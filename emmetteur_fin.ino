#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

 

unsigned long val;
unsigned long val2;
unsigned long signalCompteur = 0;
long t,t0;

 

void setup() {
  
    Serial.begin(9600);
    mySwitch.enableTransmit(10);
}
void loop() {
    
    //Read JoyStick
    val = analogRead(0);
    val = map(val,0,1023,0,180);     // scale it to use it with the servo (value between 0 and 180)

 

    val2 = analogRead(1);   // reads the value of the potentiometer (value between 0 and 1023)
    val2 = map(val2,512,1023,1000,2000);   // scale it to use it with the servo library (value between 0 and 180)
 
//    if (val != 0) {
//      mySwitch.send(val,20);
//    } else {
//      mySwitch.send(1,20);   
//    }
//    mySwitch.send(val2,20);    // Send the signal to the reciver
//    Serial.print();
//      mySwitch.send(val2 * 256 + val, 20);

 

    SendData(val,val2); // in group 2 we have 2 sensors 
}

 

void SendData( unsigned long sensor1, unsigned long sensor2)
{
//message = message + sensor1 +"," + sensor2 + "," + sensor3 +"," + sensor4 + "," + sgroup;
//mlength = message.length(); // find the number of characters in a message.
//  str = message;
//  str.toCharArray(cstr,100);
//  Serial.println(str);
//  Serial.println(cstr);
//  Serial.println(mlength);

 

    signalCompteur++;

 

    Serial.print("sensor1 = ");
    Serial.println(sensor1);
    Serial.print("sensor2 = ");
    Serial.println(sensor2);
    
    Serial.print("signalCompteur = ");
    Serial.println(signalCompteur);

 

    unsigned long valToSend = (sensor1 % 256) + (sensor2 << 8) + ((signalCompteur % 256) << 24);
    Serial.print("valToSend = ");
    Serial.println(valToSend);

 

/*  
  for (int i = 0; i < 9; i++) {
   unsigned long toto = (sensor2 << i);
//   toto = 0xFFFFFFFF;
  Serial.print("toto[");
  Serial.print(i);
  Serial.print("] = ");
  Serial.println(toto);
  }
*/

 

  
  mySwitch.send(valToSend, 32); 

 

}
