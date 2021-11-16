#define A0Pin 0
int A_1A = 11; // 모터드라이브 A_1A 핀 변수 선언
int A_2A = 12; // 모터드라이브 A_1B 핀 변수 선언
int needWater = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A_1A, OUTPUT); // 모터드라이브 A_1A의 pinMode 선언
  pinMode(A_2A, OUTPUT); // 모터드라이브 A_1B의 pinMode 선언 
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  needWater = analogRead(A0Pin); // 토양습도센서 센서값 읽어서 저장
  delay(1000);
  Serial.print("Asensor = ");
  Serial.println(needWater); // dry(0) ~ wet(1023) 값 출력

  if(needWater <= 400){
    pump(1);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    //analogWrite(6, 255);
  }
  else if(needWater > 400){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    //analogWrite(5, 255);
  } 
}

void pump(int flag){
  boolean inPin1 = HIGH;
  boolean inPin2 = LOW;

  if(flag == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  digitalWrite(A_1A, inPin1); // 펌프 A_1A에 write
  digitalWrite(A_2A, inPin2); // 펌프 A_1B에 wrtie
  delay(1000); // 1초 동안 물주기
  stop();
}

// 물주기 멈춤 함수
void stop(){
  digitalWrite(A_1A, LOW);
  digitalWrite(A_2A, LOW);
}
