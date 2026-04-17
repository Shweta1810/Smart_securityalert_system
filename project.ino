#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
#define DHTPIN 2
#define DHTTYPE DHT11
#define PIR 3
#define GAS A0
#define BUZZER 7

DHT dht(DHTPIN, DHTTYPE);

// Gas calibration
int baseValue = 0;
bool gasAlert = false;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(PIR, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, HIGH); // OFF

  dht.begin();

  lcd.print("Calibrating...");
  
  for (int i = 0; i < 50; i++) {
    baseValue += analogRead(GAS);
    delay(100);
  }
  baseValue = baseValue / 50;

  lcd.clear();
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  int motion = digitalRead(PIR);
  int gasValue = analogRead(GAS);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  bool tempAlert = false;

  lcd.clear();

  // -------- LINE 1 (TEMP + HUM) --------
  lcd.setCursor(0, 0);

  if (isnan(temp) || isnan(hum)) {
    lcd.print("Sensor Error");
  } else {
    lcd.print("T:");
    lcd.print(temp);
    lcd.print("C H:");
    lcd.print(hum);
    lcd.print("%");

    if (temp > 34) {
      tempAlert = true;
    }
  }

  // -------- GAS --------
  if (gasValue > baseValue + 70) {
    gasAlert = true;
  } 
  else if (gasValue < baseValue + 30) {
    gasAlert = false;
  }

  // -------- LINE 2 --------
  lcd.setCursor(0, 1);

  if (gasAlert) {
    lcd.print("Smoke ALERT ");
  } else {
    lcd.print("NoSmoke ");
  }

  if (motion == HIGH) {
    lcd.print("M:Y");
  } else {
    lcd.print("M:N");
  }

  // -------- BUZZER --------
  if (gasAlert || motion == HIGH || tempAlert) {
    digitalWrite(BUZZER, LOW);   // ON
  } else {
    digitalWrite(BUZZER, HIGH);  // OFF
  }

  delay(500);
}
