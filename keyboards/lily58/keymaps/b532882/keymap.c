#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
  KC_GRV,         KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,         KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,        KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  OSM(MOD_LSFT),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
                              KC_LGUI, KC_LCTL, MO(1), KC_ENT,          KC_SPC, MO(2), KC_RCTL, QK_LEADER
),

[_LOWER] = LAYOUT(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,         KC_F7,         KC_F8,        KC_F9,         KC_F10,  _______,
  KC_TRNS, _______, _______, _______, _______, _______,                   _______,       _______,       _______,      _______,       _______, LSFT(KC_DEL),
  KC_TRNS, _______, _______, KC_LCTL, KC_LSFT, CW_TOGG,                   KC_LEFT,       KC_DOWN,       KC_UP,        KC_RGHT,       _______, C(S(KC_ENT)),
  KC_TRNS, _______, _______, _______, _______, _______, _______, KC_BSPC, C(S(KC_LEFT)), LSFT(KC_HOME), LSFT(KC_END), C(S(KC_RGHT)), _______, _______,
                             KC_TRNS, KC_TRNS, _______, KC_ENT,  KC_SPC, _______, LCTL(KC_INS), LSFT(KC_INS)
),

[_RAISE] = LAYOUT(
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_GRV,  KC_TILD, KC_EQL,  KC_PLUS, _______,                     _______, KC_MINS, KC_PIPE, KC_UNDS, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, KC_TRNS,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  combo key
//
/////////////////////////////////////////////////////////////////////////////////
enum combs {
    ESC_KEY,
};
const uint16_t PROGMEM esc_combo     [] = {KC_J   , KC_K   , COMBO_END}; // ESC
																		 //
combo_t key_combos[COMBO_COUNT] = {
    [ESC_KEY]  = COMBO       ( esc_combo    , KC_ESC )
};


/////////////////////////////////////////////////////////////////////////////////
//
//  leader key
//
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

/////////////////////////////////////////////////////////////////////////////////
//  shfit feature
/////////////////////////////////////////////////////////////////////////////////
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return get_generic_autoshift_timeout();
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout();
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
#endif
/////////////////////////////////////////////////////////////////////////////////
//
//  end shfit feature
//
/////////////////////////////////////////////////////////////////////////////////

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	uint8_t mod_state;
	static bool delkey_registered ,ctrlbrace_registered ,ctrlt_registered;
	static bool j_registered, k_registered;

  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
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
