#include <pebble.h>
#include "main_window.h"

#define KEY_TRAIN_ORIGIN 0
#define KEY_DELAY 1
#define KEY_UPDATED 2
#define KEY_NEXT_STOP 3
#define KEY_NEXT_STOP_DT 6
#define KEY_NEXT_STOP_PF 7
#define KEY_LAST_STOP 4
#define KEY_LAST_STOP_DT 8
#define KEY_LAST_STOP_PF 9
#define KEY_TRAIN_CODE 5


// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_18_bold;
static GFont s_res_gothic_14;
static GFont s_res_gothic_24;
static TextLayer *txt_train_origin;
static TextLayer *txt_train_code;
static TextLayer *txt_train_delay;
static TextLayer *txt_update;
static TextLayer *s_textlayer_2;
static TextLayer *txt_last_stop;
static TextLayer *s_textlayer_4;
static TextLayer *txt_next_stop_dt;
static TextLayer *txt_next_stop;
static TextLayer *s_textlayer_1;
static TextLayer *txt_next_stop_pf;
static TextLayer *txt_last_stop_dt;
static TextLayer *txt_last_stop_pf;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 0);
  #endif
  
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_gothic_24 = fonts_get_system_font(FONT_KEY_GOTHIC_24);
  // txt_train_origin
  txt_train_origin = text_layer_create(GRect(4, 15, 137, 21));
  text_layer_set_text(txt_train_origin, "Firenze SMN");
  text_layer_set_font(txt_train_origin, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_train_origin);
  
  // txt_train_code
  txt_train_code = text_layer_create(GRect(4, 1, 136, 16));
  text_layer_set_text(txt_train_code, "1234");
  text_layer_set_font(txt_train_code, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_train_code);
  
  // txt_train_delay
  txt_train_delay = text_layer_create(GRect(2, 37, 137, 28));
  text_layer_set_text(txt_train_delay, "ritardo 12 minuti");
  text_layer_set_text_alignment(txt_train_delay, GTextAlignmentCenter);
  text_layer_set_font(txt_train_delay, s_res_gothic_24);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_train_delay);
  
  // txt_update
  txt_update = text_layer_create(GRect(111, 149, 30, 15));
  text_layer_set_text(txt_update, "12:03");
  text_layer_set_text_alignment(txt_update, GTextAlignmentRight);
  text_layer_set_font(txt_update, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_update);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(4, 77, 11, 20));
  text_layer_set_text(s_textlayer_2, "^");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // txt_last_stop
  txt_last_stop = text_layer_create(GRect(18, 65, 104, 16));
  text_layer_set_text(txt_last_stop, "Bologna C.le A/V");
  text_layer_set_font(txt_last_stop, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_last_stop);
  
  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(3, 105, 12, 20));
  text_layer_set_text(s_textlayer_4, "N");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_4);
  
  // txt_next_stop_dt
  txt_next_stop_dt = text_layer_create(GRect(16, 122, 38, 20));
  text_layer_set_text(txt_next_stop_dt, "--:--");
  text_layer_set_font(txt_next_stop_dt, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_next_stop_dt);
  
  // txt_next_stop
  txt_next_stop = text_layer_create(GRect(18, 104, 112, 18));
  text_layer_set_text(txt_next_stop, "Firenze SMN");
  text_layer_set_font(txt_next_stop, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_next_stop);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(57, 149, 55, 18));
  text_layer_set_text(s_textlayer_1, "Updated @");
  text_layer_set_font(s_textlayer_1, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // txt_next_stop_pf
  txt_next_stop_pf = text_layer_create(GRect(85, 122, 42, 20));
  text_layer_set_text(txt_next_stop_pf, "-");
  text_layer_set_text_alignment(txt_next_stop_pf, GTextAlignmentRight);
  text_layer_set_font(txt_next_stop_pf, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_next_stop_pf);
  
  // txt_last_stop_dt
  txt_last_stop_dt = text_layer_create(GRect(20, 83, 44, 20));
  text_layer_set_text(txt_last_stop_dt, "--:--");
  text_layer_set_font(txt_last_stop_dt, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_last_stop_dt);
  
  // txt_last_stop_pf
  txt_last_stop_pf = text_layer_create(GRect(99, 82, 29, 20));
  text_layer_set_text(txt_last_stop_pf, "-");
  text_layer_set_text_alignment(txt_last_stop_pf, GTextAlignmentRight);
  text_layer_set_font(txt_last_stop_pf, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)txt_last_stop_pf);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(txt_train_origin);
  text_layer_destroy(txt_train_code);
  text_layer_destroy(txt_train_delay);
  text_layer_destroy(txt_update);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(txt_last_stop);
  text_layer_destroy(s_textlayer_4);
  text_layer_destroy(txt_next_stop_dt);
  text_layer_destroy(txt_next_stop);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(txt_next_stop_pf);
  text_layer_destroy(txt_last_stop_dt);
  text_layer_destroy(txt_last_stop_pf);
}
// END AUTO-GENERATED UI CODE

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Read first item
  Tuple *t = dict_read_first(iterator);

  // For all items
  while(t != NULL) {
    
    switch(t->key) {
  		case KEY_TRAIN_CODE:   
			text_layer_set_text(txt_train_code, t->value->cstring);
			break;
		case KEY_TRAIN_ORIGIN:   
			text_layer_set_text(txt_train_origin, t->value->cstring);
			break;
		case KEY_DELAY:   
			text_layer_set_text(txt_train_delay, t->value->cstring);
			break;
		case KEY_NEXT_STOP:   
			text_layer_set_text(txt_next_stop, t->value->cstring);
			break;
		case KEY_NEXT_STOP_DT:   
			text_layer_set_text(txt_next_stop_dt, t->value->cstring);
			break;
		case KEY_NEXT_STOP_PF:   
			text_layer_set_text(txt_next_stop_pf, t->value->cstring);
			break;
		case KEY_LAST_STOP:   
			text_layer_set_text(txt_last_stop, t->value->cstring);
			break;
		case KEY_LAST_STOP_DT:   
			text_layer_set_text(txt_last_stop_dt, t->value->cstring);
			break;
		case KEY_LAST_STOP_PF:   
			text_layer_set_text(txt_last_stop_pf, t->value->cstring);
			break;
		case KEY_UPDATED:   
			text_layer_set_text(txt_update, t->value->cstring);
			break;
		default:
		  	APP_LOG(APP_LOG_LEVEL_ERROR, "Missing %d >> %s", (int)t->key, t->value->cstring);
		  	break;
    }

    // Look for next item
    t = dict_read_next(iterator);
  }
}

void select_single_click_handler(ClickRecognizerRef recognizer, void *context) {
 // ... called on single click, and every 1000ms of being held ...
 //  Window *window = (Window *)context;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Single click");
}

void select_long_click_handler(ClickRecognizerRef recognizer, void *context) {
  //... called on long click start ...
  // Window *window = (Window *)context;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Long click");
}

void next_train(ClickRecognizerRef recognizer, void *context) {
  //... called on long click start ...
  // Window *window = (Window *)context;
  app_message_outbox_send();
}

void config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, select_single_click_handler);
  window_long_click_subscribe(BUTTON_ID_SELECT, 700, select_long_click_handler, NULL);  
	
  window_single_click_subscribe(BUTTON_ID_DOWN, next_train);
  window_single_click_subscribe(BUTTON_ID_UP, next_train);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
	
  window_set_click_config_provider(s_window, (ClickConfigProvider) config_provider);
	
  // AppMessage callbacks
  app_message_register_inbox_received(inbox_received_callback);
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());	
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}
