void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* RGB LED
analogWrite(9, 0);
analogWrite(10, 0);
analogWrite(11, 0);
  */
digitalWrite(2, LOW);
delayMicroseconds(2);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);

long duration = pulseIn(3, HIGH);
  if(duration == 0){
    return;
  }
long distance = duration / 58.2;
  /* 시리얼
  char pr[12];
  sprintf(pr, "distance = %d", distance);
  Serial.println(pr);
  delay(200);
  */
  
  if(distance < 10){
    tone(8, 450, 1000);
    delay(80);
    noTone(8);
    //analogWrite(11, 255);
  } else if (distance < 20){
    tone(8, 330, 1000);
    delay(300);
    noTone(8);
    //analogWrite(10, 255);
  } else if(distance < 30){
    tone(8, 262, 1000);
    delay(600);
    noTone(8);
    //analogWrite(9, 255);
  }
  delay(100);

}
