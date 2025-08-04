#include "melody.h"

volatile char playMusic = 0xff;
volatile int cnt = 0;

void setup() {
  //ピンの設定
  pinMode(output_pin_A, OUTPUT);
  pinMode(output_pin_B, OUTPUT);
  pinMode(output_pin_C, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  TCCR2A = 127;
  TCCR2B = (TCCR2B & 0b11111000 ) | DIV_1;
  TIMSK2 = 0b1;
  OCR2A = 0;
  
  attachInterrupt(1,select_song,FALLING);
  attachInterrupt(0,start_sing,FALLING);
}

void loop() {
  switch(playMusic){
    case 0x01:
      music1();
      cnt = 0;
      playMusic = 0xff;
      break;
    case 0x02:
      music2();
      cnt = 0;
      playMusic = 0xff;
      break;
    case 0x03:
      music3();
      cnt = 0;
      playMusic = 0xff;
      break;
    default:
      break;
  }
}

void select_song(void){
  cnt++;
  if(cnt > 3){
    cnt = 1;
  }
}

void start_sing(void) {
  switch(cnt){
    case 0:
    case 1:
      playMusic = 0x01;
      break;
    case 2:
      playMusic = 0x02;
      break;
    case 3:
      playMusic = 0x03;
      break;
    default:
      playMusic = 0x03;
      break;
  }
}
