#include <LiquidCrystal.h>
#include <Servo.h>
#include <DHT.h>

// 1. Hardware Pin Configurations
#define DHTPIN 2       // Temperature & Humidity sensor data pin
#define DHTTYPE DHT11  // Sensor model
#define LIGHT_PIN A0   // Photoresistor (light sensor) analog pin
#define SERVO_PIN 9    // SG90 Servo motor control pin
#define LED_PIN 13     // Night-light LED pin

// 2. Initialize System Components
// Standard 16-pin LCD wiring pins: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 6); 
DHT dht(DHTPIN, DHTTYPE);
Servo ventServo;

void setup() {
  Serial.begin(9600);
  
  // Start the sensors and the 16-column, 2-row LCD screen
  dht.begin();
  lcd.begin(16, 2); 
  
  // Attach the servo motor and set it to 0 degrees (Closed)
  ventServo.attach(SERVO_PIN);
  ventServo.write(0); 
  
  // Prepare the LED pin to send power out
  pinMode(LED_PIN, OUTPUT); 
}

void loop() {
  // 3. Sensing: Read temperature and light levels
  float temp = dht.readTemperature();
  int lightVal = analogRead(LIGHT_PIN);

  // Safeguard: Show an error message if the temp sensor comes unplugged
  if (isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error   ");
    return;
  }

  // 4. Displaying: Print live numbers onto the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temp, 1) + "C   ");
  lcd.setCursor(0, 1);
  lcd.print("Light: " + String(lightVal) + "    ");

  // 5. Acting (Climate): Open vent if temp goes above 22.5°C
  if (temp > 22.5) { 
    ventServo.write(90); 
  } else {
    ventServo.write(0);  
  }

  // 6. Acting (Lighting): Turn LED ON if room gets dark (below 400)
  if (lightVal < 400) {
    digitalWrite(LED_PIN, HIGH); 
  } else {
    digitalWrite(LED_PIN, LOW);  
  }

  // Pause 2 seconds before repeating the loop
  delay(2000); 
}
