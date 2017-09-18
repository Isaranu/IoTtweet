[![Logo_Iottweet_official.png](https://www.iottweet.com/img/Logo_Iottweet_official.png)]

# IoTtweet
IoTtweet library for https://www.iottweet.com dashboard using. Internet of Things cloud data storage and control

### What is IoTtweet ?
-  IoTtweet.com is  web APIs for storage and control your Internet of Things over network. Anywhere, anytime in the world.

### How to starting ?</br>
<b>[step 1.]</b> </br>
  Signup account with https://www.iottweet.com/signup/register.php</br>
 
<b>[step 2.]</b></br>
  Prepare  your IoT device and install  2 library as below into your computer.</br>
  2.1) ESP8266WiFi.h library</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Open Arduino IDE on your computer.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Go to <b>preferences</b>.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Add link "http://arduino.esp8266.com/stable/package_esp8266com_index.json" into <b>Board Manager URLs</b>.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Save and re-start Arduino IDE.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Go to <b>Tool > Boards > Boards Manager</b>.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Scroll down and find <i>"esp8266 by ESP8266 community"</i>. This is contained a library of ESP8266WiFi.h.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Click install, and after installed complete, click close.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Restart Arduino IDE again.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Open example, you will see some examples code of ESP8266WiFi.h. And now ready to coding ESP8266.</br>

  2.2) ArduinoJson.h library</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Open Arduino IDE on your computer.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Go to Sketch> Include Libraries > Manage Libraries </br>
&nbsp;&nbsp;&nbsp;&nbsp;- Search "ArduinoJson" in search box, and make install it.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Restart Arduino IDE again.</br>

  2.3) IoTtweet.h library (we provided in this GITHUB)</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Download this repository into your computer.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Extract files.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Copy folder name <b>IoTtweet</b> which contained 2 files of <b><u>IoTtweet.h</u></b> and <b><u>IoTtweet.cpp</u></b>, paste this folder at <b>Arduino > libraries</b>.</br>
&nbsp;&nbsp;&nbsp;&nbsp;- Restart Arduino IDE, ready to use IoTtweet command.</br>

<b>[step 3.]</b></br>
  Upload example code in this repository and change some parameter to your parameter.</br>
<code><i>const char *userid = <b>"your_IoTtweet_userID"</b>;</i></code>          
<code><i>const char *key = <b>"your_registered_IoT_device_key"</b>;</i></code>   
<code><i>const char *ssid = <b>"your_wifi_ssid"</b>;</i></code>                    
<code><i>const char *password = <b>"your_wifi_password"</b>;</i></code>         
<code><i>float <b>data0, data1, data2, data3</b>;</i></code>                               
<code><i>const char *private_tweet = <b>"Hello%20World"</b>;</i></code>                    
<code><i>const char *public_tweet = <b>"I%20am%20Internet%20of%20Things"</b>;</i></code></br>

:warning: :warning: Library this version is not supported "blank space" between each string to send tweet.
Please replace "blank space" with %20 

<b>[step 4.]</b></br>
  Let's tweet !!</br>
  See data on your dashboard and control your IoT from there.</br></br>
[![dash v3 iottweet.png](https://s16.postimg.org/ohp5o1bh1/dash_v3_iottweet.png)](https://postimg.org/image/lnm0al9ap/)

<b>Find out more at</b> : https://www.iottweet.com/getstarted.php</br>

<b>IoTtweet support team</b> :wolf:</br>
mailto:support@iottweet.com</br>
FB : www.facebook.com/IoTtweet</br>
FB group  talk :https://www.facebook.com/groups/191156967967490/
