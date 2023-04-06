
//explaining the usage of DHT11 Module.

#include <dht11.h>                               // invoking DHT library
#define DHT11PIN 9                               // defining the DHT pin connection
dht11 DHT11;                                     // we are storing all the values of the library DHT11 in the variable declared as dht11
void setup()
{
  Serial.begin(9600);                            // defining the data rate transmission speed
}
void loop()
{
  Serial.println();
  int reading = DHT11.read(DHT11PIN);            // reading the value from the DHT 11 Module 
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);      // humidity display field
  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);   // temperature display field
  delay(2000);                                   // time delay for the operations to take place
}
