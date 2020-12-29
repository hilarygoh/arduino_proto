const int sensorPin = A0; // analog input, temperature sensor pin, TMP36
const float baselineTemp = 22.0; // 

void setup(){
    Serial.begin(9600); // open serial port, baud rate
    for(int pinNumber = 2; pinNumber<5; pinNumber++){ // run through all pins sequentially
        pinMode(pinNumber, OUTPUT); // set all pins to OUTPUT mode
        digitalWrite(pinNumber, LOW); // set all pins to LOW
        //wedfw'eoihfwoeihf
    }
}

void loop(){
    // read A0 pin and store ADC reading
    int sensorVal = analogRead(sensorPin); 
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);

    // convert the ADC reading to voltage
    float voltage = (sensorVal/1024.0)*5.0;
    Serial.print("  Volts: ");
    Serial.print(voltage);
    
    // convert voltage to temperature C
    float temperature = (voltage - 0.5) * 100;
    Serial.print("  Degrees C: ");
    Serial.print(temperature);

    //set thresholds for LED's

    if(temperature < baselineTemp+2){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    // Green LED - everything's OK
    }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);   
    // Yellow LED - getting a little warm
    }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    // Red LED - getting too hot!
    }else if(temperature >= baselineTemp+6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        Serial.print("  Too Hot!");
    }
    Serial.println("");
    delay(500);

}