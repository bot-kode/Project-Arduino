const int buzzer = 2;
const int vibrationSensor = 3;

int vibrationSensorState = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(vibrationSensor, INPUT);
}

void loop() {
  vibrationSensorState = digitalRead(vibrationSensor);
  if(vibrationSensorState == HIGH)
  {
    digitalWrite(buzzer, HIGH);
    delay(2000);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
}
