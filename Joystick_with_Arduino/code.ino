/* Written by Electrocircuit */
/*
 *Website :- www.electrocircuit.net 
 */
 
#define LEFT_LED  8
#define RIGHT_LED  9
#define UP_LED  10
#define DOWN_LED  11

void setup() 
{
  Serial.begin(9600);
  pinMode(LEFT_LED,OUTPUT);
  pinMode(RIGHT_LED,OUTPUT);
  pinMode(UP_LED,OUTPUT);  
  pinMode(DOWN_LED,OUTPUT); 
}
  
void loop()
{
    
  int x= analogRead(A0);
  int y= analogRead(A1);
  
  x = map(x, 0, 1023, 0, 11);
  y = map(y, 0, 1023, 0, 11);

  Serial.print("X= ");
  Serial.print(x);
  Serial.print(" : ");
  Serial.print("Y= ");
  Serial.print(y);
  Serial.println();

  if(x==0 && y==5)
  {
    digitalWrite(LEFT_LED,HIGH);
    Serial.println("LEFT_LED");
    
    digitalWrite(RIGHT_LED,LOW);
    digitalWrite(UP_LED,LOW);
    digitalWrite(DOWN_LED,LOW);
  }
  else if(x==10 && y==5)
  {
    digitalWrite(RIGHT_LED,HIGH);
    Serial.println("RIGHT_LED");
    
    digitalWrite(LEFT_LED,LOW);
    digitalWrite(UP_LED,LOW);
    digitalWrite(DOWN_LED,LOW);
  }
   else if(x==5 && y==10)
  {
    digitalWrite(UP_LED,HIGH);
    Serial.println("UP_LED");
    
    digitalWrite(RIGHT_LED,LOW);
    digitalWrite(LEFT_LED,LOW);
    digitalWrite(DOWN_LED,LOW);
  }
   else if(x==5 && y==0)
  {
    digitalWrite(DOWN_LED,HIGH);
    Serial.println("DOWN_LED");
    
    digitalWrite(RIGHT_LED,LOW);
    digitalWrite(UP_LED,LOW);
    digitalWrite(LEFT_LED,LOW);
  }

  delay(100);
}
