//Programmation retroviseur projet de terminal ECS.
//LEBERRE,SCHUlER,RICHERME,ROBINEAU

#include <Servo.h>
boolean bouton_haut;
boolean bouton_bas;
boolean bouton_droite;
boolean bouton_gauche;//declaration des variables des boutons de reglage
boolean memorisation;//declaration bouton de memorisation des reglages
boolean automatique;//deaclaration bouton reglage automatique
Servo Servo_vertical;
Servo Servo_horizontal;//declaration des servomoteurs
int position_verticale;
int positionV_enregistree;
int rotation_autoV;
int position_horizontale;
int positionH_enregistree;
int rotation_autoH;//declaration des variables de position

void setup() {
Serial.begin(9600);//initialisation de l'horloge serie à 9600
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);//declaration des broches entrees et sorties
  Servo_vertical.attach(6);
  Servo_horizontal.attach(7);//affectation des broches aux servomoteurs
  position_verticale = 90;
  positionV_enregistree = 90;
  position_horizontale = 90;
  positionH_enregistree = 90;//initialisation des variables de position à 0
  Servo_vertical.write(position_verticale);
  Servo_horizontal.write(position_horizontale);
}

void loop() {
  bouton_droite = digitalRead(4);//lecture valeur bouton_droite sur broche 4
  Serial.print(bouton_droite);
  if ((bouton_droite==1)&&(position_horizontale<(145))) {//si bouton_droite appuye et position max non atteinte
    position_horizontale++;//incrementer position_horizontale
    Servo_horizontal.write(position_horizontale);//mettre servomoteur vertical à la position "position_horizontale"
    bouton_droite = digitalRead(4);
  }
  bouton_gauche = digitalRead(5);//lecture valeur bouton_gauche sur broche 5
   Serial.print(bouton_gauche);
  if ((bouton_gauche==1)&&(position_horizontale>(1))) {//si bouton RH appuye et position min non atteinte
    position_horizontale=position_horizontale-1;//incrementer position_horizontale
    Servo_horizontal.write(position_horizontale);//mettre servomoteur vertical à la position "position_horizontale"
    bouton_gauche = digitalRead(5);
  }
   delay(10);//attente pour reguler la vistesse de rotation
   bouton_haut = digitalRead(2);//lecture valeur bouton_haut sur broche 2
 Serial.print(bouton_haut);
  if ((bouton_haut==1)&&(position_verticale<155)) {//si bouton_haut appuye et position max non atteinte
    position_verticale++;//incrementer position_verticale
    Servo_vertical.write(position_verticale);//mettre servomoteur vertical à la position "position_verticale"
    bouton_haut = digitalRead(2);
  } 
  bouton_bas = digitalRead(3);//lecture valeur bouton sur broche 3
  if ((bouton_bas==1)&&(position_verticale>1)) {//si bouton retro_bas appuye et position min non atteinte
    position_verticale--;//decrementer position_verticale
    Servo_vertical.write(position_verticale);//mettre servomoteur vertical à la position "position_verticale"
    bouton_bas = digitalRead(3);
  }
  delay(10);//attente pour reguler la vistesse de rotation (94-45)
  
   memorisation = digitalRead(8);
   if (memorisation==1) {
    positionV_enregistree = position_verticale;
    positionH_enregistree = position_horizontale;
    memorisation = digitalRead(8);
   }
   automatique = digitalRead(9);
   if (automatique==1) {
    Servo_vertical.write(positionV_enregistree);
    position_verticale = positionV_enregistree;
    Servo_horizontal.write(positionH_enregistree);
    position_horizontale = positionH_enregistree ;
    rotation_autoV = abs(positionV_enregistree-position_verticale);
    rotation_autoH = abs(positionH_enregistree-position_horizontale);
      if (rotation_autoV>rotation_autoH) {
      delay((rotation_autoV*720)/360);
    }
    else {
      delay((rotation_autoH*720)/360);
    }
  automatique = digitalRead(9);
  }
}
