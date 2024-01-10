#include <RCSwitch.h>
#include <Servo.h>

Servo Direction ;
Servo ESC;    

RCSwitch mySwitch = RCSwitch();

void setup() {
  
  Serial.begin(9600);
  mySwitch.enableReceive(0);
  Direction.attach(3);
  ESC.attach(9,1000,2000);
  Serial.println("Setup OK");
}


void loop() {

  if (mySwitch.available()) {
    int servo = mySwitch.getReceivedValue();
    int brushless= mySwitch.getReceivedValue();

    if (servo == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.println("Received ");
 //     long data = mySwitch.getReceivedValue();
      Serial.println( servo );     
    


//      Serial.print( "servo : ");
//      Serial.println( servo );
//      Serial.print( "brushless : ");
//      Serial.println( brushless );


    Direction.write(servo);
    ESC.writeMicroseconds(brushless);    // Send the signal to the ESC

    }
    
    mySwitch.resetAvailable();

  } }
