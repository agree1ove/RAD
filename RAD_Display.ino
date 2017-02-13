#include <FreeRTOS_AVR.h>
#include <basic_io_avr.h>
#include "DIsplayManger.h"
/* ******************************************
   Macro
 * ******************************************/
#define BUTTON_A (2)
#define BUTTON_B (3)
#define BUTTON_C (5)
#define BUTTON_DELAY (250)



/* ******************************************
   Global
 * ******************************************/
DIsplayManger *DisplayManger;
boolean  isdraw = false;


void setup(void) {

  // 0) 초기화
  //인트로 화면 추가.
  DisplayManger = new DIsplayManger();
  DisplayManger->logoPage();
  DisplayManger->logoPage();
  DisplayManger->setUser(true);
  DisplayManger->setServer(true);
  DisplayManger->setDevice(true);

  delay(1000);
  DisplayManger->checkPage();
  DisplayManger->checkPage();
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);


}

void loop(void) {
  if (digitalRead(BUTTON_A) == LOW) {
    DisplayManger->buttonControl(1);
    isdraw = true;
    delay BUTTON_DELAY;
  }
  else if (digitalRead(BUTTON_B) == LOW) {
    DisplayManger->buttonControl(2);
    isdraw = true;
    delay BUTTON_DELAY;
  }
  else if (digitalRead(BUTTON_C) == LOW) {
    DisplayManger->buttonControl(3);
    isdraw = true;
    delay BUTTON_DELAY;
  }
  if (isdraw == true && ( DisplayManger->getPagenum() == 4)) {
    //콘솔화면 계속그리기
    DisplayManger->setConsolMSG ("1\n2\n3\n4\n5\n6\n7\n8\n9\n0");
    DisplayManger->checkPage();
    DisplayManger->checkPage();
    while (digitalRead(BUTTON_C) != LOW) {
      //무한안에서의 버튼 처리
      if (digitalRead(BUTTON_A) == LOW) {
        DisplayManger->buttonControl(1);
        DisplayManger->checkPage();
        DisplayManger->checkPage();
      }
      else if (digitalRead(BUTTON_B) == LOW) {
        DisplayManger->buttonControl(2);
        DisplayManger->checkPage();
        DisplayManger->checkPage();
      }
    }
    DisplayManger->buttonControl(3);
    DisplayManger->checkPage();
    DisplayManger->checkPage();
  }


  else if (isdraw == true) {
    isdraw = false;
    DisplayManger->checkPage();
    DisplayManger->checkPage();
  }
}
String getCommInfo() {
  return "ip:000, mac:0000";
}
String getCommRecvMsg() {
  return "\n 1 \n 2 \n 3 \n 4 \n 5 \n 6 \n 7";
}

