#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    COLONSWAP,
    FOR_I_MACRO,
    FOR_EL_MACRO,
    HGE_MACRO,
    HG_MACRO,
    DRAG_SCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        |COLEMK|         | LOWER| Enter|  Del |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         |Mouse3|Mouse1|Mouse2|    |Brght-|      |Brght+|    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 
*/
[_QWERTY] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                TO(_COLEMAK),               LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_BRID, _______,      KC_BRIU
),
// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift


/* BACKUP Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RCTL,
                KC_MUTE,                    LOWER,        KC_ENT,       KC_QUOT,      KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_BRID, _______,      KC_BRIU
),
*/

/*
 ---------------------------------------------------------------------------------------------------------
 ---------------------------------------------------------------------------------------------------------
 ---------------------------------------------------------------------------------------------------------
Colemak modified
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |:; MOD|   (  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Win  |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        |QWERTY|         | LOWER| Space| Shift|    |BckSpc| Enter| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------'          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    |Brght-|      |Brght+|    // 3 way thumb switch
 *                         `--------------------'    `--------------------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,        KC_W,          KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         COLONSWAP,    KC_LPRN,
  KC_TAB,       KC_A,        KC_R,          KC_S,         KC_T,         KC_G,         KC_M,    KC_N,         KC_E,         KC_I,         KC_O,         KC_QUOT,
  KC_LCTL,      KC_Z,        KC_X,          KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_LGUI,
                TO(_QWERTY),                MO(_LOWER),   KC_SPC,       KC_LSFT,      KC_BSPC, KC_ENT,       MO(_RAISE),                 KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_BRID, _______,      KC_BRIU
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  | Page↑|
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |AltTab|  Cut | Home |   ↑  | End  | Paste|           |   !  |   -  |   =  |   [  |   ]  | Page↓|
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | Ctrl |   ←  |   ↓  |   →  |  Win |           |   *  |   +  |   /  |   (  |   )  |  Win |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Space| Shift|    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------'          `------'
 *                         ,--------------------.    ,--------------------.
 *                         |      |      |      |    |Brght-|      |Brght+|    // 3 way thumb switch
 *                         `--------------------'    `--------------------'
 */
[_RAISE] = LAYOUT_ximi(
  _______,      KC_1,       KC_2,    KC_3,        KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGUP,
  LALT(KC_TAB), LCTL(KC_X), KC_HOME, KC_UP,       KC_END,  LCTL(KC_V),   KC_EXLM, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PGDN,
  _______,      KC_LCTL,    KC_LEFT, KC_DOWN,     KC_RGHT, KC_LGUI,      KC_ASTR, KC_PLUS, KC_SLSH, KC_LPRN, KC_RPRN, KC_LGUI,
                _______,             MO(_ADJUST), KC_SPC,  KC_LSFT,      _______, _______,  _______,          _______,
                                     _______, _______, _______,      KC_BRID, _______, KC_BRIU
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |           |MouseL|MouseR|   &  |   *  |   ^  |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |AltTab|  Esc | Copy |MouseR|MouseL|Paste |           |SCROLL|   _  |   +  |   {  |   }  | Right|
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |  Caps|  Cut | ←Tab | Tab→ |EE_CLR|           |  @?  |  ←@  |  @→  |   |  |      |      | browser search, browser back/forward
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |  Del |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------'          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------'
 */
[_LOWER] = LAYOUT_ximi(
  _______,      KC_EXLM, KC_AT,     KC_HASH,            KC_DLR,  KC_PERC,      KC_BTN1,     KC_BTN2, KC_AMPR,     KC_ASTR, KC_CIRC, _______, 
  LALT(KC_TAB), KC_ESC, LCTL(KC_C), KC_BTN2,            KC_BTN1, LCTL(KC_V),   DRAG_SCROLL, KC_UNDS, KC_PLUS,     KC_LCBR, KC_RCBR, KC_RGHT,
  _______,      KC_CAPS,LCTL(KC_X), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), EE_CLR,  KC_WSCH,     KC_WBAK, KC_WFWD,     KC_PIPE, _______, _______,
                _______,            _______,            _______, _______,      KC_DEL,      _______, MO(_ADJUST),          _______,
                                    _______,            _______, _______,      _______,     _______, _______
),

/* Adjust/Macros (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |A-SHFT|      |      |  HG  |  HGE |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5  |TSK_MN|
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |A-CRCT|      |      |FOR_EL| FOR_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 |  ⏯︎  | play/pause
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |  F11 |  F12 |      |Reset | Btldr|  ⏩︎  | next track
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------'          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------'
 */
[_ADJUST] =  LAYOUT_ximi(
  AS_TOGG,      _______, _______,  HG_MACRO,    HGE_MACRO,    TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   LCTL(LALT(KC_DEL)),
  AC_TOGG,      _______, _______,  FOR_I_MACRO, FOR_EL_MACRO, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_MPLY,
  _______,      _______, _______,  _______,     _______,      _______,           KC_F11,  KC_F12,  _______, QK_RBT,   QK_BOOT, KC_MNXT,
                _______,           _______,     _______,      _______,           _______, _______, _______,          _______,
                                   _______,     _______,      _______,           _______, _______, _______
)
};


bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 20.0
#define SCROLL_DIVISOR_V -20.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                set_scrolling = !set_scrolling;
            } 
            return false;
            break;
        // case LOWER:
        //     if (record->event.pressed) {
        //         layer_on(_LOWER);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     } else {
        //         layer_off(_LOWER);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     }
        //     return false;
        //     break;
        // case RAISE:
        //     if (record->event.pressed) {
        //         layer_on(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     } else {
        //         layer_off(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     }
        //     return false;
        //     break;
        // case ADJUST:
        //     if (record->event.pressed) {
        //         layer_on(_ADJUST);
        //     } else {
        //         layer_off(_ADJUST);
        //     }
        //     return false;
        //     break;
        case COLONSWAP:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_SCLN) SS_UP(X_LSFT));
                return false;
                break;
            }
        case FOR_EL_MACRO:
            if (record->event.pressed) {
                SEND_STRING("for element in ");
                return false;
                break;
            }
        case FOR_I_MACRO: 
            if (record->event.pressed) {
                SEND_STRING("for i in ");
                return false;
                break;
            }
        case HGE_MACRO:
            if (record->event.pressed) {
                SEND_STRING("h.remmelg@student.utwente.nl");
                return false;
                break;
            }
        case HG_MACRO:
            if (record->event.pressed) {
                SEND_STRING("hanno.remmelg@gmail.com");
                return false;
                break;
            }
        default:
            break;
    }

    return true;
}
