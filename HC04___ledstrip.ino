#include <Adafruit_NeoPixel.h>                // appel de la bibliothèque 
#define sortie 2                                //  Défini le pin de l'arduino sur lequel est branché la bande de led
#define nb_led 6                                //    Défini le nombre de led voulu sur la bande branché                        
#define PIN_TRIG  8                              // Défini le pin de l'arduino sur lequel est branché la broche Trig du module HC-04
#define PIN_ECHO  9                              // Défini le pin de l'arduino sur lequel est branché la broche Echo du module HC-04

Adafruit_NeoPixel module = Adafruit_NeoPixel(nb_led, sortie, NEO_GRB + NEO_KHZ800);  // création de l'objet module à utiliser pour controler la bande

long duration_hc, distance_hc;

void setup() {
  Serial.begin (9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  module.begin();  
 
}

void loop() {

  mesureDistance();
  Serial.print("Distance ");
  Serial.print(distance_hc);
  Serial.println(" Cm ");

  if(distance_hc > 50){
    Vert();
 
  }

  else{
  Rouge();
  }

}

void Vert(){ // Fonction crée pour afficher Rouge
  for(int i=0;i<7;i++)  // Premier Led
  {
    module.setPixelColor(i,0,255,0);  //(i,Rouge,Vert,Bleu)
    module.setBrightness(40);
    module.show(); 
    delay (100);
  }
}
void Rouge(){ // Fonction crée pour afficher Rouge
  for(int i=0;i<7;i++)  // Premier Led
  {
    module.setPixelColor(i,255,0,0);  //(i,Rouge,Vert,Bleu)
    module.show(); 
    delay (100);
  }
}
void mesureDistance(){
  digitalWrite(PIN_TRIG, LOW);  
  delayMicroseconds(2); 
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(PIN_TRIG, LOW);
  duration_hc = pulseIn(PIN_ECHO, HIGH);
  Serial.println(duration_hc);
  distance_hc = duration_hc / 58;
}
