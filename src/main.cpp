#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
OneWire oneWire(2); // Data wire connected to digital pin 2

DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(2, INPUT_PULLUP); // Set pin 2 as input with pull-up resistor
  lcd.init();
  lcd.backlight(); // Turn on the backlight (if your LCD supports it)
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(2, 1);
  delay(1000);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  
  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.print(temperatureC);
  lcd.print((char)223);
  lcd.print("C");
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  delay(500);
}
