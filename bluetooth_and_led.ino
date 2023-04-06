
// Resources - https://create.arduino.cc/projecthub/mayooghgirish/arduino-bluetooth-basic-tutorial-d8b737

// controlling LED light using bluetooth HC-05 module and suitable mobile application.

// mobile app - https://www.amazon.com/Mayoogh-Girish-LED-Controller/dp/B01DR5T226/ref=sr_1_1?s=mobile-apps&ie=UTF8&qid=1463859311&sr=1-1&keywords=LED+Controller

char in=0;                         // control/flag variable.
void setup()
{
  Serial.begin(9600);              // mentioning the data transmission rate(baud rate)
  pinMode(13,OUTPUT);              // function of the LED (13 is the LED_BUILTIN_PIN)
}
void loop()
{
  if(Serial.available()>0)         // returns the number of characters which have arrived in the serial buffer that are ready to read.
  {
    in=Serial.read();              // reading the value from the bluetooth sensor
    Serial.print(in+"\n");         // displaying the value
    if(in=='1')
    digitalWrite(13,HIGH);         // if satisfied, then the LED will glow
    else if(in=='0')
    digitalWrite(13,LOW);          // if not satisfied, LED will not glow
  }
}
