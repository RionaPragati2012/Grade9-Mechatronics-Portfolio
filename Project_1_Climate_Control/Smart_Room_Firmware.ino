#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <DHT.h>

// Hardware Pin Configurations
#define DHTPIN 2
#define DHTTYPE DHT11
#define LIGHT_PIN A0
#define SERVO_PIN 9

// Initialize System Components
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 is the standard I2C address for these screens
Servo ventServo;

void setup() {
  // Start the USB Serial communication back to your laptop
  Serial.begin(9600);
  
  // Initialize the physical hardware modules
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  // Attach the servo motor to its control pin and set it to 0 degrees (Closed)
  ventServo.attach(SERVO_PIN);
  ventServo.write(0); 
}

void loop() {
  // 1. Telemetry Data Gathering (Sensing)
  float temp = dht.readTemperature();
  int lightVal = analogRead(LIGHT_PIN);

  // Error Safeguard: If the sensor fails or is unplugged, alert the screen
  if (isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error   ");
    return;
  }

  // 2. Human-Machine Interface Output (Displaying)
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temp, 1) + "C   ");
  lcd.setCursor(0, 1);
  lcd.print("Light: " + String(lightVal) + "    ");

  // 3. Closed-Loop Decision Automation (Acting)
  // If the room temperature exceeds 22.5 degrees Celsius:
  if (temp > 22.5) { 
    ventServo.write(90); // Rotate the actuator 90 degrees to mechanically open the vent
  } else {
    ventServo.write(0);  // Return the actuator to 0 degrees to close the vent
  }

  // Wait 2 seconds (2000 milliseconds) before running the loop again
  delay(2000); 
}
