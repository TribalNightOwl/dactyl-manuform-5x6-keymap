#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"
#include "tapdances.h"

#define _QWERTY 0
#define _NUMB 1
#define _MOVE 2
#define _GAME 3

#define MOVE MO(_MOVE)
#define NUMB MO(_NUMB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1    , KC_2       , KC_3                        , KC_4         , KC_5  ,                         KC_6          , KC_7        , KC_8                        , KC_9                        , KC_0                      , KC_PSCR ,
        KC_INS , KC_Q    , ALT_T(KC_W), CTL_T(KC_E)                 , LSFT_T(KC_R) , KC_T  ,                         KC_Y          , RSFT_T(KC_U), RCTL_T(KC_I)                , LALT_T(KC_O)                , KC_P                      , _______,
        KC_DELT, KC_A    , ALT_T(KC_S), LCMD_T(KC_D)                , LSFT_T(KC_F) , KC_G  ,                         KC_H          , RSFT_T(KC_J), RCMD_T(KC_K)                , LALT_T(KC_L)                , TD(CT_MINUS_UNDSCR_EQUAL) , KC_GRAVE,
        _______, KC_Z    , KC_X       , KC_C                        , KC_V         , LT(MOVE,KC_B) ,                 LT(MOVE,KC_N) , KC_M        , TD(CT_COMM_SCLN)            , TD(CT_DOT_CLN)              , TD(CT_SLSH_PIPE_BSLSH)    , _______,
                           TD(CT_TMUX), TD(CT_LPRN_LBRC_LCBR_LTHAN) ,                                                                              TD(CT_RPRN_RBRC_RCBR_GTHAN) , TD(CT_SQTE_DQTE_BQTE_CARET) ,
                                                      TT(MOVE), KC_BSPC ,                                           KC_SPC  , OSM(MOD_RSFT) ,
                                                      NUMB    , KC_TAB  ,                                           KC_ENT  , TD(CT_TMUX) ,
                                                      KC_DOWN , KC_UP   ,                                           KC_LEFT , KC_RIGHT
    ),

    [_NUMB] = LAYOUT_5x6(
        KC_ESC  , _______ , _______      , _______      , _______        , TO(_QWERTY) ,                    _______ , _______          , _______      , _______      , _______ , KC_F12                    ,
        _______ , KC_F1   , KC_F1        , KC_F3        , KC_F4          , KC_F5       ,                    KC_F6   , KC_F7            , KC_F8        , KC_F9        , KC_F10  , KC_F11                    ,
        _______ , KC_1    , LALT_T(KC_2) , LCTL_T(KC_3) , LSFT_T(KC_4)   , KC_5        ,                    KC_6    , RSFT_T(KC_7)     , RCTL_T(KC_8) , LALT_T(KC_9) , KC_0    , TD(CT_MINUS_UNDSCR_EQUAL) ,
        _______ , _______ , _______      , _______      , _______        , _______     ,                    _______ , _______          , _______      , _______      , _______ , _______                   ,
                            _______      , _______ ,                                                                                     _______      , _______      ,
                                                          _______ , _______ ,                               _______ , _______ ,
                                                          _______ , _______ ,                               _______ , _______ ,
                                                          _______ , _______ ,                               _______ , _______

    ),

    [_MOVE] = LAYOUT_5x6(
          _______ , _______ , _______ , _______ , _______ , TO(_QWERTY),                             _______  , _______ , _______ , _______ , _______ , _______ ,
          _______ , KC_NO   , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U    ,                             KC_PGUP  , KC_HOME , KC_UP   , KC_END  , KC_NO   , _______ ,
          KC_BTN2 , KC_BTN1 , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D    ,                             KC_PGDN  , KC_LEFT , KC_DOWN , KC_RIGHT, KC_NO   , _______ ,
          _______ , _______ , _______ , _______ , KC_NO   , _______    ,                             _______  , KC_BTN1 , KC_BTN3 , KC_BTN2 , _______ , _______ ,
                              _______ , _______ ,                                                               _______ , _______,
                                                  _______ , _______  ,                               _______ , _______ ,
                                                  _______ , _______  ,                               _______ , _______ ,
                                                  KC_LEFT , KC_RIGHT ,                               KC_UP   , KC_DOWN

    )
};
