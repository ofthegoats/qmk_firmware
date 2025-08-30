// Copyright 2025 Piotr Kozicki (ofthegoats)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MOD_Z MT(MOD_LGUI, KC_Z)
#define MOD_SLSH MT(MOD_LGUI, KC_SLSH)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_D MT(MOD_LCTL, KC_D)
#define HRM_K MT(MOD_RCTL, KC_K)
#define HRM_F MT(MOD_LSFT, KC_F)
#define HRM_J MT(MOD_RSFT, KC_J)

#define NAV_TAB LT(2, KC_TAB)

#define KC_LNEG S(KC_GRV)
#define KC_NUTILD S(KC_NUHS)
#define KC_NUPIPE S(KC_NUBS)

const uint16_t PROGMEM fj_capsword[] = {HRM_F, HRM_J, COMBO_END};
const uint16_t PROGMEM dk_escape[] = {HRM_D, HRM_K, COMBO_END};
const uint16_t PROGMEM sl_ralt[] = {HRM_S, HRM_L, COMBO_END};

const uint16_t PROGMEM sd_lrpn[] = {HRM_S, HRM_D, COMBO_END};
const uint16_t PROGMEM kl_rrpn[] = {HRM_K, HRM_L, COMBO_END};

const uint16_t PROGMEM we_lbrc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_rbrc[] = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM xc_lsqr[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comdot_rsqr[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM df_scln[] = {HRM_D, HRM_F, COMBO_END};
const uint16_t PROGMEM kj_cln[] = {HRM_K, HRM_J, COMBO_END};

combo_t key_combos[] = {
  COMBO(fj_capsword, QK_CAPS_WORD_TOGGLE),
  COMBO(sd_lrpn, KC_LPRN), COMBO(kl_rrpn, KC_RPRN),
  COMBO(we_lbrc, KC_LCBR), COMBO(io_rbrc, KC_RCBR),
  COMBO(xc_lsqr, KC_LBRC), COMBO(comdot_rsqr, KC_RBRC),
  COMBO(df_scln, KC_SCLN), COMBO(kj_cln, KC_COLN)
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
  &delete_key_override
};

enum custom_keycodes {
  AR_TO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AR_TO:
      if (record->event.pressed) SEND_STRING("->");
      break;
  }
  return true;
}

// TODO make a second symbols layer, I could make the first one make also a numpad sort of thing?
// TODO at some point maybe I should replace home row mods with something a bit more reliable for typing fast?
// TODO the second symbol layer needs to provide brackets, some more semicolons, and I want to have some macros for common thing I might type, for example
// /*|*/ or \(\). Those are just examples and not /that/ important, since really it's the editor that should be doing that...

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    XXXXXXX , KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_EQL,
    NAV_TAB , KC_A,    HRM_S,   HRM_D,  HRM_F,   KC_G,                          KC_H,   HRM_J,   HRM_K,   HRM_L,  KC_QUOT,  KC_MINS,
    XXXXXXX , KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RALT),
                                       KC_LGUI,  MO(1),  KC_ENT,       KC_ESC, LT(1, KC_SPC), LT(2, KC_BSPC)
),

  [1] = LAYOUT_split_3x6_3(
    AR_TO,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_PLUS,
    NAV_TAB, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR,  XXXXXXX, KC_GRV , KC_UNDS,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS,KC_NUTILD, KC_LNEG,                      XXXXXXX, KC_NUPIPE, KC_LABK, KC_RABK, KC_QUES, QK_LLCK,
                                        KC_LGUI, _______, KC_ENT,      KC_ESC,  KC_NUBS,   KC_DEL
),

  [2] = LAYOUT_split_3x6_3(
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
    XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, QK_LLCK,
                                        KC_LGUI, MO(3)  , XXXXXXX,    C(KC_PGDN), C(KC_PGUP), XXXXXXX
),

  [3] = LAYOUT_split_3x6_3(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, RM_HUEU, RM_SATU, RM_VALU, RM_TOGG, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RM_HUED, RM_SATD, RM_VALD, RM_NEXT, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
)
};
// clang-format on
