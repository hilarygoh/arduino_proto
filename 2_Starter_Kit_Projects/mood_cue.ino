#include <Servo.h>
// import servo library, get it from the Arduino Library Manager and install onto board

Servo myServo;
// create the servo object

int const potPin = A0; //potentiometer
int potVal; // store the analog ouput
int angle; //angle servo moves to

void setup(){
    myServo.attach(9); //servo is attached to pin 9

    Serial.begin(9600);
}

void loop(){
 potVal = analogRead(potPin); // read pin A0
 Serial.print("potVal: ");
 Serial.print(potVal);

 angle = map(potVal, 0 , 1023, 0, 179); // map and scale servo motor movement
 Serial.print(" , angle: "); 
 Serial.println(angle);

 myServo.write(angle); // move servo
 delay(15);
}