#define TRIG 9
#define ECHO 10 

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
} 


void loop() {
  //send signal
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  //calculate time return
  long duration = pulseIn(ECHO, HIGH);

  //calculate distance
  float distance = duration*0.0343/2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);
}
