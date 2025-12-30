#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "LCD Project"
#define BLYNK_AUTH_TOKEN "ISI_TOKEN_KAMU"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ===== WiFi =====
char ssid[] = "NAMA_WIFI";
char pass[] = "PASSWORD_WIFI";

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== BLYNK TEXT INPUT =====
BLYNK_WRITE(V1) {  
  String text = param.asStr();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Blynk Msg:");
  lcd.setCursor(0,1);
  lcd.print(text);
}

// ===== BLYNK BUTTON CLEAR =====
BLYNK_WRITE(V2) {
  if (param.asInt() == 1) {
    lcd.clear();
  }
}

void setup() {
  Serial.begin(9600);

  Wire.begin(D2, D1);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Connecting...");
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.print("Blynk Online");
}

void loop() {
  Blynk.run();
}
