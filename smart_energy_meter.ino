#include <PZEM004Tv30.h>          // importing library for working of smart energy meter.
PZEM004Tv30 pzem(11,12);          // pin mode setting for arduino board.
void setup()
{
   Serial.begin(115200);          // baud rate = data transmission rate.
}
void loop()
{
     float voltage = pzem.voltage();        // calculating VOLTAGE value.
     if (voltage != NAN)
     {
         Serial.print("Voltage: ");
         Serial.print(voltage);             // displaying the value of VOLTAGE on Serial Monitor.
         Serial.println("V");               // unit of VOLTAGE
     }
     else
         Serial.println("Error Reading the Voltage");
     float current = pzem.current();         // calculating CURRENT value.
     if (current != NAN)
     {
         Serial.print("Current: ");
         Serial.print(current);              // displaying the value of CURRENT on Serial Monitor.
         Serial.println("A");                // unit of CURRENT.
     }
     else
         Serial.println("Error Reading the Current");
     float power = pzem.power();             //calculating POWER value.
     if (current != NAN)
     {
         Serial.print("Power: ");
         Serial.print(power);                // displaying the value of POWER on Serial Monitor.
         Serial.println("W");                // unit of POWER.
     }
     else
         Serial.println("Error Reading the Power");
     float energy = pzem.energy();             // calculating ENERGY value.
     if (current != NAN)
     {
         Serial.print("Energy: ");
         Serial.print(energy,3);               // displaying the value of ENERGY on Serial Monitor.
         Serial.println("kWh");                // unit of ENERGY.
     }
     else
         Serial.println("Error Reading the Energy");
     float frequency = pzem.frequency();      // calculating FREQUENCY value.
     if (current != NAN)
     {
         Serial.print("Frequency: ");
         Serial.print(frequency, 1);          // displaying the value of FREQUENCY on Serial Monitor.
         Serial.println("Hz");                // unit of FREQUENCY.
     }
     else
         Serial.println("Error Reading the Frequency");
     float pf = pzem.pf();                 // calculating POWER FACTOR value.
     if (current != NAN)
     {
         Serial.print("Power Factor: ");
         Serial.print(pf);                    // displaying the value of POWER FACTOR on Serial Monitor.
         Serial.println("pf"); 
     }
     else
         Serial.println("Error Reading the Power Factor");
     Serial.println();
     delay(2000);             //represents the time a program should wait until moving to next looping step
 }

 //Serial.println(); = used for printing and displaying value in Serial Monitor.
