
// NeuralMesh Solution

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin for the temperature sensor
#define TEMPERATURE_SENSOR_PIN A0

// I2C address for the LCD display
#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3

// Create a LiquidCrystal_I2C object
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.print("Temperature:");
}

void loop() {
  // Read analog temperature sensor value
  int sensorValue = analogRead(TEMPERATURE_SENSOR_PIN);

  // Convert analog value to temperature (replace this with your sensor-specific conversion)
  float temperatureCelsius = map(sensorValue, 0, 1023, 0, 100);

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println(" °C");

  // Display temperature on LCD
  lcd.setCursor(0, 1);
  lcd.print(temperatureCelsius);
  lcd.print(" C  ");

  // Delay for a while before reading the temperature again
  delay(1000);
}
