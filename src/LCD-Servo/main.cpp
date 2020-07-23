#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);  // Set the LCD I2C address

void setup()
{
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();  // go home

  Serial.begin(9600);
  Serial.println(F("Initalizing"));
}
 
void loop()
{
  // Wait a few seconds between measurements.
  lcd.clear();
  lcd.setCursor(0,0); // column,row starts at 0

  Serial.print(F(">>>"));
  String s = Serial.readStringUntil(/r);

  lcd.print("Read: ");
  lcd.setCursor(0,1); // column,row starts at 0
  lcd.print(s);

}
 
 
