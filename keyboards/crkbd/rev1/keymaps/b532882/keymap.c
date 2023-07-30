/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
KC_TAB  , KC_Q     , KC_W    , KC_E     , KC_R     , KC_T        , KC_Y         , KC_U         , KC_I     , KC_O     , KC_P     , KC_BSPC ,
KC_LCTL , KC_A     , KC_S    , KC_D     , KC_F     , KC_G        , KC_H         , KC_J         , KC_K     , KC_L     , KC_SCLN  , KC_ENT  ,
KC_LSFT , KC_Z     , KC_X    , KC_C     , KC_V     , KC_B        , KC_N         , KC_M         , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT ,
                               KC_LGUI  , KC_LALT  , LT(1,KC_SPC), LT(2,KC_SPC) , LSFT(KC_SPC) , QK_LEADER
),

[1] = LAYOUT_split_3x6_3(
KC_LALT , KC_F1    , KC_F2   , KC_F3    , KC_F4    , KC_F5       , KC_F6        , KC_F7        , KC_F8          , KC_F9        , KC_F10 , LSFT(KC_DEL),
KC_LCTL , KC_NO    , KC_NO   , KC_LCTL  , KC_LSFT  , CW_TOGG     , KC_LEFT      , KC_DOWN      , KC_UP          , KC_RGHT      , KC_F11 , C(S(KC_ENT)),
KC_LSFT , KC_NO    , KC_NO   , KC_NO    , KC_NO    , KC_NO       , C(S(KC_LEFT)), LSFT(KC_HOME), LSFT(KC_END)   , C(S(KC_RGHT)), KC_F12 , KC_INS      ,
                               KC_TRNS  , KC_TRNS  , KC_TRNS     , _______      , LCTL(KC_INS) , LSFT(KC_INS)
),

[2] = LAYOUT_split_3x6_3(
KC_NO   , KC_1     , KC_2    , KC_3      , KC_4     , KC_5        , KC_6         , KC_7         , KC_8           , KC_9         , KC_0    , KC_BSPC  ,
KC_NO   , KC_NO    , KC_NO   , KC_GRV    , KC_EQL   , KC_LBRC     , KC_RBRC      , KC_MINS      , KC_BSLS        , KC_QUOT      , KC_NO   , KC_ENT   ,
KC_NO   , KC_NO    , KC_NO   , KC_NO     , KC_NO    , KC_NO       , KC_NO        , KC_NO        , KC_NO          , KC_NO        , KC_NO   , KC_NO    ,
                               KC_TRNS   , KC_TRNS  , _______     , KC_TRNS      , KC_TRNS      , KC_TRNS
),

/*
[2] = LAYOUT_split_3x6_3(
KC_GRV  , KC_EXLM  , KC_AT  , KC_HASH   , KC_DLR   , KC_PERC     , KC_CIRC      , KC_AMPR      , KC_ASTR        , KC_LPRN      , KC_RPRN , KC_DQUO    ,
KC_TILD , KC_NO    , KC_NO  , KC_EQL    , KC_PLUS  , KC_NO       , KC_PIPE      , KC_MINS      , KC_NO          , KC_LCBR      , KC_RCBR , KC_QUOT    ,
KC_TRNS , KC_NO    , KC_NO  , KC_NO     , KC_NO    , KC_NO       , KC_BSLS      , KC_UNDS      , KC_NO          , KC_LBRC      , KC_RBRC , KC_TRNS    ,
                              KC_TRNS   , KC_TRNS  , MO(3)       , KC_TRNS      , KC_TRNS      , KC_TRNS
),
*/

/*Game layout*/
[3] = LAYOUT_split_3x6_3(
KC_TAB  , KC_Q , KC_W  , KC_E    , KC_R    , KC_T    , KC_Y      , KC_U        , KC_I     , KC_O   , KC_P     , KC_BSPC ,
KC_LSFT , KC_A , KC_S  , KC_D    , KC_F    , KC_G    , KC_H      , KC_J        , KC_K     , KC_L   , KC_SCLN  , KC_ENT  ,
KC_LCTL , KC_Z , KC_X  , KC_C    , KC_V    , KC_B    , KC_N      , KC_M        , KC_COMM  , KC_DOT , KC_SLSH  , KC_RSFT ,
                         KC_TRNS , KC_TRNS , KC_SPC  , KC_SPC    , LSFT(KC_SPC), KC_ESC
),

};

#if 1

enum combs {
    ESC_KEY,
/*
    NUM_PAD,
    FUNC_PAD,
    PRN,  // ( )
    CBR,  // { }
    BRC,  // [ ]
*/
    GAME
};

const uint16_t PROGMEM esc_combo     [] = {KC_J   , KC_K   , COMBO_END}; // ESC
/*
const uint16_t PROGMEM num_combo     [] = {KC_D   , KC_F   , COMBO_END}; // NUMBER
const uint16_t PROGMEM funckey_combo [] = {KC_C   , KC_V   , COMBO_END}; // F1, F2, ...
const uint16_t PROGMEM prn_combo     [] = {KC_E   , KC_R   , COMBO_END}; // ( )
const uint16_t PROGMEM cbr_combo     [] = {KC_D   , KC_F   , COMBO_END}; // { }
const uint16_t PROGMEM brc_combo     [] = {KC_C   , KC_V   , COMBO_END}; // [ ]
*/
const uint16_t PROGMEM game_combo    [] = {KC_TAB , KC_BSPC, COMBO_END}; // game layout

combo_t key_combos[COMBO_COUNT] = {
    [ESC_KEY]  = COMBO       ( esc_combo    , KC_ESC ),
/*
    [NUM_PAD]  = COMBO       ( num_combo    , MO(3)  ),
    [FUNC_PAD] = COMBO       ( funckey_combo, MO(4)  ),
    [PRN]      = COMBO_ACTION( prn_combo      ),
    [CBR]      = COMBO_ACTION( cbr_combo      ),
    [BRC]      = COMBO_ACTION( brc_combo      ),
*/
    [GAME]     = COMBO_ACTION( game_combo     ),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
/*
        case PRN:
            if (pressed) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                tap_code16(KC_LEFT);
            }
            break;
        case CBR:
            if (pressed) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code16(KC_LEFT);
            }
            break;
        case BRC:
            if (pressed) {
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
                tap_code16(KC_LEFT);
            }
            break;
*/
        case GAME:
            if (pressed) {
                layer_invert(3);
            }
            break;
    }
}
#endif


#define TIMEOUT_MS 200  // Timeout in milliseconds.
#define RECENT_SIZE 2    // Number of keys in `recent` buffer.

static uint16_t recent[RECENT_SIZE] = {KC_NO};
static uint16_t deadline = 0;

static void clear_recent_keys(void) {
    memset(recent, 0, sizeof(recent));  // Set all zeros (KC_NO).
}

#if 0
// Handles one event. Returns true if the key was appended to `recent`.
static bool update_recent_keys(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) { return false; }
    if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
        clear_recent_keys();  // Avoid interfering with hotkeys.
        return false;
    }

    // Handle tap-hold keys.
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) { return false; }
            keycode &= 0xff;  // Get tapping keycode.
    }

    switch (keycode) {
/* jk -> esc 키맵핑 취소
        case KC_J:
        case KC_K:
            break;
*/

        case KC_LSFT:  // These keys don't type anything on their own.
        case KC_RSFT:
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
            return false;

        default:  // Avoid acting otherwise, particularly on navigation keys.
            clear_recent_keys();
            return false;
    }

    // Slide the buffer left by one element.
    memmove(recent, recent + 1, (RECENT_SIZE - 1) * sizeof(*recent));

    recent[RECENT_SIZE - 1] = keycode;
    deadline = record->event.time + TIMEOUT_MS;
    return true;
}
#endif

void matrix_scan_user(void) {
    if (recent[RECENT_SIZE - 1] && timer_expired(timer_read(), deadline)) {
        clear_recent_keys();  // Timed out; clear the buffer.
    }
}

#if 0
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) {  // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false;  // Skip default handling.
    }
    return true;  // Continue default handling.
}
#endif

/////////////////////////////////////////////////////////////////////////////////
//  shfit feature
/////////////////////////////////////////////////////////////////////////////////
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return get_generic_autoshift_timeout();
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout() * 2;
        case AUTO_SHIFT_ALPHA:
        default:
            return get_generic_autoshift_timeout();
    }
}	
#if 0
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_T:
        case KC_G:
        case KC_B:
        case KC_Y:
        case KC_H:
        case KC_N:
            return true;
        default:
            return false;
    }
}
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_T:
            register_code16((!shifted) ? KC_T : KC_LPRN);
            break;
        case KC_Y:
            register_code16((!shifted) ? KC_Y : KC_RPRN);
            break;
        case KC_G:
            register_code16((!shifted) ? KC_G : KC_LCBR);
            break;
        case KC_H:
            register_code16((!shifted) ? KC_H : KC_RCBR);
            break;
        case KC_B:
            register_code16((!shifted) ? KC_B : KC_LBRC);
            break;
        case KC_N:
            register_code16((!shifted) ? KC_N : KC_RBRC);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_T:
            unregister_code16((!shifted) ? KC_T : KC_LPRN);
            break;
        case KC_Y:
            unregister_code16((!shifted) ? KC_Y : KC_RPRN);
            break;
        case KC_G:
            unregister_code16((!shifted) ? KC_G : KC_LCBR);
            break;
        case KC_H:
            unregister_code16((!shifted) ? KC_H : KC_RCBR);
            break;
        case KC_B:
            unregister_code16((!shifted) ? KC_B : KC_LBRC);
            break;
        case KC_N:
            unregister_code16((!shifted) ? KC_N : KC_RBRC);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
/////////////////////////////////////////////////////////////////////////////////
//  end shfit feature
/////////////////////////////////////////////////////////////////////////////////
#endif


/////////////////////////////////////////////////////////////////////////////////
//  leader key
/////////////////////////////////////////////////////////////////////////////////
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
	// ()
	if (leader_sequence_one_key(KC_T)) {
        tap_code16( KC_LPRN );
        tap_code16( KC_RPRN );
        tap_code16( KC_LEFT );
    }
	// {}
	else if (leader_sequence_one_key(KC_G)) {
        tap_code16( KC_LCBR );
        tap_code16( KC_RCBR );
        tap_code16( KC_LEFT );
    }
	// []
	else if (leader_sequence_one_key(KC_B)) {
        tap_code16( KC_LBRC );
        tap_code16( KC_RBRC );
        tap_code16( KC_LEFT );
    }
	// {
	// _ -> cursor
	// }
	else if (leader_sequence_one_key(KC_H)) {
        tap_code16( KC_LCBR );
        tap_code16( KC_RCBR );
        tap_code16( KC_LEFT );
        tap_code16( KC_ENT );
        tap_code16( KC_ENT );
        tap_code16( KC_UP );
    }
	// Intellij 함수생성
    else if (leader_sequence_two_keys(KC_N, KC_F)) {
        tap_code16( A(S(KC_ENT)) );
    }
	// Intellij 함수단위테스트 실행 
    else if (leader_sequence_two_keys(KC_F, KC_T)) {
        tap_code16( C(S(KC_F10)) );
    }
	// Intellij Debugging BreakPoint
    else if (leader_sequence_one_key(KC_B)) {
        tap_code16( C(KC_F8) );
    }
	// Intellij Run Build
    else if (leader_sequence_two_keys(KC_R,KC_B)) {
        tap_code16( C(KC_F9) );
    }
	// Intellij Run 
    else if (leader_sequence_one_key(KC_E)) {
        tap_code16( S(KC_F10) );
    }
	// Intellij Run Debugging 
    else if (leader_sequence_one_key(KC_D)) {
        tap_code16( S(KC_F9) );
    }
	// 스텝
    else if (leader_sequence_one_key(KC_I)) {
        tap_code16( KC_F8 );
    }
	// into
    else if (leader_sequence_one_key(KC_U)) {
        tap_code16( KC_F7 );
    }
	// 만날때까지
    else if (leader_sequence_one_key(KC_O)) {
        tap_code16( KC_F9 );
    }
	// 디버깅 중단
    else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16( C(KC_F2) );
    }
    else if (leader_sequence_two_keys(KC_L,KC_F)) {
        SEND_STRING("LOG(FATAL,);");
        tap_code16( KC_LEFT );
        tap_code16( KC_LEFT );
    }
    else if (leader_sequence_two_keys(KC_L,KC_W)) {
        SEND_STRING("LOG(WARN,);");
        tap_code16( KC_LEFT );
        tap_code16( KC_LEFT );
    }
    else if (leader_sequence_two_keys(KC_L,KC_D)) {
        SEND_STRING("LOG(DEBUG,);");
        tap_code16( KC_LEFT );
        tap_code16( KC_LEFT );
    }
    else if (leader_sequence_two_keys(KC_L,KC_I)) {
        SEND_STRING("LOG(INFO,);");
        tap_code16( KC_LEFT );
        tap_code16( KC_LEFT );
    }
    else if (leader_sequence_two_keys(KC_L,KC_E)) {
        SEND_STRING("LOG(ERROR,);");
        tap_code16( KC_LEFT );
        tap_code16( KC_LEFT );
    }
}
/////////////////////////////////////////////////////////////////////////////////
//  leader key end
/////////////////////////////////////////////////////////////////////////////////
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

#    define L_BASE      0
#    define L_LOWER     2
#    define L_RAISE     4
#    define L_ADJUST    8
#    define L_FUNC_KEY  16
#    define L_GAME      32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Direction"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Sign"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("0~9 pad"), false);
            break;
        case L_FUNC_KEY:
            oled_write_ln_P(PSTR("F1~F12 pad"), false);
            break;
        case L_GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
//        case L_ADJUST:
//        case L_ADJUST | L_LOWER:
//        case L_ADJUST | L_RAISE:
//        case L_ADJUST | L_LOWER | L_RAISE:
//            oled_write_ln_P(PSTR("Adjust"), false);
//            break;
    };
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    uint8_t mod_state;
    static bool delkey_registered ,ctrlbrace_registered ,ctrlt_registered;
    static bool j_registered, k_registered;

    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    /**
     * KC_BSPC 는 shift키를 누르면, KC_DEL로 작동하는 로직
     */
    switch (keycode) {
        // Store the current modifier state in the variable for later reference
        case KC_BSPC:
            mod_state = get_mods(); // Initialize a boolean variable that keeps track // of the delete key status: registered or not?
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
        //ctrl + , 누르면 ctrl + t로 대응함.
        case KC_COMM:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    register_code(KC_T);
                    ctrlt_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (ctrlt_registered) {
                    unregister_code(KC_T);
                    ctrlt_registered = false;
                    return false;
                }
            }

            //ctrl + . 누르면 ctrl + ]로 대응함.
        case KC_DOT:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    register_code(KC_RBRC);
                    ctrlbrace_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (ctrlbrace_registered) {
                    unregister_code(KC_RBRC);
                    ctrlbrace_registered = false;
                    return false;
                }
            }

            //ctrl + J 누르면 PAGE DOWN로 대응함.
        case KC_J:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_PGDN);
                    j_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (j_registered) {
                    unregister_code(KC_PGDN);
                    j_registered = false;
                    return false;
                }
            }

            //ctrl + K 누르면 PAGE UP으로 대응함.
        case KC_K:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_PGUP);
                    k_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (k_registered) {
                    unregister_code(KC_PGUP);
                    k_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
        default:
            break;
    }
    return true;
}
#endif // OLED_ENABLE
