// 스마트 가로등 만들기
// 초음파 센서로 감지한 거리가 20cm보다 작으면 자동으로 가로등에 불이 들어오게 함.
// 가로등 불이 필요없다면 버튼으로 불이 꺼지게 함.
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // Trig
  pinMode(3, INPUT); // Echo
  pinMode(9, INPUT); // Button
  pinMode(10, OUTPUT); // LED
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH);
  if ( duration == 0){
    return;
  }
   
  long distance = duration / 58.2;
    if ( distance < 20 ) {
      analogWrite(10, HIGH);
      if ( digitalRead(9) == HIGH){
        analogWrite(10, LOW);
        delay(5000);
      }
    } else {
      digitalWrite(10, LOW);
   }
 }
