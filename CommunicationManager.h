#ifndef __COMM_H__
#define __COMM_H__

#include "Arduino.h"
#include "ESP8266.h"

#define RAD_SSID        ("RAD")
#define RAD_PASSWORD    ("123456789")
#define RAD_CHANNEL     (10)
#define RAD_ENCODING    (3)
#define RAD_PORT        (8888)

#define DEBUG_SERVER  (false)
#define DEBUG_SWITCH  (false)

class CommunicationManager {
  
  public:
    CommunicationManager();
    CommunicationManager(HardwareSerial*, HardwareSerial*, HardwareSerial*);
    void startServer();          // 서버모드 시작
    String readESP8266();        // ESP에서 메시지 읽기
    void sendESP8266(String);    // ESP로 메시지 전송
    String readSwitch();         // 스위치 메시지 읽기
    void sendSwitch(String);     // 스위치로 메시지 전송
    
    String excuteAT(String);     // AT명령어 직접실행
    
  private:
    ESP8266* m_esp8266;
    HardwareSerial* m_monitor;
    HardwareSerial* m_switch;
    uint8_t m_muxid;
    
};
#endif