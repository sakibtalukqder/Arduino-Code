

int IrPin = 11;
int LedTrue = 13;
int LedFalse = 12;

void setup()
{
  pinMode(LedTrue,OUTPUT);
  pinMode(LedFalse,OUTPUT);
  pinMode(IrPin,INPUT);
}

void loop()
{
  int Status = digitalRead(IrPin);
  if(Status == 1){
    digitalWrite(LedTrue,HIGH);
    digitalWrite(LedFalse,LOW);
  }
  else{
    digitalWrite(LedFalse,HIGH);
    digitalWrite(LedTrue,LOW);
  }
  
}
