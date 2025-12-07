//declear
int led = 6;
int button = 2;

//state of color
int flagColor = 0;
//state of last button
int lastState = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  //read value of button
  int state = digitalRead(button);
  //when dont press -> state = 1

  if(lastState == 1 && state == 0){
    flagColor = !flagColor;
    digitalWrite(led, flagColor);
    delay(200);
  }

  lastState = state;
}