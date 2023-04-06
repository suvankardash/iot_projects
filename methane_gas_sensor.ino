const int APin = 0;      // Connect AO of MQ4 with A0 of Arduino
const int DPin = 8;      // Connect DO of MQ4 with D8 of Arduino
int DOut;                // To Store Digital Output of MQ4
int AOut;                // To Store Analog Output of MQ4

void setup()
{
  Serial.begin(9600);        // initializing the baud rate for data transmission
  pinMode(DPin, INPUT);           // setting digital pin of gas sensor as input pin
  pinMode(LED_BUILTIN, OUTPUT);   // setting led in for output part
}
void loop()
{
  AOut = analogRead(APin);              // Take Analog Output of MQ4 Sensor
  DOut = digitalRead(DPin);             // Read Digital Output of MQ4 Sensor
  Serial.print("Methane Conentration: ");
  Serial.println(AOut);                     // printing the present amount of methane concentration in air.
  Serial.print("Threshold Value: ");
  Serial.print(DOut);                       // printing the safe value of methane concentration set by us.
  delay(500);
  if (DOut == HIGH)
    digitalWrite(LED_BUILTIN, HIGH);       // it will glow the led
  else
    digitalWrite(LED_BUILTIN, LOW);        // it will not glow the led 
}
