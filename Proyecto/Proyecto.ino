
#include <PID_v1.h>
#define PIN_OUTPUT 3

double Setpoint, Input, Output;

double Kp=.836, Ki=.0121, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

volatile int contador = 0;   // Variable entera que se almacena en la RAM del Micro
 
void setup() {
  Serial.begin(57600);
 // Input = analogRead(0);
  Setpoint = 1000;
  myPID.SetMode(AUTOMATIC);
  attachInterrupt(0,interrupcion0,RISING);  // Interrupcion 0 (pin2) 
}                                          // LOW, CHANGE, RISING, FALLING
 
void loop() {
  delay(499); 
  Input = contador*6;
  Serial.print(Input); 
  Serial.println(" RPM");
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);  
//  Serial.print(Input); 
 // Serial.println(" RPM");  
  contador = 0;
}
 
void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{
  contador++;           // Se incrementa en uno el contador
}
