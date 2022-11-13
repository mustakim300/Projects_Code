/* Title :- LED control through IR remote using Arduino.
 * For more information visit :- www.electrocircuit.com
 */

#include <IRremote.h>
#define first_key 2295
#define second_key 34935
#define third_key 18615
int receiver_pin = 8;

int first_led_pin = 6;
int second_led_pin = 5;
int third_led_pin = 4;
int led[] = {0,0,0,0};
IRrecv receiver(receiver_pin);
decode_results output;

void setup()
{
Serial.begin(9600);
receiver.enableIRIn();
pinMode(first_led_pin, OUTPUT);
pinMode(second_led_pin, OUTPUT);
pinMode(third_led_pin, OUTPUT);
}

void loop() {
if (receiver.decode(&output)) {
unsigned int value = output.value;
switch(value) {
case first_key:
if(led[1] == 1) 
{
digitalWrite(first_led_pin, LOW);
Serial.print("LED1 OFF  IR_CODE :-");
Serial.println(value);
  
led[1] = 0;
} else {
digitalWrite(first_led_pin, HIGH);
Serial.print("LED1 ON  IR_CODE :-");
Serial.println(value);
led[1] = 1;
}
break;
case second_key:

if(led[2] == 1) {
digitalWrite(second_led_pin, LOW);
Serial.print("LED2 OFF  IR_CODE :-");
Serial.println(value);
led[2] = 0;
} else {
digitalWrite(second_led_pin, HIGH);
Serial.print("LED2 ON  IR_CODE :-");
Serial.println(value);
led[2] = 1;
}
break;
case third_key:

if(led[3] == 1) {
digitalWrite(third_led_pin, LOW);
Serial.print("LED3 OFF  IR_CODE :-");
Serial.println(value);
led[3] = 0;
} else {
digitalWrite(third_led_pin, HIGH);
Serial.print("LED3 ON  IR_CODE :-");
Serial.println(value);
led[3] = 1;
}
break;
}
receiver.resume();
}
}
