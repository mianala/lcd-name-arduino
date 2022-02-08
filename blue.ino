// #include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

// LCD Pins

LiquidCrystal_I2C lcd(0x3F, 20, 4);

String Incomming_values = "";

void setup()
{

  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mianala");
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);

    Incomming_values = Serial.readString();
    lcd.print(Incomming_values);

    lcd.setCursor(0, 1);

    lcd.print("100% accurate");

    delay(5000);
    lcd.setCursor(0, 0);
  }
}
