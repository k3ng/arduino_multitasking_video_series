/*

  blink3led2

*/


#define led_red 13
#define led_yellow 12
#define led_green 11

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------


void setup() {

  initialize_pins();

}

//------------------------------------------------


void loop() {

  service_leds();

  do_this();

  do_that();
      
}

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------


void initialize_pins(){

  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);

  digitalWrite(led_red, HIGH);

}

//------------------------------------------------


void service_leds(){

  static byte current_led_on = led_red;
  static unsigned long last_led_transition_time = 0;

  if ((millis() - last_led_transition_time) >= 1000){

    switch(current_led_on){
  
      case led_red:
        digitalWrite(led_red, LOW); 
        digitalWrite(led_yellow, HIGH);    
        current_led_on = led_yellow;
        break;

      case led_yellow:
        digitalWrite(led_yellow, LOW); 
        digitalWrite(led_green, HIGH);    
        current_led_on = led_green;
        break;        

      case led_green:
        digitalWrite(led_green, LOW); 
        digitalWrite(led_red, HIGH);    
        current_led_on = led_red;
        break;    

    }

    last_led_transition_time = millis();
  }

}

//------------------------------------------------


void do_this(){

}

//------------------------------------------------

void do_that(){

  
}