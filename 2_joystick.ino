#include <Servo.h>
#define SERVO_PIN 9
#define XJOY_PIN A5                  //Y axis reading from joystick will go into analog pin A5
#define YJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
Servo myservo ;
 
void setup()
{
 Serial.begin(9600);

 myservo.attach(9);
}
 
void loop()
{
 delay(200);                    
                  
 int joystickYVal = analogRead(YJOY_PIN) ;  //read joystick input on pin A1
 int anglevalue1= map(joystickYVal,0,1023,0,180);
 myservo.write(anglevalue1);      //write the calculated value to the servo  

 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A5
 int anglevalue= map(joystickXVal,0,1023,0,180);
 myservo.write(anglevalue);      //write the calculated value to the servo  

}
