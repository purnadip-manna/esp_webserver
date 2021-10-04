#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wifi network credentials
const char* ssid     = "WifiName"; // Name of the wifi
const char* password = "WifiPassword";  // Password of the wifi
String userPass = "dXNlcm5hbWU6cGFzc3dvcmQ=";  
// Base64 encoded string of username:password (For Basic Auth)
// https://www.base64encode.org/ from here we can encode "username:password"

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

/*
  GPIO PIN Details:
  ----------------------
  D0 ==> 16
  D1 ==>  5
  D2 ==>  4
  D3 ==>  0
  D5 ==> 14
  D6 ==> 12
  D7 ==> 13
  D8 ==> 15
  RX ==>  3
  TX ==>  1
  S3 ==> 10
  S2 ==>  0

*/
// Assign output variables to GPIO pins
const int D0 = 16;
const int D1 = 5;
const int D2 = 4;
const int D3 = 0;
const int D5 = 14;
const int D6 = 12;
const int D7 = 13;
const int D8 = 15;

// Status variables of GPIO pins
String statusD0 = "off";
String statusD1 = "off";
String statusD2 = "off";
String statusD3 = "off";
String statusD5 = "off";
String statusD6 = "off";
String statusD7 = "off";
String statusD8 = "off";


// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  
  // Initialize the output variables as outputs
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available(); // Listen for incoming clients
  
  if (client) { // If a new client connects,
  Serial.println("New Client.");      // print a message out in the serial port
  String currentLine = "";            // make a String to hold incoming data from the client
  while (client.connected()){         // loop while the client's connected
    if (client.available()) {       // if there's bytes to read from the client
      char c = client.read();         // read a byte, then
      Serial.write(c);                // print it out the serial monitor
      header += c;
      if (c == '\n') {               
      /* 
      if the byte is a newline character
      if the current line is blank, you got two newline characters in a row.
      that's the end of the client HTTP request, so send a response:
      */
      if (currentLine.length() == 0) {
        /*
           checking if header is valid
           Finding the right credential string, then loads web page
        */
          if(header.indexOf(userPass) >= 0) // password authentication...
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // GET requests handler ----------------------------


            // turn (ON/OFF) the GPIO Pins

            // Pin D0 (ON/OFF) ----------------------------------------
            if (header.indexOf("GET /on/0") >= 0) {
              Serial.println("Turning on PIN : 0");
              client.print("ok");
              digitalWrite(D0, HIGH);
              statusD0 = "on";
            }
            
            else if (header.indexOf("GET /off/0") >= 0) {
              Serial.println("Turning off PIN : 0");
              client.print("ok");
              digitalWrite(D0, LOW);
              statusD0 = "off";
            }

            // Pin D1 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/1") >= 0) {
              Serial.println("Turning on PIN : 1");
              client.print("ok");
              digitalWrite(D1, HIGH);
              statusD1 = "on";
            }
            
            else if (header.indexOf("GET /off/1") >= 0) {
              Serial.println("Turning off PIN : 1");
              client.print("ok");
              digitalWrite(D1, LOW);
              statusD1 = "off";
            }

            // Pin D2 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/2") >= 0) {
              Serial.println("Turning on PIN : 2");
              client.print("ok");
              digitalWrite(D2, HIGH);
              statusD2 = "on";
            }
            
            else if (header.indexOf("GET /off/2") >= 0) {
              Serial.println("Turning off PIN : 2");
              client.print("ok");
              digitalWrite(D2, LOW);
              statusD2 = "off";
            }

            // Pin D3 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/3") >= 0) {
              Serial.println("Turning on PIN : 3");
              client.print("ok");
              digitalWrite(D3, HIGH);
              statusD3 = "on";
            }
            
            else if (header.indexOf("GET /off/3") >= 0) {
              Serial.println("Turning off PIN : 3");
              client.print("ok");
              digitalWrite(D3, LOW);
              statusD3 = "off";
            }

            // Pin D5 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/5") >= 0) {
              Serial.println("Turning on PIN : 5");
              client.print("ok");
              digitalWrite(D5, HIGH);
              statusD5 = "on";
            }
            
            else if (header.indexOf("GET /off/5") >= 0) {
              Serial.println("Turning off PIN : 5");
              client.print("ok");
              digitalWrite(D5, LOW);
              statusD5 = "off";
            }

            // Pin D6 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/6") >= 0) {
              Serial.println("Turning on PIN : 6");
              client.print("ok");
              digitalWrite(D6, HIGH);
              statusD6 = "on";
            }
            
            else if (header.indexOf("GET /off/6") >= 0) {
              Serial.println("Turning off PIN : 6");
              client.print("ok");
              digitalWrite(D6, LOW);
              statusD6 = "off";
            }

            // Pin D7 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/7") >= 0) {
              Serial.println("Turning on PIN : 7");
              client.print("ok");
              digitalWrite(D7, HIGH);
              statusD7 = "on";
            }
            
            else if (header.indexOf("GET /off/7") >= 0) {
              Serial.println("Turning off PIN : 7");
              client.print("ok");
              digitalWrite(D7, LOW);
              statusD7 = "off";
            }

            // Pin D8 (ON/OFF) ----------------------------------------
            else if (header.indexOf("GET /on/8") >= 0) {
              Serial.println("Turning on PIN : 8");
              client.print("ok");
              digitalWrite(D8, HIGH);
              statusD8 = "on";
            }
            
            else if (header.indexOf("GET /off/8") >= 0) {
              Serial.println("Turning off PIN : 8");
              client.print("ok");
              digitalWrite(D8, LOW);
              statusD8 = "off";
            }

            // Get status of GPIO pins ---------------------------------

            else if (header.indexOf("GET /status/0") >= 0) {
              Serial.println(statusD0);
              client.println(statusD0);
            }
            else if (header.indexOf("GET /status/1") >= 0) {
              Serial.println(statusD1);
              client.println(statusD1);
            }
            else if (header.indexOf("GET /status/2") >= 0) {
              Serial.println(statusD2);
              client.println(statusD2);
            }
            else if (header.indexOf("GET /status/3") >= 0) {
              Serial.println(statusD3);
              client.println(statusD3);
            }
            else if (header.indexOf("GET /status/5") >= 0) {
              Serial.println(statusD5);
              client.println(statusD5);
            }
            else if (header.indexOf("GET /status/6") >= 0) {
              Serial.println(statusD6);
              client.println(statusD6);
            }
            else if (header.indexOf("GET /status/7") >= 0) {
              Serial.println(statusD7);
              client.println(statusD7);
            }
            else if (header.indexOf("GET /status/8") >= 0) {
              Serial.println(statusD8);
              client.println(statusD8);
            }
            
            break;
          }
          
        // Wrong user or password, so HTTP request fails... 
          else { 
            client.println("HTTP/1.1 401 Unauthorized");
            client.println("WWW-Authenticate: Basic realm=\"Secure\"");
            client.println("Content-Type: text/html");
            client.println();
            client.println("Authentication failed");
            break;
          }
        }
        
        else { // if you got a newline, then clear currentLine
          currentLine = "";
        }
      }
      
      else if (c != '\r') { // if you got anything else but a carriage return character,
        currentLine += c; // add it to the end of the currentLine
      }
    }
  }
  // Clear the header variable
  header = "";
  // Close the connection
  client.stop();
  Serial.println("Client disconnected.");
  Serial.println("");
  }
}
