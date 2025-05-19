// #define MQ2_PIN 34
// #define LED_PIN 26
// #define BUZZER_PIN 25
#define LED_PIN 18
#define BUZZER_PIN 19

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  //digitalWrite(LED_PIN, LOW);
  //delay(500);
}
// int smokeThreshold = 300;  // 你可以調整這個值
// int smokeCount = 0;

// int segmentPins[] = {13, 14, 15, 16, 17, 18, 19}; // a~g

// // 七段顯示數字對應編碼（共陰極）
// const byte digits[10][7] = {
//   {1,1,1,1,1,1,0}, // 0
//   {0,1,1,0,0,0,0}, // 1
//   {1,1,0,1,1,0,1}, // 2
//   {1,1,1,1,0,0,1}, // 3
//   {0,1,1,0,0,1,1}, // 4
//   {1,0,1,1,0,1,1}, // 5
//   {1,0,1,1,1,1,1}, // 6
//   {1,1,1,0,0,0,0}, // 7
//   {1,1,1,1,1,1,1}, // 8
//   {1,1,1,1,0,1,1}  // 9
// };

// void setup() {
//   Serial.begin(115200);
//   pinMode(MQ2_PIN, INPUT);
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
//   for (int i = 0; i < 7; i++) {
//     pinMode(segmentPins[i], OUTPUT);
//   }
// }

// void loop() {
//   int smokeValue = analogRead(MQ2_PIN);
//   Serial.println(smokeValue);

//   if (smokeValue > smokeThreshold) {
//     digitalWrite(LED_PIN, HIGH);
//     digitalWrite(BUZZER_PIN, HIGH);
//     smokeCount++;
//     displayDigit(smokeCount % 10);
//     delay(1000);
//   } else {
//     digitalWrite(LED_PIN, LOW);
//     digitalWrite(BUZZER_PIN, LOW);
//     displayDigit(smokeCount % 10);
//   }

//   delay(500);
// }

// void displayDigit(int num) {
//   for (int i = 0; i < 7; i++) {
//     digitalWrite(segmentPins[i], digits[num][i]);
//   }
// }
