#include <Servo.h>

Servo myServo;
int sensorPhotoresistor = A0;

unsigned long previousMillis = 0;
const unsigned long timeDelay = 200;  // thời gian chờ giữa các bước

int state = 0;       // 0 = chờ, 1 = quay 90, 2 = quay về 0
bool ready = true;   // chỉ true khi servo đã trả về 0° và sẵn sàng trigger lần tiếp theo

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  myServo.write(0);  // luôn bắt đầu ở vị trí 0
}

void loop() {

  int adc = analogRead(sensorPhotoresistor);
  Serial.println(adc);
  unsigned long currentMillis = millis();

  // ----------------------------
  // 1. PHÁT HIỆN ÁNH SÁNG YẾU
  // ----------------------------
  if (adc > 470 && ready && state == 0) {
    state = 1;            // Bắt đầu bước 1
    ready = false;        // Không cho kích hoạt lại
    previousMillis = currentMillis;
    myServo.write(90);    // chuyển ngay đến 90°
  }

  // ----------------------------
  // 2. BƯỚC 1: ĐANG Ở 90°
  // ----------------------------
  if (state == 1 && currentMillis - previousMillis >= timeDelay) {
    myServo.write(0);     // quay về 0°
    state = 2;            // chuyển sang bước 2
    previousMillis = currentMillis;
  }

  // ----------------------------
  // 3. BƯỚC 2: TRẢ VỀ 0°
  // ----------------------------
  if (state == 2 && currentMillis - previousMillis >= timeDelay) {
    state = 0;            // kết thúc chu kỳ
    ready = true;         // sẵn sàng cho lần ánh sáng yếu tiếp theo
  }
}
