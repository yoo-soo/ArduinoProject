#include <Servo.h>
Servo myservo;

// 초음파 센서를 사용해서 30cm 안에 물체가 인식되면 서브모터를 180도 움직이기
// 주차차단기
// 자동차가 차단기 근처에 오면 차단기가 90도 각도로 움직이게 구현
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, LOW);
  delayMicroseconds(10);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long distance = pulseIn(3, HIGH) / 58;
  if(distance < 30){
    myservo.write(90);
    delay(2000);
  } else{
    myservo.write(0);
    delay(1000);
  }delay(100);
}
