/*

  blink3led1

*/


#define led_red 13
#define led_yellow 12
#define led_green 11

void setup() {

  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);

}


void loop() {

  digitalWrite(led_red, HIGH);
  delay(1000);                       
  digitalWrite(led_red, LOW);    

  digitalWrite(led_yellow, HIGH);
  delay(1000);                       
  digitalWrite(led_yellow, LOW);    
  
  digitalWrite(led_green, HIGH);
  delay(1000);                       
  digitalWrite(led_green, LOW);       

}