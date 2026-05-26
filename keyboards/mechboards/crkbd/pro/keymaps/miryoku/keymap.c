// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KC_UKTD S(KC_NUHS)
#define KC_UKAT S(KC_QUOT)
#define KC_UKHS KC_NUHS
#define KC_UKPP S(KC_NUBS)
#define KC_UKBS KC_NUBS

const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_AT);
const key_override_t *key_overrides[] = {
};

enum {TD_CW_CL};
tap_dance_action_t tap_dance_actions[] = {
  [TD_CW_CL] = ACTION_TAP_DANCE_DOUBLE(CW_TOGG, KC_CAPS)
};

enum layers {
  BASE = 0,
  MEDIA,
  NAV,
  MOUSE,
  SYM,
  NUM,
  FUN
};

#define MD_DEL LT(MEDIA, KC_DEL)
#define NV_TAB LT(NAV, KC_TAB)
#define MS_ENT LT(MOUSE, KC_ENT)
#define SM_ESC LT(SYM, KC_ESC)
#define NM_SPC LT(NUM, KC_SPC)
#define FN_BSPC LT(FUN, KC_BSPC)

#define HM_A MT(MOD_LGUI, KC_A)
#define HM_S MT(MOD_LALT, KC_S)
#define HM_D MT(MOD_LCTL, KC_D)
#define HM_F MT(MOD_LSFT, KC_F)
#define HM_J MT(MOD_LSFT, KC_J)
#define HM_K MT(MOD_LCTL, KC_K)
#define HM_L MT(MOD_LALT, KC_L)
#define HM_QUOT MT(MOD_LGUI, KC_QUOT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
    XXXXXXX, HM_A   , HM_S   , HM_D   , HM_F   , KC_G   ,                          KC_H   , HM_J   , HM_K   , HM_L   , HM_QUOT, XXXXXXX,
    XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                          KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                        MD_DEL , NV_TAB , MS_ENT ,        SM_ESC , NM_SPC , FN_BSPC
),

  [MEDIA] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          RM_TOGG, RM_HUEU, RM_SATU, RM_SATD, RM_NEXT, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                          XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX,        KC_MSTP, KC_MPLY, KC_MUTE
),

  [NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                          CW_TOGG, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_INS , KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,        KC_ESC , KC_SPC , KC_BSPC
),

  [MOUSE] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                          XXXXXXX, MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
                                        XXXXXXX, XXXXXXX, _______,        MS_BTN2, MS_BTN1, MS_BTN3
),

  [SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,                          XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
    XXXXXXX, KC_UKTD, KC_EXLM, KC_AT  , KC_UKHS, KC_UKPP,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_LPRN, KC_RPRN, KC_UNDS,        _______, XXXXXXX, XXXXXXX
),

  [NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                          XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
    XXXXXXX, KC_1   , KC_1   , KC_2   , KC_3   , KC_UKBS,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_DOT , KC_0   , KC_MINS,        XXXXXXX, _______, XXXXXXX
),

  [FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_SYRQ,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,                          XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
    XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_DEL , KC_TAB , KC_ENT ,        XXXXXXX, XXXXXXX, _______
),
};

// clang-format on
