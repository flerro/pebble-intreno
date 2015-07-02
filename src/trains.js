
var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};


var refreshTrainInfo = function(trainId, cb) {
  var url = "http://www.viaggiatreno.it/viaggiatrenonew/resteasy/viaggiatreno/cercaNumeroTrenoTrenoAutocomplete/" + trainId;

  var success = function(responseText) {
    if (responseText) {
      var trainInfo = responseText.replace('\n','').split('|')[1].split('-');
      cb(trainInfo[0], trainInfo[1]);
      console.log('Train departure is >> ' + trainInfo);
    } else {
      console.log('Train departure is n/a');        
    }
  }; 
  
  xhrRequest(url, 'GET', success);
};

var epochToTime = function(dateTime) {
	if (!dateTime) return '-';	
	var stopDateTime = new Date(dateTime);	
	return stopDateTime.getHours() + ':' + stopDateTime.getMinutes();
};

var locateTrain = function(trainId, startId) {
  var url = 'http://www.viaggiatreno.it/viaggiatrenonew/resteasy/viaggiatreno/andamentoTreno/' + startId + '/' + trainId;
    // var url = 'http://www.viaggiatreno.it/viaggiatrenonew/resteasy/viaggiatreno/andamentoTreno/S01700/9509';
	
  var success = function(responseText) {    
      var dictionary = {
		  'KEY_TRAIN_CODE': trainId,
          'KEY_TRAIN_ORIGIN': 'n/a',
          'KEY_DELAY': 'n/a'
        };
    
      try {
		  // debug - console.log('Calling ' + url);
		  
		  var json = JSON.parse(responseText);
		  var lastStop, nextStop;
		  
		  if (json.fermate) {
			  var lastIdx = json.fermate.length - 1;
			  for (var i=0; i < lastIdx; i++) {
				  lastStop = json.fermate[i];
				  nextStop = json.fermate[i + 1];

				  if (!nextStop.effettiva) {
					  lastStop = json.fermate[i];
					  break;
				  }				
			  }
			  
			  if (json.fermate[lastIdx].effettiva) {
				  lastStop = json.fermate[lastIdx];
				  nextStop = "";
			  }
		  }
		  	
		  
		   // TODO -- bulletproof
		   // get train status >> delayed, at last stop, split stop info and name,  
			dictionary = {
			  	'KEY_TRAIN_CODE': json.compNumeroTreno,
				'KEY_TRAIN_ORIGIN': json.origine,
			  	'KEY_DELAY': json.compRitardo[0],
			  	'KEY_UPDATED': json.compOraUltimoRilevamento,
				'KEY_LAST_STOP': lastStop.stazione, 
				'KEY_LAST_STOP_DT': epochToTime(lastStop.effettiva),
				'KEY_LAST_STOP_PF': lastStop.binarioEffettivoPartenzaDescrizione  || '',	 
				'KEY_NEXT_STOP': nextStop.stazione, 
				'KEY_NEXT_STOP_DT': epochToTime(nextStop.programmata), 
				'KEY_NEXT_STOP_PF': nextStop.binarioProgrammatoArrivoDescrizione  || ''
			};
        
			// debug - console.log('after dictionary ' + JSON.stringify(dictionary))
          
      } catch(error) {
        console.log(error.toString());
      }
    
      Pebble.sendAppMessage(dictionary,
         function(e) { console.log('Info sent to Pebble successfully!'); },
         function(e) { console.log('Error sending info to Pebble! ' + e.message); }
      ); 
  };
  
  xhrRequest(url, 'GET', success);
};

var currentIndex = 0;
var configuration = [{ departure: 'MILANO', code: "9505", departureCode: "S01700" }, 
							 { departure: 'FIRENZE SNM', code: "2307", departureCode: "S06421" }];

Pebble.addEventListener('ready',
  function(e) {
    console.log('JavaScript app ready and running!');              
	var currentTrain = configuration[currentIndex];
    locateTrain(currentTrain.code, currentTrain.departureCode);
  }
);

Pebble.addEventListener('appmessage',
  function(e) {
    console.log("AppMessage received!");
	
	currentIndex++;
	if (currentIndex >= configuration.length) currentIndex = 0;
	  
	var currentTrain = configuration[currentIndex];
    locateTrain(currentTrain.code, currentTrain.departureCode);  
    //refreshTrainInfo("9509", locateTrain);
  }                     
);

Pebble.addEventListener('showConfiguration', function(e) {
  // Show config page
  Pebble.openURL('https://dl.dropboxusercontent.com/u/282511/intreno-settings.html');
});

Pebble.addEventListener('webviewclosed',
  function(e) {
    var configuration = JSON.parse(decodeURIComponent(e.response));
    console.log('Configuration window returned: ', JSON.stringify(configuration));
  }
);
