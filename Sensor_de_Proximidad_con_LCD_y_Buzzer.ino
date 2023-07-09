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

  lcd.clear(); //Limpia la pantalla
  lcd.setCursor(0,0); //Establece el cursor en la posición de la columna 0 y fila 0
  lcd.print("Distancia"); //Escribe el texto Distancia
  
  lcd.setCursor(0,1); //Establece el cursor en la posición de la columna 0 y fila 1
  lcd.print(d); // Escribe el valor de la distancia 
  lcd.print("cm"); //Imprime el texto "cm" en la pantalla LCD
  delay(350); //espera 350 milisegundos

  if (d < min_distancia) {
    tone(buzzer_Pin, 2500); //Pita el buzzer a una frecuencia de 2500Hz si la condicion se cumple
  }
  else {
    noTone(buzzer_Pin); //El buzzer deja de pitar si la condicion no se cumple
  }

}
