#include <MemoryFree.h>
#include <FreeRTOS_AVR.h>
#include "CommunicationManager.h"


/* ******************************************
 * Global
 * ******************************************/
HardwareSerial* serial_monitor = &Serial;  // RXTX0
HardwareSerial* serial_esp8266 = &Serial2;  // RXTX2
//CommunicationManager comm;
//DisplayManager display;
unsigned int count = 0;


/* ******************************************
 * Task
 * ******************************************/
SemaphoreHandle_t semphr;
void task1(void* arg) {
  while(1){
    serial_monitor->print("freeMemory = ");
    serial_monitor->println(freeMemory());
    vTaskDelay(1000);
  }
}
void task2(void* arg) {
  while(1){
    serial_monitor->print("count = ");
    serial_monitor->println(count);
    vTaskDelay(1000);
  }
}
void task3(void* arg) {
  while(1){
    count++;
    vTaskDelay(3000);
  }
}


/* ******************************************
 * Entry Point
 * ******************************************/
void setup(void) {

  // 0) 초기화
  // 장치 기초 정보 
  // 기본 통신상태 
  serial_monitor->begin(9600);
  serial_esp8266->begin(115200);
  
  
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
  xTaskCreate( task1, "check free memory", 100, NULL, 1,  NULL );
  xTaskCreate( task2, "print current count", 100, NULL, 1, NULL );
  xTaskCreate( task3, "increase count", 100, NULL, 1, NULL );
  
  // 시작
  vTaskStartScheduler();
  
  serial_monitor->println( F("[!!!] Insufficient RAM..!") );
  while(1){};
}

void loop(void) {}
