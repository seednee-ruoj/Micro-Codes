int pot = A0;
int led = 6;
int sw = 2;

void setup() 
{
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{

  if (digitalRead(sw) == LOW)
  {
      pot = analogRead(A0);
      int brightness = map(pot, 0, 1023, 0, 255);
      analogWrite(led, brightness);
      Serial.print("The brightness is ");
      Serial.println(analogRead(pot));
  }
  
  else
  {
      digitalWrite(led, LOW);
      Serial.println("The LED is turned off.");
  }
}
