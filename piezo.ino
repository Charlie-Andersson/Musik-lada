
#include "pitches.h"

#define BUZZER_PIN1 7
#define BUZZER_PIN2 8

int cantina[] = {
  NOTE_B4, -4, NOTE_E5, -4, NOTE_B4, -4, NOTE_E5, -4,
  NOTE_B4, 8,  NOTE_E5, -4, NOTE_B4, 8, 0, 8,  NOTE_AS4, 8, NOTE_B4, 8,
  NOTE_B4, 8,  NOTE_AS4, 8, NOTE_B4, 8, NOTE_A4, 8, 0, 8, NOTE_GS4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_G4, 4,  NOTE_E4, -2,
  NOTE_B4, -4, NOTE_E5, -4, NOTE_B4, -4, NOTE_E5, -4,
  NOTE_B4, 8,  NOTE_E5, -4, NOTE_B4, 8, 0, 8,  NOTE_AS4, 8, NOTE_B4, 8,

  NOTE_A4, -4, NOTE_A4, -4, NOTE_GS4, 8, NOTE_A4, -4,
  NOTE_D5, 8,  NOTE_C5, -4, NOTE_B4, -4, NOTE_A4, -4,
  NOTE_B4, -4, NOTE_E5, -4, NOTE_B4, -4, NOTE_E5, -4,
  NOTE_B4, 8,  NOTE_E5, -4, NOTE_B4, 8, 0, 8,  NOTE_AS4, 8, NOTE_B4, 8,
  NOTE_D5, 4, NOTE_D5, -4, NOTE_B4, 8, NOTE_A4, -4,
  NOTE_G4, -4, NOTE_E4, -2,
  NOTE_E4, 2, NOTE_G4, 2,
  NOTE_B4, 2, NOTE_D5, 2,

  NOTE_F5, -4, NOTE_E5, -4, NOTE_AS4, 8, NOTE_AS4, 8, NOTE_B4, 4, NOTE_G4, 4,

};

int starTheme[] = {
  
  
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, 0,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
  
};

int tempo = 108;

int notes = sizeof(cantina) / sizeof(cantina[0]) / 2;

int wholenote = (60000 * 2) / tempo;

int divider = 0; 

int noteDuration = 0;

int notes2 = sizeof(starTheme) / sizeof(starTheme[0]) / 2;

int wholenote2 = (60000 * 4) / tempo;

int divider2 = 0;

int noteDuration2 = 0;

void setup() {
  Serial.begin(9600);


  pinMode(2, INPUT);
  pinMode(3, INPUT);


}

void loop() {




  if (digitalRead(2) == 1) {
    Serial.println("Now playing: Cantina - Star Wars");

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

      divider = cantina[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; 
      }

      tone(2, cantina[thisNote], noteDuration * 0.9);

      delay(noteDuration);

      noTone(2);
    }
  }


  if (digitalRead(3) == 1) {

    Serial.println("Now playing: SONG2");


     for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider2 = starTheme[thisNote + 1];
    if (divider2 > 0) {
      noteDuration2 = (wholenote2) / divider2;
    } else if (divider2 < 0) {
      noteDuration2 = (wholenote2) / abs(divider2);
      noteDuration2 *= 1.5;
    }

    tone(3, starTheme[thisNote], noteDuration*0.9);

    delay(noteDuration2);
    
    noTone(3);
    }
  }

  if ((digitalRead(2) != 1) || (digitalRead(3) != 1)); {
    Serial.println("No Song Playing");


  }
}
