/*
 Commander une LED avec un bouton poussoir

 Allume une LED connectée sur la broche 8 et la faire clignoter
 lorsque l'on appuie sur un bouton poussoir connecté sur une broche en entrée.

 Le montage :
 * LED connectée entre la broche 8
 * Bouton poussoir entre la broche 7
*/

// Les constantes ne changent pas durant le programme.
// Utilisée ici pour définir le numéro de la broche :

const byte buttonPin = 7;     // crée un identifiant pour la broche utilisée avec le BP
const byte ledPin =  8;      // crée un identifiant pour la broche utilisée avec la LED
int buttonState = 0;
int n = 0;
void setup() {
  Serial.begin(9600);
  // configure la broche numérique en SORTIE
  pinMode(ledPin, OUTPUT);      
  // configure la broche numérique en ENTREE
  pinMode(buttonPin, INPUT);
}

void loop(){

  // lit la valeur de l'état du bouton et la mémorise dans la variable
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // Teste si le bouton est appuyé
  // c'est à dire si la variable buttonState est à 1
  if (buttonState == HIGH) {    
    // allume la LED 
    n ++; 
    transformation();  
  }
  if (n % 2 == 1){
    digitalWrite(ledPin, LOW);
  }
  else { // sinon
    // éteint la LED
    digitalWrite(ledPin, HIGH);
  }
}  
void transformation(){
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  
}
