#include "OLEDManger.h"
#include "OLED_bitmap.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

OLEDManger::OLEDManger()
{
}
void OLEDManger::logoPage() {
  u8g.firstPage();
  do {
    u8g.drawBitmapP(0, 0, 16 , 64, BITMAP_LOGO);
  } while (u8g.nextPage());
}

void OLEDManger::clearPage() {
  u8g.firstPage();
  do {
  } while (u8g.nextPage());
}

int OLEDManger::getMainpoint() {
  return mainPoint;
}
void OLEDManger::setMainpoint(int mpoint) {
  mainPoint = mpoint;
}
int OLEDManger::getPagenum() {
  return pageNum;
}
void OLEDManger::setPagenum(int npage) {
  pageNum = npage;
}
int OLEDManger::getSubpoint() {
  return subpoint;
}
void OLEDManger::setSubpoint(int spoint) {
  subpoint = spoint;
}
int OLEDManger::getCirclecheck() {
  return circleCheck;
}
void OLEDManger::setShowline(int sline) {
  showline=sline;
}
int OLEDManger::getShowline() {
  return showline;
}
int OLEDManger::getEndline() {
  return endline;
}
void OLEDManger::setLineupnum(int upnum) {
  lineupnum=upnum;
}
int OLEDManger::getLineupnum() {
  return lineupnum;
}
int OLEDManger::getNumberOflines() {
  return numberOflines;
}
void OLEDManger::checkPage() {
  if (pageNum == 4) {
    drawConsolepage();
  }
  else {
    drawNotifacation();
  }
}

void OLEDManger::drawNotifacation() {
  //u8g.setFontPosTop();
  u8g.firstPage();
  do {
    int persentValue = map(notiData.gauge, 0, 1023, 0, 100);
    //persentValue = map(val, 0, 1023, 0, 100);     0~1023범위의 val값을 0~100사이의 백분율로
    int loc = 0;
    if (notiData.wifi) {
      u8g.drawBitmapP(0, 0, 3, 13, BITMAP_wifi_2);
    }
    if (!notiData.user) {
      u8g.drawBitmapP(17, 0, 2, 14, BITMAP_User_disconnect);
    }
    else {
      u8g.drawBitmapP(17, 0, 2, 14, BITMAP_User_connect);
    }
    if (!notiData.device) {
      u8g.drawBitmapP(34, 0, 2, 14, BITMAP_Device_disconnect);
    }
    else {
      u8g.drawBitmapP(34, 0, 2, 14, BITMAP_Device_connect);
    }
    if (!notiData.server) {
      u8g.drawBitmapP(51, 0, 2, 14, BITMAP_Server_disconnect);
    }
    else {
      u8g.drawBitmapP(51, 0, 2, 14, BITMAP_Server_connect);
    }
    ///////////////////////////
    u8g.setFontPosTop();
    if (persentValue < 10) loc = 83;
    else if (persentValue >= 10 && persentValue < 100) loc = 77;
    else if (persentValue == 100) loc = 71;
    if ((notiData.charge) == true) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_ON);
    else if (persentValue >= 0 && persentValue < 6) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_0);
    else if (persentValue >= 6 && persentValue < 21) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_1);
    else if (persentValue >= 21 && persentValue < 46) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_2);
    else if (persentValue >= 46 && persentValue < 71) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_3);
    else if (persentValue >= 71 && persentValue < 95) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_4);
    else if (persentValue >= 95 && persentValue < 101) u8g.drawBitmapP(100, 0, 3, 14, BITMAP_BATT_5);
    u8g.drawBitmapP(90, 1, 1, 14, BITMAP_PERSENT);
    u8g.setFont(u8g_font_6x10);
    u8g.setPrintPos(loc, 2);
    u8g.print(persentValue);
    //u8g.setFont(u8g_font_profont11);<-원래 폰트
    if (pageNum == 1) {
      drawMainpage();
    }
    else if (pageNum == 2) {
      drawSubMenupage_1();
    }
    else if (pageNum == 3) {
      drawBaudratepage();
    }
    else if (pageNum == 5) {
      drawSubMenupage_2();
    }
    else if (pageNum == 6) {
      drawInfopage();
    }
    else if (pageNum == 7) {
      drawSettinginfopage();
    }
    else if (pageNum == 8) {
    }
  } while (u8g.nextPage());
}
void OLEDManger::setWifi(bool _wifi) {
  notiData.wifi = _wifi;
}
void OLEDManger::setCharing(bool _charge) {
  notiData.charge = _charge;
}
void OLEDManger::setUser(bool _user) {
  notiData.user = _user;
}
void OLEDManger::setServer(bool _server) {
  notiData.server = _server;
}
void OLEDManger::setDevice(bool _device) {
  notiData.device = _device;
}
void OLEDManger::setBatterygauge(int _gauge) {
  notiData.gauge = _gauge;
}


void OLEDManger::drawInfopage() {
  char *Info_char[5] = {"", "", "", "", ""};
  Info_char[0] = (char*)infoData.infoSsid.c_str();
  Info_char[1] = (char*)infoData.infoId.c_str();
  Info_char[2] = (char*)infoData.infoPw.c_str();
  Info_char[3] = (char*)infoData.infoMac.c_str();
  //Info_char[4] = (char*)strInfo[4].c_str();

  u8g.drawStr(0, 15, "IP :");
  u8g.setPrintPos(23, 15);
  u8g.print(Info_char[0]);
  u8g.drawStr(0, 26, "SSID :");
  u8g.setPrintPos(35, 26);
  u8g.print(Info_char[1]);
  u8g.drawStr(0, 37, "P/W :");
  u8g.setPrintPos(29, 37);
  u8g.print(Info_char[2]);
  u8g.drawStr(0, 48, "MAC :");
  u8g.setPrintPos(29, 48);
  u8g.print(Info_char[3]);
  //  u8g.drawStr(0, 59, "Port :");
  //  u8g.setPrintPos(35, 59);
  //  u8g.print(Info_char[4]);
}
void OLEDManger::setInfossid(String strSsid) {
  infoData.infoSsid = strSsid;
}
void OLEDManger::setInfoId(String infoId) {
  infoData.infoId = infoId;
}
void OLEDManger::setInfopw(String strPW) {
  infoData.infoPw = strPW;
}
void OLEDManger::setInfomac(String strMac) {
  infoData.infoMac = strMac;
}



void OLEDManger::drawSettinginfopage() {
  char *settinginfoData_char[5] = {"", "", "", "", ""};
  settinginfoData_char[0] = (char*)settinginfoData.serverIp .c_str();
  settinginfoData_char[1] = (char*)settinginfoData.userId.c_str();
  settinginfoData_char[2] = (char*)infoData.infoPw.c_str();
  settinginfoData_char[3] = (char*)infoData.infoMac.c_str();
  //settinginfoData_char[4] = (char*)strInfo[4].c_str();

  u8g.drawStr(0, 15, "SEVER_IP :");
  u8g.setPrintPos(23, 15);
  u8g.print(settinginfoData_char[0]);
  u8g.drawStr(0, 26, "User ID :");
  u8g.setPrintPos(35, 26);
  u8g.print(settinginfoData_char[1]);
  u8g.drawStr(0, 37, "User_NUM :");
  u8g.setPrintPos(29, 37);
  u8g.print(settinginfoData_char[2]);
  u8g.drawStr(0, 48, "RAD_Num :");
  u8g.setPrintPos(29, 48);
  u8g.print(settinginfoData_char[3]);
  //  u8g.drawStr(0, 59, "Port :");
  //  u8g.setPrintPos(35, 59);
  //  u8g.print(settinginfoData_char[4]);
}
void OLEDManger::setServerip(String S_ip) {
  settinginfoData.serverIp = S_ip;
}
void OLEDManger::setUserid(String U_id) {
  settinginfoData.userId = U_id;
}
void OLEDManger::setUsernum(String U_num) {
  settinginfoData.userNum = U_num;
}
void OLEDManger::setRadnum(String R_num) {
  settinginfoData.radNum = R_num;
}


void OLEDManger::drawMainpage() {
  u8g.drawBitmapP(12, mainPoint, 1, 7, BITMAP_tri);
  u8g.drawStr(20, 20, "Rad Use");
  u8g.drawStr(20, 30, "Rad Info");
  u8g.drawStr(20, 40, "Consol");
  u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
  u8g.drawStr(0, 56, "Main >");
}
void OLEDManger::drawSubMenupage_1() {
  u8g.drawBitmapP(12, mainPoint, 1, 7, BITMAP_tri);
  if (subpoint==1) {
    u8g.setPrintPos(20, 20);
    u8g.print("...");
    u8g.setPrintPos(20, 30);
    u8g.print(subIndex[0]);
    u8g.setPrintPos(20, 40);
    u8g.print(subIndex[1]);
    u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
    u8g.drawStr(0, 56, "Main > Use");
  }
   else if (subpoint==2) {
    u8g.setPrintPos(20, 20);
    u8g.print("...");
    u8g.setPrintPos(20, 30);
    u8g.print(subIndex[0]);
    u8g.setPrintPos(20, 40);
    u8g.print(subIndex[1]);
    u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
    u8g.drawStr(0, 56, "Main > Use");
  }
   else if (subpoint==3) {
    u8g.setPrintPos(20, 20);
    u8g.print("...");
    u8g.setPrintPos(20, 30);
    u8g.print(subIndex[2]);
    u8g.setPrintPos(20, 40);
    u8g.print(subIndex[3]);
    u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
    u8g.drawStr(0, 56, "Main > Use");

  }
}
void OLEDManger::drawSubMenupage_2() {
  u8g.drawBitmapP(12, mainPoint, 1, 7, BITMAP_tri);
  u8g.drawStr(20, 20, "NewWork Info");
  u8g.drawStr(20, 30, "Settting Info");
  u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
  u8g.drawStr(0, 56, "Main > Info");
}
void OLEDManger::drawBaudratepage() {
  u8g.drawBitmapP(12, mainPoint, 1, 7, BITMAP_tri);
  u8g.drawStr(20, 20, "9600K");
  u8g.drawStr(20, 30, "38400K");
  u8g.drawStr(20, 40, "152000K");
  u8g.drawBitmapP(0, 53, 16, 1, BITMAP_bar);
  u8g.drawStr(0, 56, "Main > Use > Baudrate");
}


void OLEDManger::drawConsolepage() {
  u8g.setFontPosTop();
  u8g.setFont(u8g_font_6x10);
  u8g.firstPage();
  u8g.drawStr(0, 0, "-------Console-------");
  do {
    if (showline < 5) {//5보다 작은경우
      if (circleCheck == 0) {
        int tempyloc = 52;
        int tempxloc = 0;
        for (int i = 0; i <= showline; i++) {
          for (int j = 0; j < linesize; j++) {
            u8g.setPrintPos(tempxloc, tempyloc);
            u8g.print(consolLineArray[i][j]);
            tempxloc += 6;
          }
          tempyloc -= 10;
          tempxloc = 0;
        }

      }
      else {
        int tempyloc = 52;
        int tempxloc = 0;
        for (int i = (numberOflines - (4 - showline)); i < (numberOflines); i++) {
          for (int j = 0; j < linesize; j++) {
            u8g.setPrintPos(tempxloc, tempyloc);
            u8g.print(consolLineArray[i][j]);
            tempxloc += 6;
          }
          tempyloc -= 10;
          tempxloc = 0;
        }
        for (int i = 0; i <= showline; i++) {
          for (int j = 0; j < linesize; j++) {
            u8g.setPrintPos(tempxloc, tempyloc);
            u8g.print(consolLineArray[i][j]);
            tempxloc += 6;
          }
          tempyloc -= 10;
          tempxloc = 0;
        }
      }
    }
    else {
      int tempyloc = 52;
      int tempxloc = 0;
      for (int i = showline - 4; i <= showline; i++) {
        for (int j = 0; j < linesize; j++) {
          u8g.setPrintPos(tempxloc, tempyloc);
          u8g.print(consolLineArray[i][j]);
          tempxloc += 6;
        }
        tempyloc -= 10;
        tempxloc = 0;
      }
    }
  } while (u8g.nextPage());
}
void OLEDManger::setConsolMSG(String valuestr) {
  lineupnum = 0;
  short startindex = 0;
  short strsize = linesize - 1;
  String str_temp = "";
  char *c_temp;

  for (int i = 0; i < valuestr.length(); i++) {
    str_temp = valuestr.charAt(i);
    c_temp = (char*)str_temp.c_str();
    for (int h = 0 ; h < linesize; h++) {
      consolLineArray[endline][h] = '\0';
    }
    if  (i + 1 == (valuestr.length() )) {
      strncpy(consolLineArray[endline], valuestr.substring(startindex, i + 1).c_str(), (i + 1 - startindex));
      showline = endline;
      if (endline == numberOflines - 1) {//circle do
        circleCheck = 1;
        endline = 0;
      }
      else {
        endline++;
      }
    }

    else if (i == (strsize))
    {
      strncpy(consolLineArray[endline], valuestr.substring(startindex, i + 1).c_str(), (i + 1 - startindex));

      strsize = i + linesize;
      startindex = i + 1;
      showline = endline;
      if (endline == numberOflines - 1) {
        circleCheck = 1;
        endline = 0;
      }
      else {
        endline++;
      }
    }
    else if (*c_temp == 10) {
      if (i + 18 == strsize) { //문자열 첫글자가 \n경우
        startindex++;
      }
      else {
        strncpy(consolLineArray[endline], valuestr.substring(startindex, i).c_str(), (i + 1 - startindex));
        startindex = i + 1;
        strsize = i + linesize;
        showline = endline;
        if (endline == numberOflines - 1) {
          circleCheck = 1;
          endline = 0;
        }
        else {
          endline++;
        }
      }
    }
  }
}


