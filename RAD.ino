#include <MemoryFree.h>
#include <FreeRTOS_AVR.h>
#include "OLEDManger.h"

/* ******************************************
 * Global
 * ******************************************/
HardwareSerial* serial_monitor = &Serial;  // RxTx0
unsigned int count = 0;

OLEDManger *LEDManger;

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
  serial_monitor->begin(9600);
  
  xTaskCreate( task1, "check free memory", 100, NULL, 1,  NULL );
  xTaskCreate( task2, "print current count", 100, NULL, 1, NULL );
  xTaskCreate( task3, "increase count", 100, NULL, 1, NULL );
  
  vTaskStartScheduler();
  
  serial_monitor->println( F("[!!!] Insufficient RAM..!") );
  while(1){};
}

void loop(void) {}
