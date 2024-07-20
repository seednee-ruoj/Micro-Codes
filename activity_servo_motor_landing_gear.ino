#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD library with the I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo Leg_servo;

int LegPos = 0;
int buttonExtend = 6;
int buttonRetract = 7;
int LED = 3; // Ensure this is a PWM-capable pin

bool retracted = true;
bool extended = false;

void setup() {
  Leg_servo.attach(10);
  Leg_servo.write(0); // Initial position of the servo motor
  pinMode(buttonExtend, INPUT_PULLUP);
  pinMode(buttonRetract, INPUT_PULLUP);
  pinMode(LED, OUTPUT); // servo cover alternative

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  // Print a message to the LCD
  lcd.print("Landing Gear");
  lcd.setCursor(0, 1);
  lcd.print("Status: Ready");
}

void loop() {
  // Read the button states
  int extendState = digitalRead(buttonExtend);
  int retractState = digitalRead(buttonRetract);

  // Check if the extend button is pressed
  if ((extendState == LOW) && retracted) {
    extendLandingGear();
  }

  // Check if the retract button is pressed
  if ((retractState == LOW) && extended) {
    retractLandingGear();
  }
}

void extendLandingGear() {
  // Open the doors
  lcd.clear();
  lcd.print("Opening Doors");
  for (int i = 0; i <= 255; i++) {
    analogWrite(LED, i); // Fade in LED
    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(i);
    delay(15);
  }

  // Extend the landing gear
  lcd.clear();
  lcd.print("Extending Gear");
  for (LegPos = 0; LegPos <= 180; LegPos += 1) {
    Leg_servo.write(LegPos);
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(LegPos);
    delay(5);
  }

  // Keep the LED on
  analogWrite(LED, 255);

  // Close the doors
  lcd.clear();
  lcd.print("Closing Doors");
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED, i); // Fade out LED
    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(i);
    delay(15);
  }

  retracted = false;
  extended = true;

  // Update LCD status
  lcd.clear();
  lcd.print("Gear Extended");
}

void retractLandingGear() {
  // Open the doors
  lcd.clear();
  lcd.print("Opening Doors");
  for (int i = 0; i <= 255; i++) {
    analogWrite(LED, i); // Fade in LED
    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(i);
    delay(15);
  }

  // Retract the landing gear
  lcd.clear();
  lcd.print("Retracting Gear");
  for (LegPos = 180; LegPos >= 0; LegPos -= 1) {
    Leg_servo.write(LegPos);
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(LegPos);
    delay(5);
  }

  // Keep the LED on
  analogWrite(LED, 255);

  // Close the doors
  lcd.clear();
  lcd.print("Closing Doors");
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED, i); // Fade out LED
    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(i);
    delay(15);
  }

  retracted = true;
  extended = false;

  // Update LCD status
  lcd.clear();
  lcd.print("Gear Retracted");
}
