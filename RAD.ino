#include <FreeRTOS_AVR.h>
#include <basic_io_avr.h>
#include "OLEDManger.h"
#include "CommunicationManager.h"

/* ******************************************
 * Macro
 * ******************************************/
#define BUTTON_A (2)
#define BUTTON_B (3)
#define BUTTON_C (4)
#define BUTTON_D (5)
#define BUTTON_DELAY (500)

/* ******************************************
 * Global
 * ******************************************/
HardwareSerial* serial_monitor = &Serial;  // RXTX0
HardwareSerial* serial_esp8266 = &Serial2;  // RXTX2
//CommunicationManager comm;
//DisplayManager display;
unsigned long count = 0;
 OLEDManger *LEDManger;


/* ******************************************
 * Task
 * ******************************************/
SemaphoreHandle_t semphr;
TaskHandle_t th_print, th_increase;
TaskHandle_t th_display, th_display_renew, th_webserver;
void task_print(void* arg) {
  for(;;){
    xSemaphoreTake(semphr, portMAX_DELAY);
    serial_monitor->print("current count = ");
    serial_monitor->println(count);
    xSemaphoreGive(semphr);
  }
}
void task_print2(void* arg) {
  serial_monitor->println("task_print2 start");
  vTaskDelay(1000);
  for(;;){
    serial_monitor->println("x100");
    vTaskSuspend(NULL);
  }
}
void task_increase(void* arg) {
  serial_monitor->println("task_increase start");
  vTaskDelay(1000);
  for(;;){
    xSemaphoreTake(semphr, portMAX_DELAY);
    ++count;
    if(count == 10000) {
      serial_monitor->println("x100");
      vTaskResume(th_print);
      xSemaphoreGive(semphr);
      count = 0;
    }
  }
}

// 버튼리스너
void t_button_listener(){
  for(;;){
    if(digitalRead(BUTTON_A) == LOW){
      xSemaphoreTake(semphr, portMAX_DELAY); //세마포어 대기
      serial_monitor->println("BUTTON A");
      xSemaphoreGive(semphr);     //세마포어 해제
      vTaskResume(th_display);    // *디스플레이 테스크 재개*
      vTaskDelay(BUTTON_DELAY); //버튼구분동작 딜레이
      
    }
    else if(digitalRead(BUTTON_B) == LOW){
      serial_monitor->println("BUTTON B");
      vTaskDelay(BUTTON_DELAY);
      
    }
    else if(digitalRead(BUTTON_C) == LOW){
      xSemaphoreTake(semphr, portMAX_DELAY);
      serial_monitor->println("BUTTON C");
      xSemaphoreGive(semphr);
      
      vTaskResume(th_webserver);   // *웹서버 테스크 재개*
      vTaskDelay(BUTTON_DELAY);
      
    }
    else if(digitalRead(BUTTON_D) == LOW) {
      xSemaphoreTake(semphr, portMAX_DELAY);
      serial_monitor->println("BUTTON D");
      xSemaphoreGive(semphr);
      
      vTaskSuspend(th_webserver);   // *웹서버 테스크 정지*
      vTaskDelay(BUTTON_DELAY);
      
    }
  }
}

// 화면출력
void t_display(){
  for(;;){
    xSemaphoreTake(semphr, portMAX_DELAY);
    serial_monitor->println("display drawing!!");
    xSemaphoreGive(semphr);
    vTaskSuspend(NULL);  //1회
  }
}
// 화면갱신
void t_display_renew(){
  serial_monitor->println("webserver running!!");
}
// 웹서버
void t_webserver(){
  for(;;){
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
 * Entry Point
 * ******************************************/
void setup(void) {

  // 0) 초기화
   LEDManger = new OLEDManger();
   LEDManger->logoPage();
   LEDManger->logoPage();
   delay(1000);
  LEDManger->checkPage();
  LEDManger->checkPage();
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
  xTaskCreate(t_display, "t_display", 100, NULL, 1, &th_display);
  xTaskCreate(t_display_renew, "t_display_renew", 100, NULL, 1, &th_display_renew);
  xTaskCreate(t_webserver, "t_webserver", 100, NULL, 1, &th_webserver);

  // 시작
  vTaskSuspend(th_display);
  vTaskSuspend(th_display_renew);
  vTaskSuspend(th_webserver);
  vTaskStartScheduler();
  
  serial_monitor->println( F("[log] TaskScheduler is crushed..!") );
  while(1){};
}

void loop(void) {}
