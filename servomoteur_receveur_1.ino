#include <RCSwitch.h>
#include <Servo.h>

Servo direction1 ;
Servo vitesse ;

RCSwitch mySwitch = RCSwitch();
int pos = 0;
void setup() {
    Serial.begin(9600);

    mySwitch.enableReceive(0);
    direction1.attach(3, 1000, 2000);

}

void loop() {
    if (mySwitch.available()) {
        int value = mySwitch.getReceivedValue();
        int angle = map(value, 0, 1023, 0, 180);
    // on met à jour l'angle sur le servo
        direction1.write(angle);
        Serial.println(value);
       /* if (value > 0) {
          Serial.println(value);
          direction1.write(value);
          /*
            if (mySwitch.getReceivedValue()==1){digitalWrite(4,HIGH);}
            else if (mySwitch.getReceivedValue()==2){digitalWrite(5,HIGH);}
            else if (mySwitch.getReceivedValue()==3){digitalWrite(8,HIGH);}
            else if (mySwitch.getReceivedValue()==4){digitalWrite(9,HIGH);}
            else if (mySwitch.getReceivedValue()==5){
                digitalWrite(4,LOW);
                digitalWrite(5,LOW);
                digitalWrite(8,LOW);
                digitalWrite(9,LOW);
            }
          */

        mySwitch.resetAvailable();
    }
}
