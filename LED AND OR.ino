 int ledg = 3; //one equal is assignment operator
 int sw1 = 10;
 int ledy = 5; 
 int sw2 = 11;
 int ledo = 6;
 int ledb = 7;
 
 void setup() 
{
  pinMode(ledg, OUTPUT);
  pinMode(sw1,INPUT_PULLUP); //no pulldown resistor
  pinMode(ledy, OUTPUT);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(ledo, OUTPUT);
  pinMode(ledb, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{

  if(digitalRead(sw2) == LOW)
    {
      digitalWrite(ledg,HIGH);
    }
  
  if(digitalRead(sw1)== LOW)
      {
      digitalWrite(ledo,HIGH);
      delay(400);
      digitalWrite(ledo,LOW);
      digitalWrite(ledb,HIGH);
      delay(400);
      digitalWrite(ledb,LOW);
      Serial.println(sw1);
      Serial.println("ORANGE AND BLUE ARE BLINKING"); 
      }

   if((digitalRead(sw1)== HIGH)||(digitalRead(sw2)== HIGH))
      {
       digitalWrite(ledy,HIGH); 
      }

}
