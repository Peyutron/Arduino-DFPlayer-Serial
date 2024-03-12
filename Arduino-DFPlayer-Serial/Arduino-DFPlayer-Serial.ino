#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int vol = 10; // Volumen Inicial

void setup () {
  Serial.begin (9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial); //set softwareSerial is DFPlayer-mini mp3 module
  delay(10); // delay 1ms to set volume
  mp3_reset();
  delay(1000);
  mp3_set_volume (vol); // Valor de 0 ~ 30
  delay(10);
}

void loop () {
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {

      case 'P':     // Reproduccion
        mp3_play();
        delay(10);
        Serial.println("Reproduciendo");
        break;

      case 'S':     //Parar
        mp3_stop();
        delay(100);
        Serial.println("Parado");
        break;

      case  'N':    //Pista siguiente
        mp3_next();
        delay(10);
        Serial.println("Pista siguiente");
        break;

      case 'F':     //Pista anterior
        mp3_prev();
        delay(10);
        Serial.println("Pista anterior");
        break;

      case '+':     //Subir volumen
        vol = vol + 1;
        if  (vol >= 30) vol = 30;
        mp3_set_volume (vol) ;
        Serial.print("Nivel de volumen: ");
        Serial.println(vol);
        break;

      case '-':     //Bajar volumen
        vol = vol - 1;
        if  (vol  <= 0) vol  = 0;
        mp3_set_volume (vol) ;
        Serial.print("Nivel de volumen: ");
        
        Serial.println(vol);
        break;
    }
  }
}
