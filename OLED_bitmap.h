//% 이미지
const uint8_t BITMAP_PERSENT[] PROGMEM = {
  0x00,
  0x61,
  0x93,
  0x96,
  0x6c,
  0x18,
  0x36,
  0x69,
  0xc9,
  0x86,
  0x00,
  0x00,
  0x00,
  0x00
};
//와이파이 이미지
const uint8_t BITMAP_WIFI[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x0f, 0xf0, 0x00,
  0x00, 0x70, 0x0e, 0x00,
  0x01, 0x80, 0x01, 0x80,
  0x02, 0x07, 0xe0, 0x40,
  0x00, 0x38, 0x1c, 0x00,
  0x00, 0xc0, 0x03, 0x00,
  0x00, 0x03, 0xc0, 0x00,
  0x00, 0x1c, 0x38, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x80, 0x00,
  0x00, 0x01, 0x80, 0x00
};

//3g이미지
const uint8_t BITMAP_3G[] PROGMEM = {
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x06,
  0x00, 0x36,
  0x01, 0xb6,
  0x0d, 0xb6,
  0x6d, 0xb6,
  0x6d, 0xb6,
  0x6d, 0xb6,
  0x6d, 0xb6,
  0x6d, 0xb6
};

//베터리가 칸이 0칸
const uint8_t BITMAP_BATT_0[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x60, 0x30, 0x18,
  0x60, 0x30, 0x1e,
  0x60, 0x30, 0x1e,
  0x60, 0x30, 0x1e,
  0x60, 0x00, 0x1e,
  0x60, 0x30, 0x18,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리가 칸이 1칸
const uint8_t BITMAP_BATT_1[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x6c, 0x00, 0x18,
  0x6c, 0x00, 0x1e,
  0x6c, 0x00, 0x1e,
  0x6c, 0x00, 0x1e,
  0x6c, 0x00, 0x1e,
  0x6c, 0x00, 0x18,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리가 칸이 2칸
const uint8_t BITMAP_BATT_2[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x6d, 0x80, 0x18,
  0x6d, 0x80, 0x1e,
  0x6d, 0x80, 0x1e,
  0x6d, 0x80, 0x1e,
  0x6d, 0x80, 0x1e,
  0x6d, 0x80, 0x18,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리가 칸이 3칸
const uint8_t BITMAP_BATT_3[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x6d, 0xb0, 0x18,
  0x6d, 0xb0, 0x1e,
  0x6d, 0xb0, 0x1e,
  0x6d, 0xb0, 0x1e,
  0x6d, 0xb0, 0x1e,
  0x6d, 0xb0, 0x18,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리가 칸이 4칸
const uint8_t BITMAP_BATT_4[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x6d, 0xb6, 0x18,
  0x6d, 0xb6, 0x1e,
  0x6d, 0xb6, 0x1e,
  0x6d, 0xb6, 0x1e,
  0x6d, 0xb6, 0x1e,
  0x6d, 0xb6, 0x18,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리가 칸이 5칸(full)
const uint8_t BITMAP_BATT_5[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xff, 0xf8,
  0x60, 0x00, 0x18,
  0x6d, 0xb6, 0xd8,
  0x6d, 0xb6, 0xde,
  0x6d, 0xb6, 0xde,
  0x6d, 0xb6, 0xde,
  0x6d, 0xb6, 0xde,
  0x6d, 0xb6, 0xd8,
  0x60, 0x00, 0x18,
  0x7f, 0xff, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//베터리 충전중.....
const uint8_t BITMAP_BATT_ON[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x7f, 0xef, 0xf8,
  0x60, 0x00, 0x18,
  0x6f, 0xaf, 0xd8,
  0x6f, 0x60, 0xde,
  0x6f, 0x7d, 0xde,
  0x6e, 0x0b, 0xde,
  0x6f, 0xd3, 0xde,
  0x6f, 0xd7, 0xd8,
  0x60, 0x00, 0x18,
  0x7f, 0xdf, 0xf8,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};

//선택시 화살표
const uint8_t BITMAP_tri[] PROGMEM = {
  0x80,
  0xc0,
  0xe0,
  0xf0,
  0xe0,
  0xc0,
  0x80
};
//와이파이이지미 2번
const uint8_t BITMAP_wifi_2[] PROGMEM = {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x03, 0xf0, 0x00,
  0x0c, 0x0c, 0x00,
  0x10, 0x02, 0x00,
  0x21, 0xe1, 0x00,
  0x06, 0x18, 0x00,
  0x08, 0x04, 0x00,
  0x01, 0xe0, 0x00,
  0x02, 0x10, 0x00,
  0x00, 0xc0, 0x00,
  0x00, 0xc0, 0x00,
  0x00, 0x00, 0x00
};
//현재위치보여주기위한 바
const uint8_t BITMAP_bar[] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

//device 연결 x
const uint8_t BITMAP_Device_disconnect[] PROGMEM = {
  0x00, 0x00,
  0x40, 0x04,
  0x20, 0x78,
  0x11, 0xb8,
  0x08, 0xd8,
  0x04, 0x68,
  0x02, 0x30,
  0x11, 0x10,
  0x18, 0x80,
  0x2c, 0x40,
  0x36, 0x20,
  0x3b, 0x10,
  0x3c, 0x08,
  0x40, 0x04
};
//device 연결 o
const uint8_t BITMAP_Device_connect[] PROGMEM = {
  0x00, 0x00,
  0x00, 0x08,
  0x00, 0x30,
  0x01, 0xf0,
  0x0e, 0xe0,
  0x0b, 0x60,
  0x0d, 0xa0,
  0x16, 0xc0,
  0x1b, 0x40,
  0x1d, 0xc0,
  0x3e, 0x00,
  0x30, 0x00,
  0x40, 0x00,
  0x00, 0x00
};
//sever 연결 x
const uint8_t BITMAP_Server_disconnect[] PROGMEM = {
  0x0f, 0xf8,
  0x1f, 0xfc,
  0x1f, 0xfc,
  0x0f, 0xf8,
  0x10, 0x04,
  0x1f, 0xf8,
  0x0f, 0xbc,
  0x10, 0x42,
  0x1e, 0xa5,
  0x0e, 0x99,
  0x10, 0x99,
  0x1e, 0xa5,
  0x0f, 0x42,
  0x00, 0x3c
};
//sever 연결 o
const uint8_t BITMAP_Server_connect[] PROGMEM = {
  0x0f, 0xf8,
  0x1f, 0xfc,
  0x1f, 0xfc,
  0x0f, 0xf8,
  0x10, 0x04,
  0x1f, 0xf8,
  0x0f, 0x7c,
  0x10, 0x82,
  0x1d, 0x05,
  0x0d, 0x4d,
  0x11, 0x79,
  0x1d, 0x31,
  0x0e, 0x82,
  0x00, 0x7c
};
//사용자 연결 x
const uint8_t BITMAP_User_disconnect[] PROGMEM = {
  0x03, 0x80,
  0x07, 0xc0,
  0x07, 0xc0,
  0x07, 0xc0,
  0x03, 0x80,
  0x0c, 0x60,
  0x10, 0x10,
  0x14, 0x50,
  0x12, 0x90,
  0x11, 0x10,
  0x12, 0x90,
  0x14, 0x50,
  0x10, 0x10,
  0x1f, 0xf0
};
//사용자 연결 o
const uint8_t BITMAP_User_connect[] PROGMEM = {
  0x03, 0x80,
  0x07, 0xc0,
  0x07, 0xc0,
  0x07, 0xc0,
  0x03, 0x80,
  0x0f, 0xe0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0,
  0x1f, 0xf0
};
//% 이미지
const uint8_t BITMAP_LOGO[] PROGMEM = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x0f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3f,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x7f,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3f,0xff,0xff,0xff,0xfc,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x1f,0xff,0xf0,0x00,
0x1f,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x7f,0xff,0xfc,0x00,
0x1f,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x7f,0x00,0x00,0x01,0xff,0xff,0xff,0x00,
0x0f,0xff,0xf8,0x3f,0xff,0xf0,0x00,0x00,0xff,0x00,0x00,0x07,0xff,0xfe,0x0f,0xc0,
0x0f,0xff,0xf8,0x07,0xff,0xf8,0x00,0x00,0xff,0x80,0x00,0x0f,0xff,0xe0,0x01,0xf0,
0x0f,0xff,0xf8,0x01,0xff,0xfc,0x00,0x00,0xff,0x80,0x00,0x1f,0xff,0x80,0x00,0x78,
0x07,0xff,0xf8,0x00,0x7f,0xfe,0x00,0x01,0xff,0x80,0x00,0x3f,0xff,0x00,0x00,0x3c,
0x03,0xff,0xf8,0x00,0x1f,0xff,0x80,0x01,0xff,0x80,0x00,0x7f,0xfe,0x00,0x00,0x0c,
0x03,0xff,0xf8,0x00,0x1f,0xff,0x80,0x01,0xff,0x80,0x00,0xff,0xf8,0x00,0x00,0x04,
0x01,0xff,0xf8,0x00,0x07,0xff,0xc0,0x01,0xff,0xc0,0x01,0xff,0xf8,0x00,0x00,0x00,
0x01,0xff,0xf8,0x00,0x03,0xff,0xe0,0x01,0xff,0xc0,0x03,0xff,0xf0,0x00,0x00,0x00,
0x00,0xff,0xf8,0x00,0x03,0xff,0xf0,0x01,0xff,0xc0,0x07,0xff,0xe0,0x00,0x00,0x00,
0x00,0xff,0xf8,0x00,0x01,0xff,0xf0,0x01,0xff,0xc0,0x07,0xff,0xc0,0x00,0x00,0x00,
0x00,0x7f,0xf8,0x00,0x01,0xff,0xf8,0x03,0xff,0xc0,0x0f,0xff,0xc0,0x00,0x00,0x00,
0x00,0x3f,0xf8,0x00,0x00,0xff,0xf8,0x03,0xff,0xc0,0x0f,0xff,0x80,0x00,0x00,0x00,
0x00,0x3f,0xf8,0x00,0x00,0xff,0xfc,0x03,0xff,0xe0,0x1f,0xff,0x80,0x00,0x00,0x00,
0x00,0x1f,0xf8,0x00,0x00,0x7f,0xfc,0x03,0xff,0xe0,0x1f,0xff,0x00,0x00,0x00,0x00,
0x00,0x1f,0xf8,0x00,0x00,0x7f,0xfe,0x03,0xff,0xe0,0x1f,0xff,0x00,0x00,0x00,0x00,
0x00,0x0f,0xf8,0x00,0x00,0x7f,0xfe,0x03,0xff,0xe0,0x3f,0xff,0x00,0x00,0x00,0x00,
0x00,0x0f,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xff,0x00,0x00,0x00,0x00,
0x00,0x07,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x03,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x03,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x03,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x01,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x01,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x00,0xf8,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x00,0x78,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x00,0x78,0x00,0x00,0x3f,0xfe,0x03,0xff,0xe0,0x3f,0xfe,0x00,0x00,0x00,0x00,
0x00,0x00,0x38,0x00,0x00,0x7f,0xfe,0x03,0xff,0xe0,0x3f,0xff,0x00,0x00,0x00,0x00,
0x00,0x00,0x38,0x00,0x00,0x7f,0xfe,0x03,0xff,0xe0,0x3f,0xff,0x00,0x00,0x00,0x00,
0x00,0x00,0x18,0x00,0x00,0x7f,0xfc,0x03,0xff,0xe0,0x1f,0xff,0x00,0x00,0x00,0x00,
0x00,0x00,0x08,0x00,0x00,0xff,0xfc,0x03,0xff,0xe0,0x1f,0xff,0x80,0x00,0x00,0x00,
0x00,0x00,0x08,0x00,0x00,0xff,0xf8,0x03,0xff,0xc0,0x0f,0xff,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0xff,0xf8,0x03,0xff,0xc0,0x0f,0xff,0xc0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0xff,0xf0,0x03,0xff,0xc0,0x0f,0xff,0xc0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0xff,0xf0,0x01,0xff,0xc0,0x07,0xff,0xc0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x07,0xff,0xe0,0x01,0xff,0xc0,0x03,0xff,0xf0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x07,0xff,0xe0,0x01,0xff,0xc0,0x01,0xff,0xf0,0x00,0x00,0x00,
0x00,0x20,0x00,0x00,0x0f,0xff,0xc0,0x01,0xff,0x80,0x01,0xff,0xf8,0x00,0x00,0x06,
0x00,0x38,0x00,0x00,0x1f,0xff,0x80,0x01,0xff,0x80,0x00,0xff,0xfc,0x00,0x00,0x0e,
0x00,0x1c,0x00,0x00,0x3f,0xff,0x00,0x01,0xff,0x80,0x00,0x7f,0xff,0x00,0x00,0x1e,
0x00,0x1e,0x00,0x00,0xff,0xfe,0x00,0x01,0xff,0x80,0x00,0x3f,0xff,0x80,0x00,0x78,
0x00,0x07,0x80,0x03,0xff,0xfc,0x00,0x00,0xff,0x80,0x00,0x1f,0xff,0xe0,0x00,0xf0,
0x00,0x03,0xff,0xff,0xff,0xf0,0x00,0x00,0xff,0x00,0x00,0x07,0xff,0xff,0xff,0xc0,
0x00,0x00,0xff,0xff,0xff,0xc0,0x00,0x00,0x7f,0x00,0x00,0x03,0xff,0xff,0xff,0x80,
0x00,0x00,0x3f,0xff,0xff,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x7f,0xff,0xfe,0x00,
0x00,0x00,0x03,0xff,0xf0,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x07,0xff,0xe0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
