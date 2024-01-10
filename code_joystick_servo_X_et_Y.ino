#include <Servo.h>
#define SERVO_PIN 9
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
#define YJOY_PIN A0                  //X axis reading from joystick will go into analog pin A1
Servo myservo ;

void setup()
{
 Serial.begin(9600);
 myservo.attach(9);
}
 
void loop()
{
 delay(200);                    
 int joyXVal = analogRead(XJOY_PIN) ;
 int joyYVal = analogRead(YJOY_PIN) ;//read joystick input on pin A1
 Serial.print(joyXVal);
 Serial.println() ;
 Serial.print(joyYVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print((joyXVal+520)/10);
 Serial.println() ;
 Serial.print((joyYVal+520)/10);//print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 myservo.write((joyXVal+520)/10);
}
