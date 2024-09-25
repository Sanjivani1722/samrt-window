
#include <AFMotor.h>

AF_DCMotor motor(4);

void setup() {

  Serial.begin(9600);//enable serial monitor
  motor.setSpeed(50);
    motor.run(RELEASE);
}
void loop() {
  uint8_t i;
  int value = analogRead(A3);//read value
  Serial.print("Value : ");
  Serial.println(value);
  if (value <= 500) {//check condition
    // Turn on motor
    for(i=1;i<=5;i++)
    {
    motor.run(FORWARD);
    }
    // Accelerate from zero to maximum speed
    for (i=0; i<255; i++) 
    {
        motor.setSpeed(i);  
        delay(10);
    }
  for (i=255; i!=0; i--) 
    {
        motor.setSpeed(i);  
        delay(10);
    }
    Serial.print("Heavy rain  LED on ");
  delay(10000);
    
  } 
  else {
    motor.run(BACKWARD);
    
    // Accelerate from zero to maximum speed
    for (i=0; i<255; i++) 
    {
        motor.setSpeed(i);  
        delay(10);
    }

    // Decelerate from maximum speed to zero
    for (i=255; i!=0; i--) 
    {
        motor.setSpeed(i);  
        delay(10);
    }

    // Now turn off motor
    motor.run(RELEASE);
  delay(10);
  
  }
  delay(10000);
}


