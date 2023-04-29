//##########################################################################

int serialBound = 9600;
int servoPins[5] = {0,0,0,0,0}; //Note Pin 1 does not work on the Arduino UNO

//##########################################################################

#include <Servo.h>
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
int dataIndex = 0;
int savedAngles[5];

void setup() {
  servo_1.attach(servoPins[0]);servo_2.attach(servoPins[1]);servo_3.attach(servoPins[2]);servo_4.attach(servoPins[3]);servo_5.attach(servoPins[4]);
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
        servo_1.write(savedAngles[0]);
        delay(1000);
        servo_2.write(savedAngles[1]);
        delay(1000);
        servo_3.write(savedAngles[2]);
        delay(1000);
        servo_4.write(savedAngles[3]);
        delay(1000);
        servo_5.write(savedAngles[4]);
        delay(1000);
       Serial.flush();    
    }
  }
}
