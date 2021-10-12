#include <Servo.h>
Servo myservo;

//조도센서를 사용하여 300보다 낮으면 서보 모터를 90도 움직이기
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600); // 시리얼 통신 속도 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(A0) < 300) {
    myservo.write(90);
  } else {
    myservo.write(0);
  }
  Serial.println(analogRead(A0));
  delay(1000);
}
