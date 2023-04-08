#include <ESP8266WiFi.h>                          // importing the basic ESP8266 library.
#include <WiFiClient.h>                           // importing Wi-Fi library
#include <ESP8266WebServer.h>                     // importing the ESP8266 library used for connecting to server.
ESP8266WebServer server(80);
const int PHOTO_RESISTOR_PIN = A0;                // setting the photoresistor input pin
const int THRESHOLD = 500;
void setup()
{
  Serial.begin(115200);                           // setting the baud rate.
  pinMode(PHOTO_RESISTOR_PIN, INPUT);             // taking input from photoresistor.
  WiFi.mode(WIFI_STA);
  WiFi.begin("OnePlus 9RT 5G", "mypassword");     // initiating the Wi-Fi setup.
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  server.begin();                                 // initialized the communication from device to server.
}
void loop()
{
  int lightLevel = analogRead(PHOTO_RESISTOR_PIN);              // taking analog input of the light intensity level from the sensor.
  Serial.print("Light Level: ");
  Serial.println(lightLevel);                                   // printing the value of light level.
  if (lightLevel < THRESHOLD)                                   // checking the condition that whether the level of light is less than threshold or not.
    server.send(200, "text/html", "<h1>Lab is Open</h1>");      // sending data to the server that lab is open.
  else
    server.send(200, "text/html", "<h1>Lab is Closed</h1>");    // sending data to the server that lab is closed.
    
  server.handleClient();                                        // used to process incoming HTTP connections, handles them, send responses, exits and then repeats them.
  delay(1000);
}

//void handleRoot() {
//  server.send(200, "text/html", "<h1>Lab is Closed</h1>");
//}


// delay() = It is used for pausing the program for a specific amount of time in milliseconds before going to next part of program.
// Serial.println(); = used for printing and displaying value in Serial Monitor.
