int switchState = 0;

void setup(){
pinMode(3, OUTPUT); //pin 3 is an LED and set to output
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, INPUT);
}

void loop(){
switchState = digitalRead(2); // check for voltage on pin 2, is it pressed on?
// if there is voltage then state will change to HIGH
// if there is no voltage then state will change to LOW

    if (switchState == LOW) {
    // button is not pressed
    digitalWrite(3, HIGH); //green LED, on
    digitalWrite(4, HIGH); // yellow LED, off
    digitalWrite(5, LOW); // red LED, off
}
    else { //buton is pressed
        delay(250); //wait for a quarter second
    //toggle the LEDS
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    }
} // start loop again