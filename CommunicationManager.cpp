#include "CommunicationManager.h"

/* ******************************************
 * Constructor
 * ******************************************/
CommunicationManager::CommunicationManager(){};
CommunicationManager::CommunicationManager(HardwareSerial* serial_esp8266, 
                                           HardwareSerial* serial_switch, 
                                           HardwareSerial* serial_monitor) {
  m_esp8266 = new ESP8266(*serial_esp8266, 115200);
  m_switch = serial_switch;
  m_monitor = serial_monitor;
  m_switch->begin(9600);
  m_monitor->begin(9600);
};

/* ******************************************
 * Start Sever Mode (softap)
 * ******************************************/
void CommunicationManager::startServer(){
  m_monitor->print("setup begin\r\n");
  
  // 서버모드
  if(m_esp8266->setOprToSoftAP()) m_monitor->print("set softap mode OK\r\n");
  else m_monitor->print("set softap mode ERR\r\n");
  if(m_esp8266->setSoftAPParam(RAD_SSID, RAD_PASSWORD, RAD_CHANNEL, RAD_ENCODING)) m_monitor->print("set ap param OK\r\n"); 
  else m_monitor->print("set ap param ERR\r\n");
  if(m_esp8266->enableMUX()) m_monitor->print("set multiple OK\r\n");
  else m_monitor->print("set multiple ERR\r\n");
  if(m_esp8266->startTCPServer(RAD_PORT)) m_monitor->print("start tcp server OK\r\n");
  else m_monitor->print("start tcp server ERR\r\n");
  
  delay(100);
  m_monitor->println("Kick : " + m_esp8266->kick());
  delay(100);
  m_monitor->println("FW Version : " + m_esp8266->getVersion());
  delay(100);
  m_monitor->println("Local IP : " + m_esp8266->getLocalIP());
  delay(100);
  m_monitor->println("IP Status : " + m_esp8266->getIPStatus());
  
  
  m_monitor->print("setup end\r\n");
};

/* ******************************************
 * Read From ESP8266
 * ******************************************/
String CommunicationManager::readESP8266(){
  uint8_t buffer[1024];
  uint32_t len = m_esp8266->recv(&m_muxid, buffer, sizeof(buffer), 1000);
  String msg;
  if (len > 0) {
    for(uint32_t i = 0; i < len; i++) {
      msg += (char)buffer[i];
    };

    // log
    if(DEBUG_SERVER){
      m_monitor->print("\r\n//======================================\r\n");
      m_monitor->print("[from ESP8266] :: \r\n");
      
//      char* c_msg = msg.c_str();
//      for(int i=0; i<len; i++){
//        Serial.print(buffer[i]);
//        Serial.print(" // ");
//        Serial.println((char)buffer[i]);
//      }
      m_monitor->print(msg);

      m_monitor->print("\r\n======================================//\r\n");
    };
  };
  return msg;
};
/* ******************************************
 * Send To ESP8266
 * ******************************************/
void CommunicationManager::sendESP8266(String msg){
  char* msg_c = msg.c_str();
  m_esp8266->send(m_muxid, msg_c, strlen(msg_c));
  
  // log
  if(DEBUG_SERVER){
    m_monitor->print("\r\n//======================================\r\n");
    m_monitor->print("[to ESP8266] :: \r\n");
    m_monitor->print(msg_c);
    m_monitor->print("\r\n======================================//\r\n");
  };
};


/* ******************************************
 * Read From Switch
 * ******************************************/
String CommunicationManager::readSwitch(){
  String msg;
  unsigned long start = millis();
  while(millis()-start < 1000){
    if(m_switch->available()){
      msg += (char) m_switch->read();
    }else{
      // log
      if(DEBUG_SWITCH){
        m_monitor->print("\r\n//======================================\r\n");
        m_monitor->print("[from switch] :: \r\n");
        m_monitor->print(msg);
        m_monitor->print("\r\n======================================//\r\n");
      }
      break;
    };
  };
  return msg;
};
/* ******************************************
 * Send To Switch
 * ******************************************/
void CommunicationManager::sendSwitch(String msg){
  m_switch->print(msg);
  
  // log
  if(DEBUG_SWITCH){
    m_monitor->print("\r\n//======================================\r\n");
    m_monitor->print("[to switch] :: \r\n");
    m_monitor->print(msg);
    m_monitor->print("\r\n======================================//\r\n");
  };
};
/* ******************************************
 * Send To Switch
 * ******************************************/
String CommunicationManager::excuteAT(String cmd){
  return m_esp8266->eAT_RAW(cmd + "\r\n");
  
  // log
  if(DEBUG_SWITCH){
    m_monitor->print("\r\n//======================================\r\n");
    m_monitor->print("[excute AT] :: \r\n");
    m_monitor->print(cmd);
    m_monitor->print("\r\n======================================//\r\n");
  };
};
