#include "melody.h"

volatile int operator_A = 0;
volatile int operator_B = 0;
volatile int operator_C = 0;
volatile int operator_D = 0;

volatile int operator_A_add = 0;
volatile int operator_B_add = 0;
volatile int operator_C_add = 0;
volatile int operator_D_add = 0;

void music1()
{
  int i = 0;
  int num;

  /* メロディー */
  int intro_A_add[] = {MI_4,MI_4,MI_4,RE_4,RE_4,RE_4,
                       DO_4,RE_4,MI_4,FA_4,MI_4,RE_4,
                       MI_4,FA_4,SO_4,RA_4,DO_5,RA_4,
                       SO_4,FA_4,MI_4,RE_4,RE_4,RE_4,
                       MI_4,MI_4,MI_4,MI_4,DO_4,MI_4,
                       RE_4};

  int intro_D_add[] = {DO_4,DO_4,DO_4,SO_3,SO_3,SO_3,
                       MI_3,SO_3,DO_4,RE_4,DO_4,SO_3,
                       DO_4,RE_4,MI_4,FA_4,RA_4,FA_4,
                       MI_4,RE_4,DO_4,SO_3,SO_3,SO_3,
                       DO_4,DO_4,DO_4,DO_4,MI_4,DO_4,
                       SO_3};

  int intro_time[] = {450,150,300,300,300,300,
                      300,300,300,300,300,300,
                      300,300,300,300,300,300,
                      300,300,300,450,150,300,
                      450,150,300,300,300,300,
                      1500};

  int A1_A_add[] ={SO_4,SO_4};
  int A1_C_add[] ={FA_4,FA_4};

  int A1_time[] = {450,300};

  int A2_A_add[] = {DO_5,RE_5,MI_5,FA_5,SO_5,DO_6,LONG,SI_5,RA_5,
                    RA_5,SO_5,STOP,FA_SHARP_5,FA_SHARP_5,RA_5,SO_5,MI_5,LONG,MI_4,MI_4};
  int A2_C_add[] = {MI_4,SO_4,DO_5,DO_5,DO_5,LONG,DO_5,LONG,LONG,
                    FA_5,MI_5,STOP,RE_SHARP_5,RE_SHARP_5,RA_5,MI_5,DO_5,LONG,STOP,STOP};
  int A2_D_add[] = {DO_3,SI_2,RA_SHARP_2,RA_2,MI_2,LONG,FA_2,LONG,LONG,
                    DO_3,SO_2,DO_2,LONG,DO_3,LONG,DO_2,MI_2,SO_2,DO_3};

  int A2_time[] = {600,600,600,600,600,600,450,450,300,
                   900,300,300,300,300,300,600,600,450,450,300};

  int A3_A_add[] = {MI_4,MI_4,FA_SHARP_4,SO_SHARP_4,RA_4,LONG,STOP,RA_4,SI_4,DO_5,
                    RE_5,LONG,STOP,RA_4,RA_4,DO_5,DO_5,SI_4,RA_4,SO_4};
  int A3_C_add[] = {SO_SHARP_3,SO_SHARP_3,RA_3,SI_3,DO_4,LONG,STOP,DO_4,RE_4,MI_4,
                    RA_4,LONG,STOP,FA_SHARP_4,FA_SHARP_4,RA_4,RA_4,RA_4,SO_4,FA_4,FA_4};
  int A3_D_add[] = {MI_2,LONG,MI_2,LONG,RA_2,MI_3,DO_3,LONG,RA_2,LONG,
                    FA_SHARP_2,RA_2,RE_3,LONG,RE_2,LONG,SO_2,LONG,SO_2,SI_2};

  int A3_time[] = {600,600,600,600,600,600,300,300,300,300,
                   600,600,300,300,300,300,600,600,600,600};

  int A4_A_add[] = {MI_5,LONG,MI_5,FA_5,MI_5,RE_5,DO_5,LONG,RA_4,DO_5,
                    RE_5,LONG,RE_5,MI_5,RE_5,DO_5,DO_5,LONG,SI_4,SO_4};
  int A4_C_add[] = {SO_SHARP_4,LONG,SO_SHARP_4,SO_SHARP_4,SO_SHARP_4,SO_SHARP_4,RA_4,LONG,MI_4,MI_4,
                    RA_4,LONG,RA_4,FA_SHARP_4,FA_SHARP_4,FA_SHARP_4,FA_4,LONG,RE_4,FA_4};
  int A4_D_add[] = {MI_2,SO_SHARP_2,SI_2,LONG,MI_2,LONG,RA_2,SI_2,DO_3,RA_2,
                    FA_SHARP_2,RA_2,RE_3,LONG,RE_2,LONG,SO_2,SO_2,RE_3,FA_3};

  int A4_time[] = {600,600,300,300,300,300,600,600,600,600,
                   600,600,300,300,300,300,600,600,600,600};

  int A5_A_add[] = {SO_5,LONG,SO_5,MI_5,FA_5,SO_5,RA_5,LONG,STOP,RA_4,SI_4,DO_5,
                    FA_5,LONG,MI_5,LONG,LONG,DO_5,LONG,STOP,STOP,STOP};
  int A5_C_add[] = {DO_SHARP_5,LONG,DO_SHARP_5,DO_SHARP_5,RE_5,MI_5,FA_5,LONG,STOP,FA_4,SO_4,RA_4,
                    RA_4,LONG,RA_4,SO_4,FA_4,MI_4,LONG,STOP,STOP,STOP};
  int A5_D_add[] = {MI_3,DO_SHARP_3,RA_2,LONG,RA_2,LONG,RE_2,MI_2,FA_2,LONG,RE_2,LONG,
                    RE_3,SO_2,FA_3,SO_2,LONG,DO_3,SO_2,DO_2,STOP,STOP};

  int A5_time[] = {600,600,300,300,300,300,600,600,300,300,300,300,
                   600,600,600,300,300,600,600,600,300,300};

  analogWrite(SPEAKER_PIN,127);

  /* 演奏パート */
  num = sizeof(intro_A_add) / sizeof(intro_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = intro_A_add[i];
    operator_B_add = operator_A_add << 1;
    operator_D_add = intro_D_add[i];
    delay(intro_time[i]*0.45);
    operator_A_add = 0;
    operator_B_add = 0;
    operator_D_add = 0;
    delay(5);
  }

  //Aメロ
  num = sizeof(A1_A_add) / sizeof(A1_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = A1_A_add[i];
    operator_B_add = operator_A_add << 1;
    operator_C_add = A1_C_add[i];
    delay(A1_time[i]*0.45);
    operator_A_add = 0;
    operator_B_add = 0;
    operator_C_add = 0;
    delay(5);
  }

  num = sizeof(A2_A_add) / sizeof(A2_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A2_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A2_C_add,i);
    operator_D_add = MELODY_SET(A2_D_add,i);
    delay(A2_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A2_A_add,i);
    operator_B_add = LONG_VOWEL(A2_A_add,i);
    operator_C_add = LONG_VOWEL(A2_C_add,i);
    operator_D_add = LONG_VOWEL(A2_D_add,i);
  }

  num = sizeof(A3_A_add) / sizeof(A3_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A3_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A3_C_add,i);
    operator_D_add = MELODY_SET(A3_D_add,i);
    delay(A3_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A3_A_add,i);
    operator_B_add = LONG_VOWEL(A3_A_add,i);
    operator_C_add = LONG_VOWEL(A3_C_add,i);
    operator_D_add = LONG_VOWEL(A3_D_add,i);
  }

  num = sizeof(A4_A_add) / sizeof(A4_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A4_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A4_C_add,i);
    operator_D_add = MELODY_SET(A4_D_add,i);
    delay(A4_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A4_A_add,i);
    operator_B_add = LONG_VOWEL(A4_A_add,i);
    operator_C_add = LONG_VOWEL(A4_C_add,i);
    operator_D_add = LONG_VOWEL(A4_D_add,i);
  }

  num = sizeof(A5_A_add) / sizeof(A5_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A5_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A5_C_add,i);
    operator_D_add = MELODY_SET(A5_D_add,i);
    delay(A5_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A5_A_add,i);
    operator_B_add = LONG_VOWEL(A5_A_add,i);
    operator_C_add = LONG_VOWEL(A5_C_add,i);
    operator_D_add = LONG_VOWEL(A5_D_add,i);
  }
}

void music2()
{
  int i = 0;
  int num;

  /* メロディー */
  int A2_A_add[] = {DO_5,RE_5,MI_5,FA_5,SO_5,DO_6,LONG,SI_5,RA_5,
                    RA_5,SO_5,STOP,FA_SHARP_5,FA_SHARP_5,RA_5,SO_5,MI_5,LONG,MI_4,MI_4};
  int A2_C_add[] = {MI_4,SO_4,DO_5,DO_5,DO_5,LONG,DO_5,LONG,LONG,
                    FA_5,MI_5,STOP,RE_SHARP_5,RE_SHARP_5,RA_5,MI_5,DO_5,LONG,STOP,STOP};
  int A2_D_add[] = {DO_3,SI_2,RA_SHARP_2,RA_2,MI_2,LONG,FA_2,LONG,LONG,
                    DO_3,SO_2,DO_2,LONG,DO_3,LONG,DO_2,MI_2,SO_2,DO_3};

  int A2_time[] = {600,600,600,600,600,600,450,450,300,
                   900,300,300,300,300,300,600,600,450,450,300};

  analogWrite(SPEAKER_PIN,127);

  /* 演奏パート */
  num = sizeof(A2_A_add) / sizeof(A2_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A2_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A2_C_add,i);
    operator_D_add = MELODY_SET(A2_D_add,i);
    delay(A2_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A2_A_add,i);
    operator_B_add = LONG_VOWEL(A2_A_add,i);
    operator_C_add = LONG_VOWEL(A2_C_add,i);
    operator_D_add = LONG_VOWEL(A2_D_add,i);
  }
  cli();
  operator_A_add = 0;
  operator_B_add = 0;
  operator_C_add = 0;
  operator_D_add = 0;
  sei();
}

void music3()
{
  int i = 0;
  int num;

  /* メロディー */
  int A5_A_add[] = {SO_5,LONG,SO_5,MI_5,FA_5,SO_5,RA_5,LONG,STOP,RA_4,SI_4,DO_5,
                    FA_5,LONG,MI_5,LONG,LONG,DO_5,LONG,STOP,STOP,STOP};
  int A5_C_add[] = {DO_SHARP_5,LONG,DO_SHARP_5,DO_SHARP_5,RE_5,MI_5,FA_5,LONG,STOP,FA_4,SO_4,RA_4,
                    RA_4,LONG,RA_4,SO_4,FA_4,MI_4,LONG,STOP,STOP,STOP};
  int A5_D_add[] = {MI_3,DO_SHARP_3,RA_2,LONG,RA_2,LONG,RE_2,MI_2,FA_2,LONG,RE_2,LONG,
                    RE_3,SO_2,FA_3,SO_2,LONG,DO_3,SO_2,DO_2,STOP,STOP};

  int A5_time[] = {600,600,300,300,300,300,600,600,300,300,300,300,
                   600,600,600,300,300,600,600,600,300,300};

  analogWrite(SPEAKER_PIN,127);

  /* 演奏パート */
  num = sizeof(A5_A_add) / sizeof(A5_A_add[0]);
  sei();
  for (i = 0; i < num; i++) {
    operator_A_add = MELODY_SET(A5_A_add,i);
    operator_B_add = operator_A_add << 1;
    operator_C_add = MELODY_SET(A5_C_add,i);
    operator_D_add = MELODY_SET(A5_D_add,i);
    delay(A5_time[i]*0.45);

    operator_A_add = LONG_VOWEL(A5_A_add,i);
    operator_B_add = LONG_VOWEL(A5_A_add,i);
    operator_C_add = LONG_VOWEL(A5_C_add,i);
    operator_D_add = LONG_VOWEL(A5_D_add,i);
  }
  cli();
  operator_A_add = 0;
  operator_B_add = 0;
  operator_C_add = 0;
  operator_D_add = 0;
  sei();
}

ISR(TIMER2_OVF_vect) {
  //割り込み時に実行される関数
  char data = 0;
  digitalWrite(output_pin_C, !digitalRead(output_pin_C));

  int output_data = 0;

  operator_A += operator_A_add;
  operator_A &= 0x7FFF;
  operator_B += operator_B_add;
  operator_B &= 0x7FFF;
  operator_C += operator_C_add;
  operator_C &= 0x7FFF;
  operator_D += operator_D_add;
  operator_D &= 0x7FFF;


  if (operator_A < 0x3FFF) {//矩形波　50%
    output_data += -31;
  } else {
    output_data += 31;
  }

  //  if (operator_B < 0x3FFF) {//矩形波　50%
  //    output_data += -31;
  //  } else {
  //    output_data += 31;
  //  }

  if (operator_B < 0x3FFF) {//三角波
    output_data += operator_B >> 9;
  } else {
    output_data += -31 + (63 - (operator_B >> 9));
  }

  if (operator_C < 0x1FFF) {//矩形波　25%
    output_data += -31;
  } else {
    output_data += 31;
  }

  output_data += -31 + operator_D >> 9;//のこぎり波

  //  if (operator_D < 0x3FFF) {//矩形波　50%
  //    output_data += -31;
  //  } else {
  //    output_data += 31;
  //  }

  if (output_data > 0) {
    output_data >>= 1;//output_data/=2;と同じ
  } else {
    output_data = -((-output_data) >> 1);
  }

  OCR2A = output_data + 127;

  digitalWrite(output_pin_C, !digitalRead(output_pin_C));
}

/* メロディー設定関数 */
int MELODY_SET(int *melody, int arr){
  int n = 0;          /* ループ */
  int cnt = 0;        /* 連続数カウント */
  int operator_add;   /* 音階周波数 */

  if(*(melody + arr) == LONG){
    /* LONGが何回続いているかカウントする */
    for(n = arr; n > 0; n--){
      if(*(melody + n) == LONG){
        cnt++;
      }
      else{
        break;    /* 連続が終了した段階で終了 */
      }
    }
    operator_add = *(melody + (arr - cnt));
  }
  else{
    operator_add = *(melody + arr);
  }

  return operator_add;
}

/* 長音判定関数 */
int LONG_VOWEL(int *melody, int arr){
  int breath;
  
  /* 長音でないなら音を区切る */
  if(*(melody + (arr+1)) != LONG){
    breath = 0;
    delay(1);
  }
  else{
    breath = MELODY_SET(melody, arr);
    delay(1);
  }

  return breath;
}