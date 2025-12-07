//declear
int pinAnalog = A0;
int sensorPin = 2;

//setup
void setup() {
  pinMode(sensorPin, 2);
  Serial.begin(9600);
}

//run
void loop() {
  //read value state from pin 2
  int state = digitalRead(sensorPin);
  //read value adc from A0
  int adc = analogRead(pinAnalog);
  Serial.print("Value of ADC: ");
  Serial.println(adc);
  Serial.print("Value of state: ");
  Serial.println(state);
  delay(800);
}
