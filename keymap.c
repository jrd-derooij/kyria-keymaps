#include QMK_KEYBOARD_H

enum layers {
	_BASE = 0,
    _COLEMAK_DH,
	_SYMBOLS,
	_NAVIGATION,
	_NUMBERS,
	_FUNCTION,
    _RGB,
    _GAMING,
    _STENO
};

#include "custom_keycodes.c"
#include "g/keymap_combo.h"
#include "keymap_steno.h"

void eeconfig_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
    // SHORT TERMS

    // LONG TERMS
        case SPCNAV_NUMB:
            return COMBO_TERM + 50;
    }
    return COMBO_TERM;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: QWERTY
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * | TAB    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | CTL/ESC|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LSFT   |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
    * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
    *                        | CTRL | ALT  | GUI  | Space| LEAD |  | Bspc | Symb | FUNC | MEH  | NMBRS|  
    *                        |      |      |      | MEH  |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
	[_BASE] = LAYOUT(
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, 
	 	CTL_ESC, KC_A, LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                             KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, 
	 	        KC_LCTL, KC_LALT, KC_LGUI, SPC_NAV, KC_LEAD,                 KC_BSPC, SYMB, FUNC, KC_MEH, NUMBTO
	),           
    /*
    * Base Layer: COLEMAK
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * | TAB    |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   :  |  | \   |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | CTL/ESC|   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LSFT   |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   K  |   M  | ,  < | . >  | /  ? |  - _   |
    * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
    *                        | CTRL | ALT  | GUI  | Space| NAV  |  | Bspc | Symb | CTRL | ALT  | NMBRS|  
    *                        |      |      |      | MEH  |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_G ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSLS,
     CTL_ESC , KC_A ,  LALT_T(KC_R),  LCTL_T(KC_S),   LSFT_T(KC_T) ,   KC_D ,                     KC_H,   RSFT_T(KC_N),  RCTL_T(KC_E),   LALT_T(KC_I),  KC_O , KC_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX,XXXXXXX,     XXXXXXX  , XXXXXXX, KC_K,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_MINS,
	 	        KC_LCTL, KC_LALT, KC_LGUI, SPC_NAV, KC_LEAD,       KC_BSPC, SYMB, FUNC, KC_MEH, NUMBTO
    ),
	[_SYMBOLS] = LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 									 	  			      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______, 
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,								 	  			      KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_ENT, _______, 
		_______, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL,  _______, _______, 		        _______, _______, KC_UNDSC,KC_LCBR, KC_RCBR, KC_RCBR, _______, _______, 
						           COLEMAK, TO(_STENO), _______, _______, _______, 	        _______, _______, _______, _______, TO(_RGB)
	),
    [_NAVIGATION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                              KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                                              KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, KC_INS,
      _______, _______, _______, _______, _______, KC_SLCK, _______, _______,           _______, _______,KC_PAUSE, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______,           _______, _______, _______, _______, GAMING
    ),
     /* Lower Layer: Numpad, Media
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |      |      | VolUp|      |      |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |        |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | +      |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |      |      | VolDn| Mute |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  |        |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
	[_NUMBERS] = LAYOUT(
		_______, _______, _______, KC_UP, 	_______, _______, 														KC_DOT, 		KC_7, 		KC_8, 		KC_9, 		KC_MINS, 	KC_ASTR, 
		_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, 														KC_COMM, 		KC_4, 		KC_5, 		KC_6, 		KC_ENT, 	KC_PLUS, 
		_______, _______, _______, _______, _______, _______, _______, _______, 			_______, 	_______, 	KC_EQL, 			KC_1, 		KC_2, 		KC_3, 		KC_SLSH, 	_______,
								   _______, _______, _______, BASE, _______, 			_______,    KC_0, 	_______, 	KC_DOT, 	TO(_NAVIGATION)
	),
	[_FUNCTION] = LAYOUT(
		_______, _______, _______, _______, _______, _______, 														    _______, KC_F9, KC_F10, KC_F11, KC_F12,  _______, 
		_______, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,														    _______, KC_F5, KC_F6,	KC_F7,  KC_F8,   _______,  
		_______, _______, _______, _______, _______, _______, _______, _______, 				      _______, _______, _______, KC_F1, KC_F2, 	KC_F3,  KC_F4,   _______, 
						   		   _______, _______, _______, BASE, _______, 				      _______, _______, _______, _______, BASE
	),
	[_RGB] = LAYOUT(
		_______, _______, _______, 	DF(_BASE), 		_______, _______, 													_______, _______, _______, _______, _______, 	_______, 
		_______, _______, _______, 	DF(_SYMBOLS), 	_______, _______, 													RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, 	_______, 
		_______, _______, _______, 	DF(_NAVIGATION), _______, _______, _______, _______, 		  	_______, _______, 	_______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, 	_______, 
									_______, 		_______, _______, _______, _______, 			_______, _______, 	_______, _______, BASE
	),
    [_GAMING] = LAYOUT(
		_______, _______, KC_Q, KC_W, KC_E, KC_R, 													_______, _______, _______, _______, _______, 	_______, 
		_______, _______, KC_A, KC_S, KC_D, KC_F, 													_______, _______, _______, _______, _______, 	_______, 
		_______, _______, KC_Z, KC_X, KC_C, KC_V, _______, _______, 		  	_______, _______, 	_______, _______, _______, _______, _______, 	_______, 
									_______, _______, _______, _______, _______, 			_______, _______, 	_______, _______, BASE
    ),
    // // ---- STENO ---- {{{
    [_STENO] = LAYOUT(
    _______, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                            STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  ,
    _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                                           STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, _______,     _______,       _______, _______, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                _______, _______,     STN_A,   STN_A,   STN_O, STN_N1,  STN_E,   STN_U,   _______, BASE
    )
// ---- END STENO ---- }}}

};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             record->event.key.row,
             record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
    #endif
    switch (keycode) {
    //...
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_T) {
        // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
        SEND_STRING(SS_LCTRL(SS_LSFT("t")));
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    SEQ_THREE_KEYS(KC_M, KC_V, KC_G) {
        SEND_STRING("Met vriendelijke groet,\nJordy de Rooij");
    }
    }
}


#ifdef OLED_ENABLE 
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR(" Jordy\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("Base\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _SYMBOLS:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _NAVIGATION:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _NUMBERS:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Functions\n"), false);
                break;
            case _GAMING:
                oled_write_P(PSTR("GAMING\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}

#endif