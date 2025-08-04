#ifndef melody_h
#define melody_h

// Arduinoの基本的な機能を利用するためのヘッダファイルをインクルードします。
#include <Arduino.h>

// タイマ設定値
#define output_pin_A 11
#define output_pin_B 12
#define output_pin_C 13
#define SPEAKER_PIN 11

// タイマ分周
#define DIV_1 1             //分周無し

// 音階表(分周なし)
#define STOP         0
#define DO_1         34
#define DO_SHARP_1   36
#define RE_1         38
#define RE_SHARP_1   41
#define MI_1         43
#define FA_1         46
#define FA_SHARP_1   48
#define SO_1         51
#define SO_SHARP_1   54
#define RA_1         58
#define RA_SHARP_1   61
#define SI_1         65
#define DO_2         69
#define DO_SHARP_2   73
#define RE_2         77
#define RE_SHARP_2   82
#define MI_2         86
#define FA_2         92
#define FA_SHARP_2   97
#define SO_2         103
#define SO_SHARP_2   109
#define RA_2         115
#define RA_SHARP_2   122
#define SI_2         129
#define DO_3         137
#define DO_SHARP_3   145
#define RE_3         154
#define RE_SHARP_3   163
#define MI_3         173
#define FA_3         183
#define FA_SHARP_3   194
#define SO_3         206
#define SO_SHARP_3   218
#define RA_3         231
#define RA_SHARP_3   244
#define SI_3         259
#define DO_4         274
#define DO_SHARP_4   291
#define RE_4         308
#define RE_SHARP_4   326
#define MI_4         346
#define FA_4         366
#define FA_SHARP_4   388
#define SO_4         411
#define SO_SHARP_4   435
#define RA_4         461
#define RA_SHARP_4   489
#define SI_4         518
#define DO_5         549
#define DO_SHARP_5   581
#define RE_5         616
#define RE_SHARP_5   652
#define MI_5         691
#define FA_5         732
#define FA_SHARP_5   776
#define SO_5         822
#define SO_SHARP_5   871
#define RA_5         923
#define RA_SHARP_5   978
#define SI_5         1036
#define DO_6         1097
#define DO_SHARP_6   1163
#define RE_6         1232
#define RE_SHARP_6   1305
#define MI_6         1383
#define FA_6         1465
#define FA_SHARP_6   1552
#define SO_6         1644
#define SO_SHARP_6   1742
#define RA_6         1845
#define RA_SHARP_6   1955
#define SI_6         2071
#define DO_7         2195
#define DO_SHARP_7   2325
#define RE_7         2463
#define RE_SHARP_7   2610
#define MI_7         2765
#define FA_7         2929
#define FA_SHARP_7   3104
#define SO_7         3288
#define SO_SHARP_7   3484
#define RA_7         3691
#define RA_SHARP_7   3910
#define SI_7         4143
#define DO_8         4389
#define LONG         9999

#define LEN(x) (sizeof(x) / sizeof((x)[0]))

// プロトタイプ宣言
void music1();
void music2();
void music3();
int MELODY_SET(const int16_t* melody, int index);
int LONG_VOWEL(const int16_t* melody, int index);

#endif