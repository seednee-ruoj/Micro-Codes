const int ledPin = 12; // LED connected to digital pin 13
const int buttonAPin = 2; // Button A connected to digital pin 2
const int buttonBPin = 3; // Button B connected to digital pin 3

int interval = 1000; // Initial blink interval (1000 ms = 1 second)
const int minInterval = 250; // Minimum interval (250 ms)
const int maxInterval = 2000; // Maximum interval (2000 ms)

unsigned long previousMillis = 0; // Stores the last time the LED was updated

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if it's time to toggle the LED
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Save the last time you blinked the LED
    
    // If the LED is off turn it on and vice-versa
    digitalWrite(ledPin, !digitalRead(ledPin));
  }

  // Check if Button A is pressed
  if (digitalRead(buttonAPin) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(buttonAPin) == LOW) {
      interval += 250; // Increase interval by 250 ms
      if (interval > maxInterval) {
        interval = maxInterval; // Cap interval at maximum
      }
      while (digitalRead(buttonAPin) == LOW); // Wait for button release
    }
  }

  // Check if Button B is pressed
  if (digitalRead(buttonBPin) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(buttonBPin) == LOW) {
      interval -= 250; // Decrease interval by 250 ms
      if (interval < minInterval) {
        interval = minInterval; // Cap interval at minimum
      }
      while (digitalRead(buttonBPin) == LOW); // Wait for button release
    }
  }
}
