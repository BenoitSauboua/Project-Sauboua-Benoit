#include <RCSwitch.h>
#include <Servo.h>

#define SERIAL_DEBUG

Servo Direction ;
Servo ESC;     // create servo object to control the ESC
RCSwitch mySwitch = RCSwitch();

 

int compteur = 0;
unsigned long test = 0;

 

void setup() {
  
  Serial.begin(9600);
  mySwitch.enableReceive(0);
  Direction.attach(3);
  ESC.attach(9);
  }
  
unsigned long lastvalue;

 

void loop() {

 

  
  
  if (mySwitch.available()) {
    
    unsigned long value = mySwitch.getReceivedValue();
    if (value != lastvalue){
      lastvalue = value;
      if (value == 0) {
      ifdef SERIAL_DEBUG{
        while(!Serial
         Serial.print("Unknown encoding");}
      }
       end if
      else { 

 

      unsigned char servo = value & 0xFF;
      unsigned int brushless = (value >> 8) & 0xFFFF;
      unsigned char signalCompteur = (value >> 24) & 0xFF;
      Direction.write(servo);
      ESC.writeMicroseconds(brushless);
      signal(signalCompteur);
      }
    }
        
  mySwitch.resetAvailable();
  }
}

 

void signal(unsigned char signalCompteur){ 

 

  if (compteur == signalCompteur){
    test = 1;
    Serial.print("Test : ");
    Serial.println(test);

 

  }
  else {
    test = 0;
    Serial.print("Test : ");
    Serial.println(test);

 

  }
  
  Serial.print("Signal compteur : ");
  Serial.println(signalCompteur);
  Serial.print("Compteur : ");
  Serial.println(compteur);
  compteur++;    
}
 
