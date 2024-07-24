#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo coinServo;  // create servo object to control a servo
const int coinPin = 2;  // Pin where the coin acceptor is connected
const int chargingPortPin = 8;  // Pin where the charging port relay is connected
const int chargingTime = 1500;  // Charging time in milliseconds (e.g., 30000 ms = 30 seconds)

void setup() {
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("I");
  lcd.print("N");
  lcd.print("S");
  lcd.print("E");
  lcd.print("R");
  lcd.print("T");
  lcd.print(" ");
  lcd.print("C");
  lcd.print("O");
  lcd.print("I");
  lcd.print("N");
  pinMode(coinPin, INPUT);
  pinMode(chargingPortPin, OUTPUT);
  digitalWrite(chargingPortPin, LOW);  // Ensure charging port is initially off
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(coinPin) == HIGH) {  // Check if coin is inserted
    Serial.println("Coin detected");
    delay(1000);  // Wait for coin to be inserted
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("C");
    lcd.print("H");
    lcd.print("A");
    lcd.print("R");
    lcd.print("G");
    lcd.print("I");
    lcd.print("N");
    lcd.print("G");

    coinServo.write(0);  // Return servo to initial position
    startCharging();
  }
}

void startCharging() {
  Serial.println("Charging started");
  digitalWrite(chargingPortPin, HIGH);  // Turn on charging port
  delay(chargingTime);  // Wait for the charging time to elapse
  digitalWrite(chargingPortPin, LOW);  // Turn off charging port
  Serial.println("Charging stopped");
}