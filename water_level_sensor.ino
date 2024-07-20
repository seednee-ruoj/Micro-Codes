int led1 = 2;
int led2 = 3;
int led3 = 4; 
int buzz = 5;
int waterLevel = A0;
int sensorValue = 0;

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  sensorValue = analogRead(waterLevel);
  Serial.print(" The water level is  ");
  Serial.println(sensorValue);
  delay(1000);
  
  if((sensorValue>=5)&&(sensorValue<=350))
    {
    digitalWrite(led1,HIGH);
    delay(100);
    }
  else if((sensorValue>=351)&&(sensorValue<=550))
    {
   digitalWrite(led2,HIGH);
   delay(100);
    }  
  else if(sensorValue>=551)
    {
    digitalWrite(led3,HIGH);
    digitalWrite(buzz,HIGH);
    delay(1);
    }
  else
    {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(buzz,LOW);
    delay(1);
    }
}
