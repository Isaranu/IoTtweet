/*
library for IoTtweet.com, using via api.iottweet.com
Created by : IoTtweet tech. team
Date : 2016.Sep.22
Updated : 2016.Sep.23, 01:35
Updated : 2016.Sep.23, 16:50
Updated : 2016.Sep.24, 20:40
Updated : 2016.Sep.25, 12:03
    >> Release GITHUB : v0.1.0 on 25.Sep, 12:04
*/

#ifndef IoTtweet_h
#define IoTtweet_h

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ArduinoJson.h"

class IoTtweet
{

public:
  bool begin(const char *ssid, const char *passw);

  String WriteDashboard(const char *userid, const char *key, float slot0, float slot1, float slot2, float slot3, const char *tw, const char *twpb);
  String ReadControlPanel(const char *userid, const char *key);
  String getVersion();

private:
  const char *_ssid, *_passw;
  const char *_userid, *_key, *_tw, *_twpb;
  float _slot0, _slot1, _slot2, _slot3;
  const char *_libversion;
  String _str, _response, _controlpanelstatus;
  const char *_sw1status, *_sw2status, *_sw3status, *_sw4status, *_sw5status, *_sl1status, *_sl2status, *_sl3status;
  float f_sl1status, f_sl2status, f_sl3status;
  String _allcontrol;

};

#endif
