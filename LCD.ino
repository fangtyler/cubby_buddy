#include <LiquidCrystal.h>

int sensorPin = A0;
int sensorValue = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Light reading:");
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 1);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  lcd.print(sensorValue);
  delay(1000);
}
