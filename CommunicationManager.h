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
    void startServer();          // ������� ����
    String readESP8266();        // ESP���� �޽��� �б�
    void sendESP8266(String);    // ESP�� �޽��� ����
    String readSwitch();         // ����ġ �޽��� �б�
    void sendSwitch(String);     // ����ġ�� �޽��� ����
    
    String excuteAT(String);     // AT��ɾ� ��������
    
  private:
    ESP8266* m_esp8266;
    HardwareSerial* m_monitor;
    HardwareSerial* m_switch;
    uint8_t m_muxid;
    
};
#endif