#include <Adafruit_LiquidCrystal.h>

// LCD Pins
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2); /*Initialize the LCD and tell it which pins is to be used for communicating*/

// Global Var
#define contra 9 // Define the pin that controls the contrast of the screen
#define bri 10   // Define the pin the controls the brightness of the screen
char[] Incomming_values = "0"

    void
    setup()
{ //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // put your setup code here, to run once:
  lcd.begin(16, 2);        // Tell the LCD that it is a 16x2 LCD
  pinMode(contra, OUTPUT); // set pin 9 to OUTPUT
  pinMode(bri, OUTPUT);    // Set pin 10 to OUTPUT
  // pinMode-ing OUTPUT makes the specified pin output power
  digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
                            this lets you see the words*/
  analogWrite(bri, 255);     // Outputs full power to the screen brightness LED
} //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loop()
{ //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    // put your main code here, to run repeatedly:
    lcd.print(Incoming_value); // Output " Hello, World!!" on the first line of the LCD
    // lcd.setCursor(0, 1); /*Set the (invisible) cursor on the first place second row of the LCD.
    lcd.print("16x2 LCD Screen");

    delay(5000);
    digitalWrite(contra, LOW);
    lcd.setCursor(0, 0);
  }
}
