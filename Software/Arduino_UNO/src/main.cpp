#include <Arduino.h>
#include <Servo.h>


Servo srv;
int pin_servo_pwm = 5;
int servo_pos_1 = 0;
int servo_pos_2 = 90;

int pin_entradaBtn = 3;
int estadoBtn = 0;
int estadoBtn_anterior = 0;
int salida = 0;


void setup() 
{
  Serial.begin(115200);
  srv.attach(pin_servo_pwm);
  pinMode(pin_entradaBtn, INPUT);
  srv.write(servo_pos_1);
}

void loop() 
{
  estadoBtn = digitalRead(pin_entradaBtn);
  Serial.print("estadoBtn: "); Serial.print(estadoBtn); Serial.print(", ");
  
  if((estadoBtn == HIGH) && (estadoBtn_anterior == LOW)){
    salida = 1 - salida;
    delay(25);
  }
  estadoBtn_anterior = estadoBtn;

  if(salida == 1)
  {
    srv.write(servo_pos_2);
    Serial.println("Servo 90");
  }
  else
  {
    srv.write(servo_pos_1);
    Serial.println("Servo 0");
  }

  delay(20);
}