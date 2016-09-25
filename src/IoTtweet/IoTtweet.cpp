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

#include "IoTtweet.h"

#define IoTtweet_HOST "api.iottweet.com"
#define IoTtweet_PORT 80
#define IoTtweet_libVersion "v0.1.0"

//Connect WiFi router
bool IoTtweet::begin(const char *ssid, const char *passw)
{
    //Transfer variable
    _ssid = ssid;
    _passw = passw;
  int _cnt=0, _retry=30;
  bool _conn = false;

  //Connect WiFi
  WiFi.begin(_ssid,_passw);
  Serial.print("IoTweet wifi start connection...");

  //Connecting WiFi
  while ((WiFi.status() != WL_CONNECTED) && (_cnt <= _retry))
  {
    delay(200);
    _cnt++;
  }

  if(WiFi.status() == WL_CONNECTED)
  {
    _conn = true;
    Serial.println("\nWiFi for IoTtweet Connected !");
  }else{
    _conn = false;
  }

  return _conn;
}

//Connect to api.iottweet.com & send data to dashboard
String IoTtweet::WriteDashboard(const char *userid, const char *key, float slot0, float slot1, float slot2, float slot3, const char *tw, const char *twpb)
{
    //Transfer variable
    _userid = userid;
    _key = key;
    _slot0 = slot0;
    _slot1 = slot1;
    _slot2 = slot2;
    _slot3 = slot3;
    _tw = tw;
    _twpb = twpb;

    //Create connection TCP to api.iottweet.com
    WiFiClient client;

    if (client.connect(IoTtweet_HOST, IoTtweet_PORT))
    {
      //Start sending data package
      _str = "GET /?userid=";
      _str += _userid;
      _str += "&key=";
      _str += _key;
      _str += "&slot0=";
      _str += _slot0;
      _str += "&slot1=";
      _str += _slot1;
      _str += "&slot2=";
      _str += _slot2;
      _str += "&slot3=";
      _str += _slot3;
      _str += "&tw=";
      _str += _tw;
      _str += "&twpb=";
      _str += _twpb;
      _str += " HTTP/1.1\r\n";
      _str += "Host: api.iottweet.com\r\n";
      _str += "Connection: keep-alive\r\n\r\n";

      //Push data to api.iottweet.com
      client.print(_str);

      //Check response back
      while(client.available()){
        _response = client.readStringUntil('\r');
      }

      return _response;
    }
}

//Connect to dashboard and read status of all switch and slide
String IoTtweet::ReadControlPanel(const char *userid, const char *key)
{
  //Transfer variable
  _userid = userid;
  _key = key;

  //Create connection TCP to api.iottweet.com
  WiFiClient client;

  if (client.connect(IoTtweet_HOST, IoTtweet_PORT))
  {
    //Start sending data package
    _str = "GET /read/?userid=";
    _str += _userid;
    _str += "&key=";
    _str += _key;
    _str += " HTTP/1.1\r\n";
    _str += "Host: api.iottweet.com\r\n";
    _str += "Connection: keep-alive\r\n\r\n";

    //Push data to api.iottweet.com
    client.print(_str);

    //Check response back
    while(client.available()){
      _controlpanelstatus = client.readStringUntil('\r');
    }

    //--------- Start parse json message ---------------
    StaticJsonBuffer<2000> jsonBuffer;
    JsonObject& _root = jsonBuffer.parseObject(_controlpanelstatus);

    if (!_root.success())
  {
    Serial.println("parseObject() failed");
  }

   _sw1status = _root["sw1"];
   _sw2status = _root["sw2"];
   _sw3status = _root["sw3"];
   _sw4status = _root["sw4"];
   _sw5status = _root["sw5"];

   _sl1status = _root["slide1"];
   f_sl1status = String(_sl1status).toFloat();

   _sl2status = _root["slide2"];
   f_sl2status = String(_sl2status).toFloat();

   _sl3status = _root["slide3"];
   f_sl3status = String(_sl3status).toFloat();

   _allcontrol = "{";
   _allcontrol += "\"sw1\":\"";
   _allcontrol += _sw1status;
   _allcontrol += "\",";
   _allcontrol += "\"sw2\":\"";
   _allcontrol += _sw2status;
   _allcontrol += "\",";
   _allcontrol += "\"sw3\":\"";
   _allcontrol += _sw3status;
   _allcontrol += "\",";
   _allcontrol += "\"sw4\":\"";
   _allcontrol += _sw4status;
   _allcontrol += "\",";
   _allcontrol += "\"sw5\":\"";
   _allcontrol += _sw5status;
   _allcontrol += "\",";
   _allcontrol += "\"slider1\":\"";
   _allcontrol += f_sl1status;
   _allcontrol += "\",";
   _allcontrol += "\"slider2\":\"";
   _allcontrol += f_sl2status;
   _allcontrol += "\",";
   _allcontrol += "\"slider3\":\"";
   _allcontrol += f_sl3status;

   _allcontrol += "\"}";

    return _allcontrol;
  }

}


//Get IoTtweet library version information
String IoTtweet::getVersion()
{
  return IoTtweet_libVersion;
}
