/*
 * This example demonstrate how to write data from your "Internet of Things" to IoTtweet dashboard
 * coding from IoTtweet.com
 * Created : 2016.Sep.25
 * Updated : 2016.Oct.4,PM
 * By Isaranu Janthong
 * IoTtweet Founder.
 * Visit us at : www.iottweet.com
 */

#include <ESP8266WiFi.h>
#include <IoTtweet.h>

const char *userid = "your-user-id";            /*IoTtweet account user ID (6 digits, included zeor pre-fix)*/
const char *key = "your-user-key";     /*IoTtweet registered device key in "MY IOT Garage"*/
const char *ssid = "your-ssid";                    /*Your-WiFi-router-SSID*/
const char *password = "your-wifi-password";            /*Your-WiFi-password*/

IoTtweet myiot;  /*naming your devices*/

void setup() {
  
  Serial.begin(115200);

  /*Get IoTtweet Library version*/
  String libvers = myiot.getVersion();
  Serial.println("IoTtweet Library vesion : " + String(libvers));

  /*Connect WiFi*/
  Serial.println("\nConnect wifi...");
  bool conn = myiot.begin(ssid,password);

    if(!conn)
    {
      Serial.println("WiFi connection failed.");
    }else
    {
      Serial.println("WiFi connected !");
     }

}  

void loop() {

  /*Read control panel status (Switch and Slider)*/
  String control_panel_status = myiot.ReadControlPanel(userid,key);

  /*Print out result: Output is JSON format*/
  Serial.println(control_panel_status);

  /*Delay interval time for read control status*/
  delay(1000);
}
