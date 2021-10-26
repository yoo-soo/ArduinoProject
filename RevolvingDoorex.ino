// 30cm 안에 물체가 인식되면 스텝 모터를 정방향 3바퀴, 역방향 3바퀴 움직이고, 삼색 LED를 이용하여 경고등과 수동 부조 경고음을 동작시킴.
// 자동회전문 예제코드

#include <Stepper.h>
const int stepsPerRevolution = 64;
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); // LED
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  myStepper.setSpeed(300); //회전속도 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delayMicroseconds(2);
  digitalWrite(2, LOW);
  
  long duration = pulseIn(3, HIGH);
  if(duration == 0){
    return;
  }
  
  long distance = duration / 58.2;
  if(distance < 30){ // 초음파 센서 30cm안에 물체가 인식되면
    tone(7, 220, 1000); // 경고음
    delay(1000); 
    
    digitalWrite(12, HIGH); // 경고등
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
    
    for(int i = 0; i < 96; i++){ // 정방향 3바퀴
      myStepper.step(stepsPerRevolution);
    }
    delay(500);
    
    for(int i = 0; i < 96; i++){ // 역방향 3바퀴
      myStepper.step(-stepsPerRevolution);
    }
    delay(500);
  }
}
