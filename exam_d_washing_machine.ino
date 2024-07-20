int water = 2;
int spinF = 3; 
int spinR = 4;  // OUTPUT
int drain = 5;
int dry = 6;

int startB = 8;
int waterFinished = 9;  
int drainSensor = 10;
int drySensor = 11;
int waterLevelSensor = A5;  // Analog input for water level sensor

const int desiredWaterLevel = 500; // Example threshold value for desired water level

bool start = HIGH;
bool watered = HIGH;
bool washed = HIGH;
bool drained = HIGH;
bool dried = HIGH;

void setup() 
{
  Serial.begin(9600);
  pinMode(water, OUTPUT);
  pinMode(spinR, OUTPUT);
  pinMode(spinF, OUTPUT);
  pinMode(drain, OUTPUT);
  pinMode(dry, OUTPUT);
  pinMode(startB, INPUT_PULLUP);
  pinMode(waterFinished, INPUT_PULLUP);
  pinMode(drainSensor, INPUT_PULLUP);
  pinMode(drySensor, INPUT_PULLUP);
}

void loop()
{
  // Start button pressed
  if ((digitalRead(startB) == LOW) && (start == HIGH))
  {
    start = LOW;
    delay(20);
  }
  // Start button released
  if ((digitalRead(startB) == HIGH) && (start == LOW))
  {
    digitalWrite(water, HIGH);
    Serial.println("Loading water into wash bin");
    start = HIGH;
  }

  // Water finished sensor triggered
  if ((digitalRead(waterFinished) == LOW) && (watered == HIGH))
  {
    digitalWrite(water, LOW);
    Serial.println("Water loading finished");
    watered = LOW;
  }

  // Check water level sensor
  int waterLevel = analogRead(waterLevelSensor);
  if (waterLevel >= desiredWaterLevel && watered == HIGH)
  {
    watered = LOW;
    digitalWrite(water, LOW);
    Serial.println("Water loaded, starting washing cycle");

    // Washing cycle
    for (int i = 0; i < 5; i++) // Wash 5 times
    {
      digitalWrite(spinF, HIGH);
      digitalWrite(spinR, LOW);
      Serial.println("Washing: forward");
      delay(1000); // Forward spin for 1 second
      digitalWrite(spinF, LOW);
      digitalWrite(spinR, HIGH);
      Serial.println("Washing: reversed");
      delay(1000); // Reverse spin for 1 second
    }
    digitalWrite(spinR, LOW);
    washed = LOW;
  }

  // Drain sensor triggered
  if ((digitalRead(drainSensor) == LOW) && (washed == LOW)) 
  {
    digitalWrite(drain, HIGH);
    Serial.println("Draining water");
    delay(5000); // Simulate draining time
    digitalWrite(drain, LOW);
    drained = LOW;
  }

  // Drying sensor triggered
  if ((digitalRead(drySensor) == LOW) && (drained == LOW))
  {
    digitalWrite(dry, HIGH);
    Serial.println("Drying clothes");
    delay(5000); // Simulate drying time
    digitalWrite(dry, LOW);
    dried = LOW;
  }

  // Reset cycle
  if (dried == LOW) 
  {
    start = HIGH;
    watered = HIGH;
    washed = HIGH;
    drained = HIGH;
    dried = HIGH;
    Serial.println("Washing cycle complete. Ready for new cycle.");
  }
}
