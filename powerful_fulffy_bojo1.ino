#include<Servo.h> // Servo library
Servo s;

void setup()
{
  pinMode(5, OUTPUT); //LED
  pinMode(2, INPUT); //PIR sensor
  s.attach(3);// servo motor
  Serial.begin(9600);
}

void loop()
{
  int p=digitalRead(2);
  Serial.println(p);
  if(p==1){
    s.write(180);
    delay(2000);
    int r=analogRead(A0);
    Serial.print("Analog data: ");
    Serial.println(r);
    int j;
    j=map(r,6,679,0,255);
    Serial.println(j);
    analogWrite(5,j);
}
  else{
    s.write(0);
    delay(2000);
    digitalWrite(5,LOW);
  }
}