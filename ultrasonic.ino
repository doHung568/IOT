#define TRIG 9
#define ECHO 10 
int BUZZER = 8;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
} 

void loop() {
  // send signal
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // calculate time return (with timeout)
  //avoid echo dont receive signal
  // if > 30ms, ECHO dont HIGH -> return 0
  long duration = pulseIn(ECHO, HIGH, 30000);

  // calculate distance
  float distance = duration * 0.0343 / 2;

  // print
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // buzzer logic
  if (distance > 0 && distance < 20) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(50);
}
