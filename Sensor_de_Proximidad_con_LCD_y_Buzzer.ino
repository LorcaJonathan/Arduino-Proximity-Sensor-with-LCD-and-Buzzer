
#include <LiquidCrystal.h>

#define Trigger 13 //Trigger en el pin 13
#define Echo 12 // Echo en el pin 12

#define max_distancia 200
#define min_distancia 10

int buzzer_Pin = 9; 

LiquidCrystal lcd(7,6,5,4,3,2); //Pines donde conectamos los datos, RS y E

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2); //Indicamos que es una pantalla lcd 16x2

  pinMode(Trigger, OUTPUT); //Definimos el pin trigger como salida
  pinMode(Echo, INPUT); //Definimos el pin Echo como entrada
  digitalWrite(Trigger, LOW); //Inicializamos el pin con el valor 0

  pinMode(buzzer_Pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  long t; //Tiempo que demora en llegar el echo del ultrasonido
  long d; //Distancia en centimetros

  digitalWrite(Trigger, HIGH); //Mandamos un pulso a Trigger
  delayMicroseconds(10);
  
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); //Encontramos el ancho del pulso 
  d= t/59; //Hacemos la relacion de la distancia en cm segun el tiempo

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia");
  
  lcd.setCursor(0,1);
  lcd.print(d);
  lcd.print("cm");
  delay(350);

  if (d < min_distancia) {
    tone(buzzer_Pin, 2500);
  }
  else {
    noTone(buzzer_Pin);
  }

}
