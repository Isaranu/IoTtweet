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

const char *userid = "your_IoTtweet_userID";            /*IoTtweet account user ID (6 digits, included zeor pre-fix)*/
const char *key = "your_registered_IoT_device_key";     /*IoTtweet registered device key in "MY IOT Garage"*/
const char *ssid = "your_wifi_ssid";                    /*Your-WiFi-router-SSID*/
const char *password = "your_wifi_password";            /*Your-WiFi-password*/

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
  
  /*Example : Read status slider no.1 on dashboard.
   * This command will return data type as float to you 
   * command parameter : ReadAnalogSlider(userid,key,slider number);
   */
  float slider1_read = myiot.ReadAnalogSlider(userid,key,1);

  /*Print output to serial monitor*/
  Serial.println();
  Serial.print("Analog Slider 1 value is ");
  Serial.print(slider1_read);

  delay(10);

}
