#define TEMP_LM35 A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp_lm35 = (5.0*analogRead(TEMP_LM35)*100)/1024;
  Serial.print("온도 : "); 
  Serial.println(temp_lm35);
  delay(1000);
}
