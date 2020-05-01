#include <Ultrasonic.h>
int BSH;
int BSB;//déclaration des boutons
Ultrasonic ultrasonic(8);//déclaration de la broche capteur ultrason
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(7, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);//déclaration des broches entrée et sortie
  
}
void loop() {
  digitalWrite(3,HIGH);//activation pont en H
  BSH = digitalRead(4);//affectation de la valeur de la broche 4 à BSH
  while (BSH==1){//tant que bouton haut appuyé
  BSH = digitalRead(4);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);//faire tourner le moteur dans un sens
  }
  BSB = digitalRead(7);//affectation de la valeur de la broche 7 à BSB
  while (BSB==1){
  BSB = digitalRead(7);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);//faire tourner le moteur dans l'autre sens
  }
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);//ne pas faire tourner le moteur si aucuns bouton appuyé
}
  
    
