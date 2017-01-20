/*
 * This example demonstrate how to write data from your "Internet of Things" to IoTtweet dashboard
 * coding from IoTtweet.com
 * Created : 2016.Oct.4
 * Updated : 2016.Oct.4, PM
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

  /*Set output pin of LED (Built-in LED of NodeMCU is IO no. 16)*/
  pinMode(LED_BUILTIN,OUTPUT);

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

  /*Example : Read status switch no.1 on dashboard.
   * This command will return "ON" or "OFF" string to you    
   * command parameter : ReadDigitalSwitch(userid,ket,switch number);
   */
  String sw1_read = myiot.ReadDigitalSwitch(userid,key,1);

  delay(10);

  /*Drive to built-in LED*/
  if(sw1_read == "ON")
  {
      digitalWrite(LED_BUILTIN,LOW);
   }else
    {
      digitalWrite(LED_BUILTIN,HIGH);
     }
}
