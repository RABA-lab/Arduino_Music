#include "melody.h"
#include <avr/pgmspace.h>
#include <stdint.h>

volatile int operator_A = 0;
volatile int operator_B = 0;
volatile int operator_C = 0;
volatile int operator_D = 0;

volatile int operator_A_add = 0;
volatile int operator_B_add = 0;
volatile int operator_C_add = 0;
volatile int operator_D_add = 0;

typedef struct {
  const uint16_t* melodyA;
  const uint16_t* melodyC;
  const uint16_t* melodyD;
  const uint16_t* time;
  uint8_t length;
} MelodySection;

void music1()
{
  int i,j;
  int num;

  /* メロディー */
  const int16_t intro_A[] PROGMEM = {MI_4,MI_4,MI_4,RE_4,RE_4,RE_4,DO_4,RE_4,MI_4,FA_4,MI_4,RE_4,
                                     MI_4,FA_4,SO_4,RA_4,DO_5,RA_4,SO_4,FA_4,MI_4,RE_4,RE_4,RE_4,
                                     MI_4,MI_4,MI_4,MI_4,DO_4,MI_4,RE_4};

  const int16_t intro_C[] PROGMEM = {DO_4,DO_4,DO_4,SO_3,SO_3,SO_3,MI_3,SO_3,DO_4,RE_4,DO_4,SO_3,
                                     DO_4,RE_4,MI_4,FA_4,RA_4,FA_4,MI_4,RE_4,DO_4,SO_3,SO_3,SO_3,
                                     DO_4,DO_4,DO_4,DO_4,MI_4,DO_4,SO_3};
                                  
  const int16_t intro_D[] PROGMEM = {0};                  

  const int16_t intro_time[] PROGMEM = {450,150,300,300,300,300,300,300,300,300,300,300,
                                        300,300,300,300,300,300,300,300,300,450,150,300,
                                        450,150,300,300,300,300,1500};

  const int16_t melody_A1[] PROGMEM ={SO_4,SO_4};
  const int16_t melody_C1[] PROGMEM ={FA_4,FA_4};
  const int16_t melody_D1[] PROGMEM = {0};

  const int16_t melody_time1[] PROGMEM = {450,300};

  const int16_t melody_A2[] PROGMEM = {
    DO_5,RE_5,MI_5,FA_5,SO_5,DO_6,LONG,SI_5,RA_5,RA_5,SO_5,STOP,FA_SHARP_5,FA_SHARP_5,RA_5,SO_5,MI_5,LONG,MI_4,MI_4,
    MI_4,MI_4,FA_SHARP_4,SO_SHARP_4,RA_4,LONG,STOP,RA_4,SI_4,DO_5,RE_5,LONG,STOP,RA_4,RA_4,DO_5,DO_5,SI_4,RA_4,SO_4,
    MI_5,LONG,MI_5,FA_5,MI_5,RE_5,DO_5,LONG,RA_4,DO_5,RE_5,LONG,RE_5,MI_5,RE_5,DO_5,DO_5,LONG,SI_4,SO_4,
    SO_5,LONG,SO_5,MI_5,FA_5,SO_5,RA_5,LONG,STOP,RA_4,SI_4,DO_5,FA_5,LONG,MI_5,LONG,LONG,DO_5,LONG,STOP,STOP,STOP
  };

  const int16_t melody_C2[] PROGMEM = {
    MI_4,SO_4,DO_5,DO_5,DO_5,LONG,DO_5,LONG,LONG,FA_5,MI_5,STOP,RE_SHARP_5,RE_SHARP_5,RA_5,MI_5,DO_5,LONG,STOP,STOP,
    SO_SHARP_3,SO_SHARP_3,RA_3,SI_3,DO_4,LONG,STOP,DO_4,RE_4,MI_4,RA_4,LONG,STOP,FA_SHARP_4,FA_SHARP_4,RA_4,RA_4,RA_4,SO_4,FA_4,FA_4,
    SO_SHARP_4,LONG,SO_SHARP_4,SO_SHARP_4,SO_SHARP_4,SO_SHARP_4,RA_4,LONG,MI_4,MI_4,RA_4,LONG,RA_4,FA_SHARP_4,FA_SHARP_4,FA_SHARP_4,FA_4,LONG,RE_4,FA_4,
    DO_SHARP_5,LONG,DO_SHARP_5,DO_SHARP_5,RE_5,MI_5,FA_5,LONG,STOP,FA_4,SO_4,RA_4,RA_4,LONG,RA_4,SO_4,FA_4,MI_4,LONG,STOP,STOP,STOP
  };

  const int16_t melody_D2[] PROGMEM = {
    DO_3,SI_2,RA_SHARP_2,RA_2,MI_2,LONG,FA_2,LONG,LONG,DO_3,SO_2,DO_2,LONG,DO_3,LONG,DO_2,MI_2,SO_2,DO_3,
    MI_2,LONG,MI_2,LONG,RA_2,MI_3,DO_3,LONG,RA_2,LONG,FA_SHARP_2,RA_2,RE_3,LONG,RE_2,LONG,SO_2,LONG,SO_2,SI_2,
    MI_2,SO_SHARP_2,SI_2,LONG,MI_2,LONG,RA_2,SI_2,DO_3,RA_2,FA_SHARP_2,RA_2,RE_3,LONG,RE_2,LONG,SO_2,SO_2,RE_3,FA_3,
    MI_3,DO_SHARP_3,RA_2,LONG,RA_2,LONG,RE_2,MI_2,FA_2,LONG,RE_2,LONG,RE_3,SO_2,FA_3,SO_2,LONG,DO_3,SO_2,DO_2,STOP,STOP
  };

  const uint16_t melody_time2[] PROGMEM = {
    600,600,600,600,600,600,450,450,300,900,300,300,300,300,300,600,600,450,450,300,
    600,600,600,600,600,600,300,300,300,300,600,600,300,300,300,300,600,600,600,600,
    600,600,300,300,300,300,600,600,600,600,600,600,300,300,300,300,600,600,600,600,
    600,600,300,300,300,300,600,600,300,300,300,300,600,600,600,300,300,600,600,600,300,300
  };

  const MelodySection melody_sections[] PROGMEM = {
    {pgm_read_word(intro_A), pgm_read_word(intro_C), pgm_read_word(intro_D), pgm_read_word(intro_time), LEN(intro_time)},
    {pgm_read_word(melody_A1), pgm_read_word(melody_C1), pgm_read_word(melody_D1), pgm_read_word(melody_time1), LEN(melody_time1)},
    {pgm_read_word(melody_A2), pgm_read_word(melody_C2), pgm_read_word(melody_D2), pgm_read_word(melody_time2), LEN(melody_time2)},
  };

  analogWrite(SPEAKER_PIN, 127);
  for (uint8_t i = 0; i < LEN(melody_sections); i++) {
    MelodySection section;
    memcpy_P(&section, &melody_sections[i], sizeof(MelodySection));

    const int16_t* melodyA = (const int16_t*)pgm_read_word(&section.melodyA);
    const int16_t* melodyC = (const int16_t*)pgm_read_word(&section.melodyC);
    const int16_t* melodyD = (const int16_t*)pgm_read_word(&section.melodyD);
    const uint16_t* time = (const uint16_t*)pgm_read_word(&section.time);

    for (uint8_t j = 0; j < section.length; j++) {
      operator_A_add = MELODY_SET(melodyA, j);
      operator_B_add = operator_A_add << 1;
      operator_C_add = MELODY_SET(melodyC, j);
      operator_D_add = MELODY_SET(melodyD, j);

      delay(pgm_read_word(&time[j]) * 0.45);

      operator_A_add = LONG_VOWEL(melodyA, j);
      operator_B_add = operator_A_add;
      operator_C_add = LONG_VOWEL(melodyC, j);
      operator_D_add = LONG_VOWEL(melodyD, j);
    }
  }
  cli();
  operator_A_add = 0;
  operator_B_add = 0;
  operator_C_add = 0;
  operator_D_add = 0;
  sei();
}


void music2()
{

}

void music3()
{
  
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
int MELODY_SET(const int16_t* melody, int index) {
  int n = 0, cnt = 0;
  int16_t note = pgm_read_word(&melody[index]);

  if (note == LONG) {
    for (n = index; n > 0; n--) {
      if (pgm_read_word(&melody[n]) == LONG) {
        cnt++;
      } else {
        break;
      }
    }
    return pgm_read_word(&melody[index - cnt]);
  } else {
    return note;
  }
}

/* 長音判定関数 */
int LONG_VOWEL(const int16_t* melody, int index) {
  int16_t next = pgm_read_word(&melody[index + 1]);
  if (next != LONG) {
    delay(1);
    return 0;
  } else {
    int freq = MELODY_SET(melody, index);
    delay(1);
    return freq;
  }
}