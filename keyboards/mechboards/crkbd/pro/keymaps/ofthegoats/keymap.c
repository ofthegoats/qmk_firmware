// Copyright 2025 Piotr Kozicki (ofthegoats)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_QUOT MT(MOD_LGUI, KC_QUOT)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_D MT(MOD_LCTL, KC_D)
#define HRM_K MT(MOD_RCTL, KC_K)
#define HRM_F MT(MOD_LSFT, KC_F)
#define HRM_J MT(MOD_RSFT, KC_J)

#define KC_LNEG S(KC_GRV)
#define KC_NUTD S(KC_NUHS)
#define KC_NUPP S(KC_NUBS)

#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DWN KC_KB_VOLUME_DOWN

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_ALT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
  /* &delete_key_override */
};

enum custom_keycodes {
  AR_TO = SAFE_RANGE,
  AR_FROM,
  IMPLIES
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AR_TO:
      if (record->event.pressed) SEND_STRING("->");
      break;
    case AR_FROM:
      if (record->event.pressed) SEND_STRING("<-");
      break;
    case IMPLIES:
      if (record->event.pressed) SEND_STRING("=>");
      break;
  }
  return true;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
  /* switch (tap_hold_keycode) { */
  /*   case LT(2, KC_SPC): return true; */
  /* } */
  return get_chordal_hold_default(tap_hold_record, other_record);
}

void leader_start_user(void) {}

void leader_end_user(void) {}

enum layers {
  BASE = 0,
  NUM,
  SYM,
  FUN,
  NAV
};

#define NAV_DEL LT(NAV, KC_DEL)
#define NUM_TAB LT(NUM, KC_TAB)
#define SYM_SPC LT(SYM, KC_SPC)
#define FUN_BSPC LT(FUN, KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    KC_MINS, KC_Q   , KC_W   , KC_E   ,   KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,   KC_O,    KC_P, KC_EQL ,
    KC_NUBS, HRM_A  , HRM_S  , HRM_D  ,  HRM_F,    KC_G,                       KC_H,   HRM_J,   HRM_K,  HRM_L,HRM_QUOT, KC_SCLN,
    KC_LPRN, KC_Z   , KC_X   , KC_C   ,   KC_V,    KC_B,                       KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RPRN,
                                       NAV_DEL, NUM_TAB, KC_ENT ,     KC_ESC , SYM_SPC, FUN_BSPC
),

  [NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
),

  [NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_CIRC, KC_7   , KC_8   , KC_9   , KC_EQL , XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_MINS, KC_4   , KC_5   , KC_6   , KC_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLSH, KC_1   , KC_2   , KC_3   , KC_ASTR, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,    KC_DOT , KC_0   , _______
),

  [SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_EXLM, KC_GRV , KC_PERC, KC_LBRC, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_AMPR, KC_AT  , KC_DLR , KC_LCBR, KC_RCBR,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_NUPP, KC_NUTD, KC_NUHS, KC_LPRN, KC_RPRN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______, XXXXXXX
),

  [FUN] = LAYOUT_split_3x6_3(
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
)
};
// clang-format on
