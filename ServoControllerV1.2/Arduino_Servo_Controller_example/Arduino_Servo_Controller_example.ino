//##########################################################################

int serialBound = 9600;
int servoPins[5] = {0,0,0,0,0}; //Note Pin 1 does not work on the Arduino UNO

//##########################################################################

#include <Servo.h>
Servo usedServo;
int dataIndex = 0;
int savedAngles[5];

void setup() {
  Serial.begin(serialBound);
  Serial.println("Servo Controller Arduino Sketch 1.0v");
  Serial.println("Ready");
}

void loop() {
  ServoControllerMain();
  
  //Your Code:


  //
}

void ServoControllerMain(){
    if(Serial.available() != 0){
    savedAngles[dataIndex] = Serial.parseInt();
    Serial.println(savedAngles[dataIndex]);
    dataIndex++;
  
    if(dataIndex == 5){
       dataIndex = 0;

       Serial.println("setting servos...");
       for(int i = 0; i != 4; i++){
        usedServo.attach(servoPins[i]);
        delay(1000);
        usedServo.write(savedAngles[i]);
        delay(1000);
       }
         Serial.read();
         Serial.flush();    
    }
  }
}
