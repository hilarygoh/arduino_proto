const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;
// set LED pin numbers

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;
// set sensor pin numbers

int redValue = 0;
int greenValue = 0;
int blueValue = 0;
// set and store the light levels for each LED

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;
// set and store the sensor readings


void setup(){
    Serial.begin(9600);
    // open the serial port, set baud rate
    pinMode(greenLEDPin, OUTPUT); //set LED pins to output mode
    pinMode(redLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
}

void loop(){
   // read the value of each sensor
   redSensorValue = analogRead(redSensorPin); //read pin A0
   delay(5);
   greenSensorValue = analogRead(greenSensorPin); // read pin A1
   delay(5);
   blueSensorValue = analogRead(blueSensorPin); // read pin A2

   // print sensor readings to console
   Serial.print("Raw Sensor Values \t red: ");
   Serial.print(redSensorValue);
   Serial.print("\t green: ");
   Serial.print(greenSensorValue);
   Serial.print("\t blue: ");
   Serial.print(blueSensorValue);

   // convert the sensor readings so we can set the duty cycle
   redValue = redSensorValue/4;
   greenValue = greenSensorValue/4;
   blueValue = blueSensorValue/4;

   // print LED light levels
   Serial.print("Mapped Sensor Values \t red: ");
   Serial.print(redValue);
   Serial.print("\t green: ");
   Serial.print(greenValue);
   Serial.print("\t blue: ");
   Serial.print(blueValue);

   // set the duty cycles
   analogWrite(redLEDPin, redValue); // what pin, what duty cycle
   analogWrite(greenLEDPin, greenValue);
   analogWrite(blueLEDPin, blueValue);

}