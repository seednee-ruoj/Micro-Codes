 int led1 = 3; //one equal is assignment operator
 int sw1 = 10;
 int led2 = 4; 
 int sw2 = 11;
 int led3 = 5;
 
 void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(sw1,INPUT_PULLUP); //no pulldown resistor
  pinMode(led2, OUTPUT);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(sw1) == LOW) //two equals is comparison operator
    {
      digitalWrite(led1,HIGH);
      Serial.println(sw1);
      Serial.println("LED1 is ON");
    }

  if(digitalRead(sw1) == HIGH) //two equals is comparison operator
    {
      digitalWrite(led1,LOW);
      Serial.println(sw1);
      Serial.println("LED1 is OFF");
    }

  if(digitalRead(sw2) == LOW) //two equals is comparison operator
    {
      digitalWrite(led2,HIGH);
      Serial.println(sw2);
      Serial.println("LED2 is ON");
    }

  if(digitalRead(sw2) == HIGH) //two equals is comparison operator
    {
      digitalWrite(led2,LOW);
      Serial.println(sw2);
      Serial.println("LED2 is OFF");
    }

    if((digitalRead(sw1)== LOW)&& (digitalRead(sw2)== LOW))
      {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      delay(500);
      Serial.println(sw1);
      Serial.println("LED2 is BLINKING");  
      }
      
    if((digitalRead(sw1)== LOW)||(digitalRead(sw2)== LOW))
      {
       digitalWrite(led3,HIGH); 
      }

    else
      {
      digitalWrite(led3,LOW);
      }
}
