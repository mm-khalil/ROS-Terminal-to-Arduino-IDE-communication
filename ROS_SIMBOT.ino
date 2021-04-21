
#include <ros.h>


//------------- SIMBOT ------------------------
// PWM Pins for
int R_PWM = 10;
int L_PWM = 9;

//  Motor Direction Pins
int R_direction = 5;
int L_direction = 6;

#define Forward 1
#define Reverse 0


// Left Speed
int CCW_R = 180;        // Forward (max 0 - min 255)
int CCW_L = 40;         // Reverse (max 255 - min 0)
// Left Speed
int CW_R = 40;          // Forward (max 0 - min 255)
int CW_L = 180;         // Reverse (max 255 - min 0)
//wheel speeds (Forward/Reverse)
int right_speed = 40;
int left_speed  = 40;



void setup() 
{       
        Serial.begin (9600);

 
}

void loop() 
{
   if(Serial.available() > 0)  
   {   char Incoming_value = Serial.read();
   
       Serial.print("Incoming_value = ");     
       Serial.println(Incoming_value);     
       if(Incoming_value == 'F')            
       {    forward();
            delay(1000);     }      
       else if(Incoming_value == 'R')      
       {    reverse();
            delay(1000);     }
       else if(Incoming_value == 'L')      
       {    turn_left();
            delay(1000);     }
       else if(Incoming_value == 'r')      
       {    turn_right();
            delay(1000);     }
       else if(Incoming_value == 'S')      
       {    stop_SIMBOT();   }
                   
   } 
              
              
}

void forward() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Forward);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Forward);     
}

void reverse() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Reverse);     
}

void stop_SIMBOT() 
{
        analogWrite(R_PWM, 0);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, 0);
        digitalWrite(L_direction, Reverse);     
}

void turn_right() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Forward); 
}

void turn_left() 
{   
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Forward);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Reverse);
}
