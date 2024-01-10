#include <SCServo.h>

#define POS_HORIZONTALE_GAUCHE_1 1000
#define POS_HORIZONTALE_DROITE_1 150
#define POS_VERTICALE_1 580

#define POS_HORIZONTALE_GAUCHE_2 900
#define POS_HORIZONTALE_DROITE_2 50
#define POS_VERTICALE_2 450

#define POS_HORIZONTALE_GAUCHE_3 850
#define POS_HORIZONTALE_DROITE_3 0
#define POS_VERTICALE_3 425

#define POS_HORIZONTALE_GAUCHE_4 4000
#define POS_HORIZONTALE_DROITE_4 450
#define POS_VERTICALE_4 580

#define FERMER 1000
#define OUVERT 0

#define postest1 500
#define postest2 700

int pin_7 = 7;
int pin_8 = 8;

SCSCL sc;

byte ID[5];
u16 Position[4];
u16 Speed[5];
byte IDS[4];
u16 Speeds[4];



void setup()

{

  Serial.begin(1000000);
  sc.pSerial = &Serial;
  delay(1000);
  while (!Serial) {}

  pinMode(pin_7, OUTPUT);
  pinMode(pin_8, INPUT);

  Init_IDS();

  Init_Speeds();



}




void loop() {

  

  pulse();


  
}






void Init_IDS() {
  IDS[0] = 1;
  IDS[1] = 2;
  IDS[2] = 3;
  IDS[3] = 4;
}

void Init_Speeds() {
  Speeds[0] = 50;
  Speeds[1] = 50;
  Speeds[2] = 50;
  Speeds[3] = 50;
}

void Init_ID() {
  ID[0] = 1;
  ID[1] = 2;
  ID[2] = 3;
  ID[3] = 4;
  ID[4] = 5;
}

void Init_Speed() {
  Speed[0] = 50;
  Speed[1] = 50;
  Speed[2] = 50;
  Speed[3] = 50;
  Speed[4] = 50;
}

void Init_Position(int Pos1, int Pos2, int Pos3, int Pos4) {

  Position[0] = Pos1;
  Position[1] = Pos2;
  Position[2] = Pos3;
  Position[3] = Pos4;
}

void position_initiale() {

  Init_Position(750, 20, 800, 1000);

  sc.SyncWritePos(IDS, 4, Position, 0, Speeds);
  delay(754);

  delay(3000);

  
}


void saisir_objet() {

  Init_Position(600, 20, 800, 1000);

  sc.SyncWritePos(IDS, 4, Position, 0, Speeds);
  delay(754);

  delay(3000);
 

  sc.WritePos(5, 1000, 0, 200);
  delay(754);
}


void lacher_objet() {

  Init_Position(600, 20, 800, 1000);

  sc.SyncWritePos(IDS, 4, Position, 0, Speeds);
  delay(754);

  delay(3000);
  

  sc.WritePos(5, OUVERT, 0, 200);
  delay(754);
}


void test_position() {

  sc.WritePos(1, 580, 0, 500);  // 580 corresdpond à la position verticale
  delay(754);
}



void pulse() {
  int state = digitalRead(pin_8);

  sc.WritePos(5, OUVERT, 0,100);

  if (state == HIGH) {

    digitalWrite(pin_7, LOW);
    delay(50);

    position_initiale();
    delay(754);

    delay(3000);
    

    saisir_objet();
    delay(754);

    delay(3000);

    position_initiale();
    delay(754);

    delay(5000);

    digitalWrite(pin_7, HIGH);
    delay(4000);

    digitalWrite(pin_7, LOW);
    delay(50);

    lacher_objet();
    delay(754);
    
    delay(3000);

    position_initiale();
    delay(754);

    digitalWrite(pin_7, HIGH);
    delay(50);
  }
}
