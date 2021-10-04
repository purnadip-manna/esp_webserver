# ESP Webserver
Normal ESP8266 webserver with Basic Auth to control its GPIO pins

## Wifi SSID & Password Setup
In the beginning of the code there are two variables `const char* ssid` and `const char* password` Here the wifi SSID and password need to put in order to connect with that wifi network.

## UserName & Password Setup
We just need to set the variable `userPass` with the Base64 encoded string of `username:password` like this **dXNlcm5hbWU6cGFzc3dvcmQ=**

## To Turn On a pin
We have to make a get request on `http://esp8266_ipaddress/on/<pin_no>`

## To Turn Off a pin
We have to make a get request on `http://esp8266_ipaddress/off/<pin_no>`

## To Check the status of a pin
We have to make a get request on `http://esp8266_ipaddress/status/<pin_no>`

## Implementing Basic Auth