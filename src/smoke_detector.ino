#include <TM1637Display.h>

#define MQ2_PIN 34      // 模擬輸入
#define LED_PIN 25
#define BUZZER_PIN 26
#define CLK 27          // TM1637 CLK
#define DIO 14          // TM1637 DIO

TM1637Display display(CLK, DIO);
int alertCount = 0;

void setup() {
  pinMode(MQ2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  display.setBrightness(5); // 亮度 0~7
  display.showNumberDec(0); // 初始顯示 0
  Serial.begin(115200);
}

void loop() {
  int gasDetected = digitalRead(MQ2_PIN);

  if (gasDetected == LOW) { // 有煙霧（有些模組輸出低電位代表有氣體）
    alertCount++;
    display.showNumberDec(alertCount);
    airRaidAlarm();  // 呼叫空襲聲音警報
    Serial.println("⚠️ 偵測到煙霧！");
  } else {
    digitalWrite(LED_PIN, LOW);
    // digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}

void airRaidAlarm() {
  // 上升音調
  for (int freq = 400; freq <= 1000; freq += 10) {
    tone(BUZZER_PIN, freq);
    digitalWrite(LED_PIN, HIGH);
    delay(10);
  }

  // 下降音調
  for (int freq = 1000; freq >= 400; freq -= 10) {
    tone(BUZZER_PIN, freq);
    digitalWrite(LED_PIN, LOW);
    delay(10);
  }

  noTone(BUZZER_PIN); // 停止蜂鳴器
}
