
#include <PID_v1.h>
#define PIN_OUTPUT 3//Pin 3 PWM 

double Setpoint, Input, Output;

double Kp=.836, Ki=.0121, Kd=0;//Valores PID obtenidos con MATLAB para nuestro sistema.
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

volatile int contador = 0;   // Variable entera que se almacena en la RAM del Micro
 
void setup() {
  Serial.begin(57600);
  Setpoint = 1000;//Valor RPM 
  myPID.SetMode(AUTOMATIC);
  attachInterrupt(0,interrupcion0,RISING);  // Interrupcion 0 (pin2) 
}            
 
void loop() {
  delay(499); 
  Input = contador*6;
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);  
  contador = 0;
}
 
void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{
  contador++;           // Se incrementa en uno el contador
}
