#ifndef DIsplayManger_h
#define DIsplayManger_h
#include <Arduino.h>



class DIsplayManger
{
  private:
    int mLineNumber;
    int pageNum = 1;
    int mainPoint = 20;
    int subpoint = 1;
    String strSettinginfo[4] = { "SEVER_IP : ", "User ID : ", "User_NUM", "RAD_Num : " };
    String subIndex[6] = {"SEVER MODE", "CLIENT MODE", "3G/4G MODE", "Change Rauderate", "GET RAD NUM", "RAD Rebooting"};
    //////////////////////////////////////String cutting
    static const int linesize = 21;
    static const int numberOflines = 20;
    char consolLineArray[numberOflines][linesize] = {" ",};
    short endline = 0;
    int showline = 0;
    boolean circleCheck = 0;
    short lineupnum = 0;
    ///////////////////////////////
    typedef struct {
      String infoSsid;
      String infoId;
      String infoPw;
      String infoMac;
    } struct_infoData;
    typedef struct {
      String serverIp;
      String userId;
      String userNum;
      String radNum;
    } struct_SettinginfoData;
    typedef struct {
      boolean wifi;
      boolean charge;
      boolean user;
      boolean device;
      boolean server;
      unsigned short int gauge;
    } struct_notiData;

    struct_infoData infoData = {"", "", "", ""};
    struct_SettinginfoData settinginfoData = {"", "", "", ""};
    struct_notiData notiData = {true, false, true, true, true, 100};

    // 기능 : 화면초기화
    //
    // @Param : 없음
    // @Return :
    void clearPage();

    // 기능 : 인자값을 받아서 상단 알림창 Draw 및 전체 화면이동 해주는 함수
    //
    // @Param :
    // @Return :
    void drawNotifacation();
    // 기능 : Main page Draw
    //
    // @Param  : 없음
    void drawMainpage();
    // 기능 : Info page Draw
    //
    // @Param  : 없음
    // @Return :
    void drawInfopage();
    // 기능 : Setting_Info page Draw
    //
    // @Param  : 없음
    // @Return :
    void drawSettinginfopage();
    // 기능 : User Info page Draw
    //
    // @Param  : 없음
    // @Return :
    void drawsUserinfopage();
    // 기능 : Sub page1Draw
    //
    // @Param  : 없음
    // @Return :
    void drawSubMenupage_1();
    // 기능 : Sub page2 Draw
    //
    // @Param  : 없음
    // @Return :
    void drawSubMenupage_2();
    // 기능 : Baudrat page Draw
    //
    // @Param  : 없음
    // @Return :
    void drawBaudratepage();
    // 기능 : 인자값을 받아서 콘솔화면   Draw
    //
    // @Param : 없음
    void drawConsolepage();

  public:
    DIsplayManger();
    // 기능 : subpoint 리턴
    //
    // @Param : x
    // @Return :subpoint 넘버
    int getSubpoint();
    // 기능 : subpoint 설정
    //
    // @Param : subpoint 넘버
    // @Return :
    void setSubpoint(int);
    // 기능 : mainpoint 리턴
    //
    // @Param : x
    // @Return :mainpoint 넘버
    int getMainpoint();
    // 기능 : mainpoint  설정
    //
    // @Param : mainpoint
    // @Return :
    void setMainpoint(int);
    // 기능 : 페이지 넘버 리턴
    //
    // @Param : x
    // @Return :페이지 넘버
    int getPagenum();
    // 기능 : 페이지 넘버  설정
    //
    // @Param : 페이지 넘버
    // @Return :
    void setPagenum(int);
    // 기능 : Circlecheck 리턴
    //
    // @Param : x
    // @Return :Circlecheck
    int getCirclecheck();
    // 기능 : Showline 설정
    //
    // @Param : int Showline
    // @Return :x
    void setShowline(int);
    // 기능 : Showline 리턴
    //
    // @Param : x
    // @Return :Showline
    int getShowline();
    // 기능 : Endine 리턴
    //
    // @Param : x
    // @Return :Endine
    int getEndline();
    // 기능 : lineupnum 리턴
    //
    // @Param : x
    // @Return :lineupnum
    int getLineupnum();
    // 기능 : lineupnum 설정
    //
    // @Param : lineupnum (int)
    // @Return :x
    void setLineupnum(int);
    // 기능 : NumberOflines 리턴
    //
    // @Param : x
    // @Return :NumberOflines
    int getNumberOflines();
    // 기능 :로고 띄우는화면
    //
    // @Param : 없음
    // @Return :
    void logoPage();
    // 기능 : 페이지넘버를 가지고  화면선택에 따라  다른화면으로 보내주는 역활
    //
    // @Param : 없음
    // @Return :
    void checkPage();
    // 기능 : 알림창 정보 설정
    //
    // @Param : 와이파이 유/무
    // @Return :
    void setWifi(bool);
    // 기능 : 알림창 정보 설정
    //
    // @Param : 베터리 유/무
    // @Return :
    void setCharing(bool);
    // 기능 : 알림창 정보 설정
    //
    // @Param : 베터리잔량
    // @Return :
    void setBatterygauge(int);
    // 기능 : 알림창 정보 설정
    //
    // @Param : User on/off
    // @Return :
    void setUser(bool);
    // 기능 : 알림창 정보 설정
    //
    // @Param : Sever on/off
    // @Return :
    void setServer(bool);
    // 기능 : 알림창 정보 설정
    //
    // @Param : device on/off
    // @Return :
    void setDevice(bool);
    // 기능 : Setting Info page의 Serverip 변경
    //
    // @Param : String
    // @Return :
    void setServerip(String );
    // 기능 : Setting Info page의 Userid변경
    //
    // @Param : String
    // @Return :
    void setUserid(String);
    // 기능 : Setting Info page의 Usernum 변경
    //
    // @Param : String
    // @Return :
    void setUsernum(String );
    // 기능 : Setting Info page의 Radnum 변경
    //
    // @Param : String
    // @Return :
    void setRadnum(String );
    // 기능 : Setting page의 내용 변경
    //
    // @Param : String,String,String,String
    // @Return :
    void setSettinginfo( String, String, String, String);
    // 기능 : info page의 Ssid 변경
    //
    // @Param : String
    // @Return :
    void setInfossid(String );
    // 기능 : info page의 Id 변경
    //
    // @Param : String
    // @Return :
    void setInfoId(String);
    // 기능 : info page의 pw 변경
    //
    // @Param : String
    // @Return :
    void setInfopw(String );
    // 기능 : info page의 mac 변경
    //
    // @Param : String
    // @Return :
    void setInfomac(String );
    // 기능 : save Consol Message 2 char array
    //
    // @Param :콘솔창정보
    // @Return :
    void setConsolMSG(String);
};
#endif

