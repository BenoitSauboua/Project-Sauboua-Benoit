// Code de l'émetteur 
// explications vidéo -> https://www.youtube.com/watch?v=bDY4I_TKO1U&ab_channel=tutorialmaker
#include "VirtualWire.h"
int butPressed1 ;
int butPressed2 ;
int butPressed3 ;

void setup() {
  vw_setup(2050);
  vw_set_tx_pin(2);

  pinMode(3, INPUT_PULLUP) ;
  pinMode(4, INPUT_PULLUP) ;
  pinMode(5, INPUT_PULLUP) ; 

}

void loop() {
  byte message[27];
  byte taille_message = 27;

butPressed1 = !digitalRead(1) ;
 
  if(butPressed1) {
      strcpy(message, "on1") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;
  }
  else {
      strcpy(message, "off1") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;    
  }


 butPressed2 = !digitalRead(4) ;
 
  if(butPressed2) {
      strcpy(message, "on2") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;
  }
  else {
      strcpy(message, "off2") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;    
  }


   butPressed3 = !digitalRead(5) ;
 
  if(butPressed3) {
      strcpy(message, "on3") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;
  }
  else {
      strcpy(message, "off3") ;
      vw_send(message, taille_message) ;
      vw_wait_tx() ;    
  }

}
