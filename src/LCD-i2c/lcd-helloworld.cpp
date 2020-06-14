#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);  // Set the LCD I2C address
#define DHTPIN 2
#define DHTTYPE DHT11
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

int motorPin = 3;

void setup()
{
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);

  lcd.home ();  // go home
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  Serial.begin(9600);

  dht.begin();

  pinMode(motorPin, OUTPUT);
}
 
void loop()
{
  // lcd.scrollDisplayLeft();
  // delay(200);
  //-----------------------

  // lcd.noDisplay();
  // delay(200);
  // lcd.display();
  //delay(200);
  //-------------------------
  // lcd.clear();
  //lcd.setCursor(0,1); // column,row starts at 0
  //lcd.setCursor(0,5);
  //lcd.print("HAI..");
  //delay(200);

  // Wait a few seconds between measurements.
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0); // column,row starts at 0

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    lcd.print("DHT hum Failed!");
    return;
  }
  if (isnan(f)) {
    lcd.print("DHT temp Failed!");
    return;
  }

  lcd.print(("Humidity: "));
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1); // column,row starts at 0
  lcd.print("Temp (F): ");
  lcd.print(f);

  // spin the fan
  // if (speed >= 0 && speed <= 255)
  if (f > 75) {
    analogWrite(motorPin, 100);
  } else {
    analogWrite(motorPin, 0);
  }
}
 
 
