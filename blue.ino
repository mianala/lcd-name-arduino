// #import <LiquidCrystal.h>

#include <Adafruit_LiquidCrystal.h>
#include <string.h>

// LCD Pins
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Global Var
#define contra 9
#define bri 10
String Incomming_values = "";

void setup()
{
  lcd.begin(16, 2);
  pinMode(contra, OUTPUT);
  pinMode(bri, OUTPUT);
  digitalWrite(contra, LOW);
  analogWrite(bri, 255);
}
void loop()
{
  if (Serial.available() > 0)
  {
    Incomming_values = Serial.readString();
    lcd.print(Incomming_values);

    lcd.setCursor(0, 1);

    lcd.print("100% accurate");

    delay(5000);
    digitalWrite(contra, LOW);
    lcd.setCursor(0, 0);
  }
}
