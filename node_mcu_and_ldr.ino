#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const int PHOTO_RESISTOR_PIN = A0;
const int THRESHOLD = 500;

void setup() {
  Serial.begin(115200);
  pinMode(PHOTO_RESISTOR_PIN, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin("OnePlus 9RT 5G", "GIRI@6714");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  int lightLevel = analogRead(PHOTO_RESISTOR_PIN);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel < THRESHOLD) {
    server.send(200, "text/html", "<h1>Lab is Open</h1>");
  }
  else {
    server.send(200, "text/html", "<h1>Lab is Closed</h1>");
  }

    `qWL
    server.handleClient();
  delay(1000);

}

//void handleRoot() {
//  server.send(200, "text/html", "<h1>Lab is Closed</h1>");
//}
