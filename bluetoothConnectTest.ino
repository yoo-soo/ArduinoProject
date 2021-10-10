#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3

SoftwareSerial SwSerial(rxPin, txPin);
char data;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  SwSerial.begin(9600);
  Serial.println("Ready..");
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.flush();
  Serial.print("cmd : ");
  while ( !Serial.available());

  while ( Serial.available()){
    data = Serial.read();

    if(data == -1)
      break;

      SwSerial.print(data);
      Serial.print(data);

      delay(1);
  }

  Serial.println();
  delay(1000);
  Serial.print("return : ");

  while ( SwSerial.available() ){
    data = SwSerial.read();
      if(data == -1)
        break;

    Serial.print(data);
    delay(1);
  }
  Serial.println("");
}
