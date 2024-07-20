// DIGITAL POTENTIOMETER
//amplifier - below saturation; switch - in saturation

int swUp = 2;
int swDown = 3;
int led = 5; //pwm
int brightness = 0;


void setup() 
{
  pinMode(swUp,INPUT_PULLUP);
  pinMode(swDown, INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  if(digitalRead(swUp) == LOW)
  {
    brightness = brightness + 1 ;
    Serial.print("The brightness is ");
    Serial.println(brightness);
    delay(10);
  }

  if(digitalRead(swDown) == LOW)
  {
    brightness = brightness - 1 ;
    Serial.print("The brightness is ");
    Serial.println(brightness);
    delay(10);
  }

  analogWrite(led, brightness);
}
