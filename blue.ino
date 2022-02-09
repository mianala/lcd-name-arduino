// #include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

// LCD Pins
// Thi is obtained from the Scanner Code
LiquidCrystal_I2C lcd(0x3F, 20, 4);

String Incomming_values = "";

void setup()
{

  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mianala");
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0)
  {
    // read the incoming byte:hopefuly this will clear the screen at every new value
    Incomming_values = Serial.readString();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Incomming_values);

    lcd.setCursor(0, 1);
    // removed delay, todo: split string and print
  }
}
