// Arduino Function calling

Servo Cover;
Servo Leg;
int CoverPos;
int LegPos;
int buttonExtend = 2;

bool retracted = HIGH;
bool extended = HIGH;

void setup() 
{
  Cover.attach(9);
  Leg.attach(10);
  pinMode(buttonExtend,INPUT_PULLUP);

}

void loop() 
// Data Set
{
 if((buttonExtend == LOW) && (retracted == HIGH ))
  {
    extendLandingGear(); 
  }
  
  if((buttonRetract == LOW) && (extended == HIGH ))
  {
    retractLandingGear(); 
  }
}

void extendLandingGear()
{
  if((buttonExtend == LOW) && (retracted == HIGH ))
  {
    // opening door //
    for(CoverPos = 0; CoverPos <= 180; CoverPos +=1)
    {
      Servo Cover.write(CoverPos);
      delay(15);
    }

    // extending landing gear //
    for(LegPos = 0; LegPos <= 180; LegPos +=1)
    {
      Servo Leg.write(LegPos);
      delay(15);
    }

    // closing door //
    for(CoverPos = 180; COverPos >= 0; CoverPos -=1)
    {
      Servo Cover.write(CoverPos);
      delay(15);
    }

    retracted = LOW;
}

void retractLandingGear()
{
  
}
  

  
}
