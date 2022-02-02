#include QMK_KEYBOARD_H
#include "keymap_finnish.h"

#define _BASE   0
#define _SHIFT  1
#define _LOWER  2
#define _LOWER2 3
#define _RAISE  4
#define _GUI    5

#define OSX_PIPE LOPT(FI_7)
#define OSX_BSLS S(LOPT(FI_7))
#define OSX_LBRC S(LOPT(FI_8))
#define OSX_RBRC S(LOPT(FI_9))

#define MCTL_TAB  LCTL_T(KC_TAB)
#define MGUI 	  LM(_GUI, MOD_LGUI)
#define SHIFT_SPC LT(_SHIFT, KC_SPC)
#define LOWER_ESC LT(_LOWER, KC_ESC)
#define RAISE_ENT LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |   å  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ö  |   ä  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   -  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |      |      |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        _______,  FI_Q,   FI_W,    FI_E,    FI_R,    FI_T,                   FI_Y,    FI_U,    FI_I,    FI_O,    FI_P,    FI_ARNG,
	_______,  FI_A,   FI_S,    FI_D,    FI_F,    FI_G,                   FI_H,    FI_J,    FI_K,    FI_L,    FI_ODIA, FI_ADIA,
        _______,  FI_Z,   FI_X,    FI_C,    FI_V,    FI_B,                   FI_N,    FI_M,    FI_COMM, FI_DOT,  FI_MINS, _______,
                          KC_VOLD, KC_VOLU,                                                    KC_MPRV, KC_MNXT,
                                            LOWER_ESC, MCTL_TAB, 	     RAISE_ENT, SHIFT_SPC,
                                            KC_MPLY,   MGUI,         	     KC_BSPC,   KC_DEL,
                                            _______,   _______,              _______,   _______
    ),

    [_SHIFT] = LAYOUT(
	_______, S(FI_Q), S(FI_W),  S(FI_E),  S(FI_R), S(FI_T),			S(FI_Y), S(FI_U), S(FI_I), S(FI_O),  S(FI_P),    S(FI_ARNG),
	_______, S(FI_A), S(FI_S),  S(FI_D),  S(FI_F), S(FI_G),			S(FI_H), S(FI_J), S(FI_K), S(FI_L),  S(FI_ODIA), S(FI_ADIA),
	_______, S(FI_Z), S(FI_X),  S(FI_C),  S(FI_V), S(FI_B),			S(FI_N), S(FI_M), _______, _______,  _______,    _______,
	                  _______,  _______, 							  _______, _______,
	                                      MO(_LOWER2), S(KC_ENT), 	        _______, _______,
	                                      _______,   _______,      	        _______, _______,
	                                      _______,   _______,               _______, _______
    ),

    [_LOWER] = LAYOUT(
        _______,  _______, FI_QUOT, _______, FI_EURO, FI_PERC,               OSX_PIPE, OSX_LBRC, OSX_RBRC, FI_PLUS, _______, _______,
        _______,  FI_EXLM, FI_DQUO, FI_HASH, FI_DLR,  FI_AMPR,               FI_SLSH,  FI_LPRN,  FI_RPRN,  FI_EQL,  FI_ASTR, _______,
        _______,  FI_TILD, FI_AT,   _______, _______, _______,               OSX_BSLS, FI_QUES,  FI_SCLN,  FI_COLN, FI_UNDS, _______,
                           _______, _______,                                                      _______,  _______,
                                             _______, _______,               KC_BSPC, MO(_LOWER2),
                                             _______, _______,               _______, _______,
                                             RESET,   _______,               _______, _______
    ),

    [_LOWER2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,               _______, FI_LABK, FI_RABK, _______, _______, _______,
        _______, _______, FI_GRV,  _______, FI_CIRC, _______,               _______, FI_LBRC, FI_RBRC, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                   _______, _______,
                                            _______, _______,               _______, _______,
                                            _______, _______,               _______, _______,
                                            _______, _______,               _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, FI_7,    FI_8,    FI_9,    _______,               _______, KC_HOME, KC_END,  _______,  _______, _______,
        _______, FI_0,    FI_4,    FI_5,    FI_6,    _______,               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, FI_1,    FI_2,    FI_3,    _______,               _______, _______, _______, _______,  _______, _______,
                          _______, _______,                                                   _______, _______,
                                            KC_BSPC, _______,               _______, _______,
                                            _______, _______,               _______, _______,
                                            _______, _______,               _______, RESET
    ),

    [_GUI] = LAYOUT(
        _______, _______, _______, _______, _______, _______,               _______, _______, _______,   _______, _______, _______,
        _______, _______, FI_GRV,  _______, _______, _______,               _______, KC_TAB,  S(KC_TAB), _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               _______, _______, _______,   _______, _______, _______,
                          _______, _______,                                                   _______,   _______,
                                            _______, _______,               C(FI_Q), _______,
                                            _______, _______,               S(FI_4), _______,
                                            _______, _______,               _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Layer template
//
// [TEMPLATE] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
//                       _______, _______,                                                   _______,  _______,
//                                         _______, _______,               _______, _______,
//                                         _______, _______,               _______, _______,
//                                         _______, _______,               _______, _______
// )
