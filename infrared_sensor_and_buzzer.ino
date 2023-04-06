
// USE OF THE INFRARED SENSOR FOR ACTIVATING LED AND BUZZER.

int IRSensor = 2;              // connect ir sensor to arduino pin 2
int LED;
int BUZ=3;                     //connecting BUZZER to pin 3 of ARDUINO.
void setup()
{
 pinMode (IRSensor,INPUT);     // sensor pin INPUT
 pinMode(BUZ,OUTPUT);          // buzzer pin for OUTPUT
}
void loop()
{
  int statusSensor = digitalRead(IRSensor);    // reading the value from the IR Sensor.
  if (statusSensor == 1)
  {
    Serial.println("near");
    digitalWrite(LED, LOW);                    // LED LOW, i.e. it will not glow 
    digitalWrite(BUZ, LOW);                    // BUZZER LOW, i.e. it will not beep
  }
  else
  {
    Serial.println("far ");
    digitalWrite(LED, HIGH);                   // LED High, i.e. it will glow
    digitalWrite(BUZ, HIGH);                   // BUZZER High, i.e. it will beep
  }
}
