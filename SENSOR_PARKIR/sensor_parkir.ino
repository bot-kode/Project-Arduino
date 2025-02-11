#include <Wire.h>
#define Buzzer 10
#define trigPin 8
#define echoPin 9

long duration;
int distance = 0;

void setup(){
  pinMode(trigPin, OUTPUT); // setting triggerpin sebagai output
  pinMode(echoPin, INPUT); // setting echopin sebagai Input
  pinMode(Buzzer, OUTPUT); // setting Buzzer sebagai Output
  Serial.begin(9600); // setting kecepatan pengiriman serial monitor
}

void loop(){
  digitalWrite(trigPin, HIGH);// aktifkan sensor ultrasonic
  delayMicroseconds(10); // selama 10 microseconds
  digitalWrite(trigPin, LOW); // matikan sensor ultrasonic
  duration = pulseIn(echoPin, HIGH); // baca rentan waktu dari trigPin High sampai echoPin high
  distance= duration*0.034/2; //konversi selang waktu ke CM
  
  if (distance > 10) // Hanya menampilkan jarak jika jaraknya kurang dari 300 cm / 3 meter
{
  Serial.println(distance); // kirim data jarak ke PC
  digitalWrite(Buzzer,LOW);
}
  else if (distance < 10 && distance >= 8) 
{
  Serial.println(distance); 
  digitalWrite(Buzzer,HIGH);
  delay(500);
  digitalWrite(Buzzer,LOW);
  delay(500);
}
  else if (distance < 8 && distance >= 6 ) 
{
  Serial.println(distance); 
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(100);
}
  else if (distance < 6 &&  distance >= 4 ) 
{
  Serial.println(distance); 
  digitalWrite(Buzzer,HIGH);
  delay(50);
  digitalWrite(Buzzer,LOW);
  delay(50);
}
  else if (distance < 4  ) 
{
  Serial.println(distance); // kirim data jarak ke PC
  digitalWrite(Buzzer,HIGH);
  delay(50);
}
}