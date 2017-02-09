#include <FreeRTOS_AVR.h>
#include <basic_io_avr.h>
#include "DIsplayManger.h"
#include "CommunicationManager.h"
#include <U8glib.h>
U8GLIB_SSD1306_128X64 u81g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
/* ******************************************
   Macro
 * ******************************************/
#define BUTTON_A (2)
#define BUTTON_B (3)
#define BUTTON_C (4)
#define BUTTON_D (5)
#define BUTTON_DELAY (500)



/* ******************************************
   Global
 * ******************************************/
HardwareSerial* serial_monitor = &Serial;  // RXTX0
HardwareSerial* serial_esp8266 = &Serial2;  // RXTX2
//CommunicationManager comm;
//DisplayManager display;
unsigned long count = 0;
DIsplayManger *DisplayManger;



/* ******************************************
   Task
 * ******************************************/
SemaphoreHandle_t semphr;
TaskHandle_t th_print, th_increase;
TaskHandle_t th_display, th_display_renew, th_webserver;
void task_print(void* arg) {
  for (;;) {
    xSemaphoreTake(semphr, portMAX_DELAY);
    serial_monitor->print("current count = ");
    serial_monitor->println(count);
    xSemaphoreGive(semphr);
  }
}
void task_print2(void* arg) {
  serial_monitor->println("task_print2 start");
  vTaskDelay(1000);
  for (;;) {
    serial_monitor->println("x100");
    vTaskSuspend(NULL);
  }
}
void task_increase(void* arg) {
  serial_monitor->println("task_increase start");
  vTaskDelay(1000);
  for (;;) {
    xSemaphoreTake(semphr, portMAX_DELAY);
    ++count;
    if (count == 10000) {
      serial_monitor->println("x100");
      vTaskResume(th_print);
      xSemaphoreGive(semphr);
      count = 0;
    }
  }
}

// 버튼리스너
void t_button_listener() {
  for (;;) {
    if (digitalRead(BUTTON_A) == LOW) {
      xSemaphoreTake(semphr, portMAX_DELAY); //세마포어 대기
      serial_monitor->println("BUTTON A");
      downbtn();
      xSemaphoreGive(semphr);     //세마포어 해제
      vTaskResume(th_display);    // *디스플레이 테스크 재개*
      vTaskDelay(BUTTON_DELAY); //버튼구분동작 딜레이

    }
    else if (digitalRead(BUTTON_B) == LOW) {
      xSemaphoreTake(semphr, portMAX_DELAY); //세마포어 대기
      serial_monitor->println("BUTTON B");
      upbtn();
      xSemaphoreGive(semphr);     //세마포어 해제
      vTaskResume(th_display);    // *디스플레이 테스크 재개*
      vTaskDelay(BUTTON_DELAY); //버튼구분동작 딜레이

    }
    else if (digitalRead(BUTTON_C) == LOW) {
      xSemaphoreTake(semphr, portMAX_DELAY);
      serial_monitor->println("BUTTON C");
      clickbtn();
      xSemaphoreGive(semphr);
      vTaskResume(th_display);    // *디스플레이 테스크 재개*
      vTaskDelay(BUTTON_DELAY);

    }
    else if (digitalRead(BUTTON_D) == LOW) {
      xSemaphoreTake(semphr, portMAX_DELAY);
      serial_monitor->println("BUTTON D");
      xSemaphoreGive(semphr);
      vTaskDelay(BUTTON_DELAY);

    }

  }
}

// 화면출력
void t_display() {
  for (;;) {
    xSemaphoreTake(semphr, portMAX_DELAY);
    serial_monitor->println("display drawing!!");

    DisplayManger->checkPage();
    DisplayManger->checkPage();

    
    xSemaphoreGive(semphr);
    vTaskSuspend(NULL);  //1회
  }
}
// 화면갱신
void t_display_renew() {
  serial_monitor->println("webserver running!!");
}
// 웹서버
void t_webserver() {
  for (;;) {
    xSemaphoreTake(semphr, portMAX_DELAY); //세마포어 대기
    serial_monitor->println("webserver running!!");
    xSemaphoreGive(semphr);
    vTaskDelay(100);
  }
}
////로깅
//extern "C"{
//  void vApplicationIdleHook(void){
//    ulIdleCycleCount++;
//  }
//}


/* ******************************************
   Entry Point
 * ******************************************/
void setup(void) {

  // 0) 초기화
  //인트로 화면 추가.
  DisplayManger = new DIsplayManger();
  DisplayManger->logoPage();
  DisplayManger->logoPage();
  delay(1000);
  DisplayManger->checkPage();
  DisplayManger->checkPage();
  // 장치 기초 정보
  // 기본 통신상태
  serial_monitor->begin(9600);
  serial_esp8266->begin(115200);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(BUTTON_D, INPUT);

  // 1) UI 쓰레드 (우선순위:1)
  // 버튼입력 감지
  // 버튼입력에 따른 화면 그리기
  // 화면구성에 필요한 데이터 가져오기
  // ※ 리부팅 선택시, 리부팅함수 직접실행
  // ※ 통신속도변경 선택시, 통신속더변경함수 직접실행
  // ※ 승인요청 선택시, 승인요청함수 직접실행 + 승인번호보여주기


  // 2) 통신 쓰레드 (우선순위:1)
  // 콘솔화면에서만 동작? 백그라운드 동작?
  // 송수신 병렬처리? 순차처리?
  // 버퍼초과하면..?


  // 3) 웹서버 쓰레드
  // 서버모드화면에서만 동작
  // 서버모드 선택시,


  // 4) 로깅 쓰레드
  // ...


  // 등록
  semphr = xSemaphoreCreateMutex();
  xTaskCreate(t_button_listener, "t_button_listener", 100, NULL, 1, NULL);
  xTaskCreate(t_display, "t_display", 300, NULL, 1, &th_display);
  xTaskCreate(t_display_renew, "t_display_renew", 100, NULL, 1, &th_display_renew);
  xTaskCreate(t_webserver, "t_webserver", 100, NULL, 1, &th_webserver);

  // 시작
  vTaskSuspend(th_display);
  vTaskSuspend(th_display_renew);
  vTaskSuspend(th_webserver);
  vTaskStartScheduler();

  serial_monitor->println( F("[log] TaskScheduler is crushed..!") );
  while (1) {};
}

void loop(void) {}

/* ******************************************
   Button actions
 * ******************************************/
void upbtn() {
  switch (DisplayManger->getPagenum()) {
    case 1:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() + 10);
      delay(300);
      if (DisplayManger->getMainpoint() > 40) {
        DisplayManger->setMainpoint(20);
      }
      break;
    case 2:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() + 10);
      delay(300);
      if (DisplayManger->getMainpoint() > 40) {
        DisplayManger->setMainpoint(20);
        if (DisplayManger->getSubpoint() < 3) {
          DisplayManger->setSubpoint(DisplayManger->getSubpoint() + 1);
        }
        else {
          DisplayManger->setSubpoint(1);
        }
      }
      break;
    case 3:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() + 10);
      delay(300);
      if (DisplayManger->getMainpoint() > 40) {
        DisplayManger->setMainpoint(20);
      }
      break;
    case 4:
      if (DisplayManger->getCirclecheck() == 1 && DisplayManger->getShowline() == 0) {
        DisplayManger->setShowline(DisplayManger->getNumberOflines() - 1);
        DisplayManger->setLineupnum(DisplayManger->getLineupnum() + 1);
      }
      else if ((DisplayManger->getCirclecheck()  == 0) && ( DisplayManger->getShowline() < 5)) {
      }
      else if ((DisplayManger->getCirclecheck() == 1) && ( (DisplayManger->getShowline() ) == (DisplayManger->getEndline() + 4))) {
      }
      else {
        DisplayManger->setShowline(DisplayManger->getShowline() - 1);
        DisplayManger->setLineupnum(DisplayManger->getLineupnum() + 1);
      }
      DisplayManger->checkPage();
      DisplayManger->checkPage();
      delay(300);
      break;
    case 5:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() + 10);
      delay(300);
      if (DisplayManger->getMainpoint() > 30) {
        DisplayManger->setMainpoint(20);
      }
      break;
  }
}
void downbtn() {
  switch (DisplayManger->getPagenum()) {
    case 1:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() - 10);
      delay(300);
      if (DisplayManger->getMainpoint() < 20) {
        DisplayManger->setMainpoint(40);
      }
      break;
    case 2:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() - 10);
      delay(300);
      if (DisplayManger->getMainpoint() < 20) {
        DisplayManger->setMainpoint(40);
        if (DisplayManger->getSubpoint() > 1) {
          DisplayManger->setSubpoint(DisplayManger->getSubpoint() - 1);
        }
        else {
          DisplayManger->setSubpoint(3);
        }
      }
      break;
    case 3:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() - 10);
      delay(300);
      if (DisplayManger->getMainpoint() < 20) {
        DisplayManger->setMainpoint(40);
      }
      break;
    case 4:
      if ( DisplayManger->getLineupnum() > 0) {
        DisplayManger->setShowline((DisplayManger->getShowline()) + 1);
        DisplayManger->setLineupnum(DisplayManger->getLineupnum() - 1);

        if (DisplayManger->getShowline() == DisplayManger->getNumberOflines()) {
          DisplayManger->setShowline(0);
        }
      }
      DisplayManger->checkPage();
      DisplayManger->checkPage();
      delay(300);
      break;
    case 5:
      DisplayManger->setMainpoint(DisplayManger->getMainpoint() - 10);
      delay(300);
      if (DisplayManger->getMainpoint() < 20) {
        DisplayManger->setMainpoint(30);
      }
      break;
  }
}
void clickbtn(){
      switch (DisplayManger->getPagenum()) {
      case 1:
        switch (DisplayManger->getMainpoint()) {
          case 20:
            DisplayManger->setPagenum(2);
            DisplayManger->setSubpoint(1);

            break;
          case 30:
            DisplayManger->setPagenum(5);

            break;
          case 40:
            DisplayManger->setPagenum(4);

            break;
        }
        break;
      case 2:
        switch (DisplayManger->getMainpoint()) {
          case 20:
            DisplayManger->setPagenum(1);
            break;
          case 30:
            if (DisplayManger->getSubpoint() == 1) { //서버모드
              DisplayManger->setPagenum(1);
            }
            else if (DisplayManger->getSubpoint() == 2) { //3g/4g
              DisplayManger->setPagenum(1);
            }
            else if (DisplayManger->getSubpoint() == 3) { //rad승인요청
              DisplayManger->setPagenum(7);
            }
            break;
          case 40:
            if (DisplayManger->getSubpoint() == 1) { //클라이언트 모드
              DisplayManger->setPagenum(1);
            }
            else if (DisplayManger->getSubpoint() == 2) { //rad 통신 속도 변경
              DisplayManger->setPagenum(3);
            }
            else if (DisplayManger->getSubpoint() == 3) { //rad rebooting
              DisplayManger->setPagenum(1);
            }
            break;
        }
        break;
      case 3:
        switch (DisplayManger->getMainpoint()) {
          case 20:
            //통신속도 9600k
            DisplayManger->setPagenum(1);
            break;
          case 30:
            //통신속도 38400k
            DisplayManger->setPagenum(1);
            break;
          case 40:
            //통신속도 152000k
            DisplayManger->setPagenum(1);
            break;
        }
        break;
      case 4:
             DisplayManger->setPagenum(1);
        break;
      case 5:
        switch (DisplayManger->getMainpoint()) {
          case 20:
            DisplayManger->setPagenum(6);
            break;
          case 30:
            DisplayManger->setPagenum(7);
            break;
        }
        break;
      case 6:
           DisplayManger->setPagenum(1);
        break;
      case 7:
           DisplayManger->setPagenum(1);
        break;
    }
  DisplayManger->setMainpoint(20);
}

