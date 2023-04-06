
//ULTRASONIC SENSOR WITH A PIEZO BUZZER.

#define echoPin 10        // attach a digital pin from Arduino to pin Echo of HC-SR04
#define trigPin 9         // attach a digital pin from Arduino to pin Trig of HC-SR04
const int buz=9;          // buzzer is connected to the Arduino's pin 9
long duration;            // variable for the duration of sound wave travel
int distance;             // variable for the distance measurement
void setup()
{
  pinMode(trigPin, OUTPUT);     // Sets the trigPin as an OUTPUT pin
  pinMode(echoPin, INPUT);      // Sets the echoPin as an INPUT pin
  pinMode(buz,OUTPUT);          // sets the buzzer S pin as an OUTPUT pin
  Serial.begin(115200);         // Serial Communication is starting with 115200 of baudrate speed / data transmission speed
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);                  // Sets the trigPin HIGH (ACTIVE) for 2 microseconds
  int buz_state = digitalRead(buz);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);            // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);     // Calculating the distance
  distance = duration * 0.034 / 2;       // Speed of sound wave divided by 2 (go and back)
  Serial.print("Distance: ");
  Serial.print(distance);                // printing the value of distance in cms.
  Serial.println(" cm");
  if(distance<5)                         // checking the condition for whether the distance is less than 5 cms
  {
    Serial.println("Object near to the sensor.");
    digitalWrite(buz_state,HIGH);               // will switch on the buzzer
    delay(500);
    digitalWrite(buz_state,LOW);                // will switch off the buzzer
    delay(500);
  } 
}


// delay() = It is 
