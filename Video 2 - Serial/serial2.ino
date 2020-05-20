/*

  serial2

*/


#define led_red 13
#define led_yellow 12
#define led_green 11

#define serial_port Serial
#define serial_port_baud_rate 115200

byte current_led_on = 0;

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------


void setup() {

  initialize_pins();
  initialize_serial();

}

//------------------------------------------------


void loop() {

  service_leds();
  service_serial_port();
      
}

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------


void initialize_pins(){

  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);

  digitalWrite(led_red, HIGH);
  current_led_on = led_red;

}

//------------------------------------------------


void service_leds(){

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


void initialize_serial(){

  serial_port.begin(serial_port_baud_rate);
  serial_port.println("Hi there!");

}

//------------------------------------------------

void service_serial_port(){

  char serial_incoming_byte = 0;
  static char serial_incoming_byte_buffer[32];
  static byte serial_incoming_byte_buffer_bytes = 0;

  if (serial_port.available()){
  
    serial_incoming_byte = serial_port.read();

    serial_port.print(serial_incoming_byte);

    if ((serial_incoming_byte != '\n') || (serial_incoming_byte != '\r')){

      if (serial_incoming_byte_buffer_bytes < 32){

        serial_incoming_byte = toupper(serial_incoming_byte);
        serial_incoming_byte_buffer[serial_incoming_byte_buffer_bytes] = serial_incoming_byte;
        serial_incoming_byte_buffer_bytes++;
        
      }

    }

    if ((serial_incoming_byte == '\n') || (serial_incoming_byte == '\r') || (serial_incoming_byte_buffer_bytes >= 32)){

      if ((serial_incoming_byte_buffer[0] == 'Q') 
        && (serial_incoming_byte_buffer[1] == 'U')
        && (serial_incoming_byte_buffer[2] == 'E')
        && (serial_incoming_byte_buffer[3] == 'R')
        && (serial_incoming_byte_buffer[4] == 'Y')){

        serial_port.print("\r\nThe ");

        switch(current_led_on){
          case led_red:
            serial_port.print("red");
            break;

          case led_yellow:
            serial_port.print("yellow");
            break;

          case led_green:
            serial_port.print("green");
            break;

        }

        serial_port.println(" led is on.");

      } else {

        serial_port.println("\r\nSyntax error.");

      }

      serial_incoming_byte_buffer_bytes = 0;

    }

  }

  
}