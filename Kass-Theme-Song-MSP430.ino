/* 
 *  Toby Chow
 *  3/30/20
 *  Kass-Theme-Song-MSP430
 */
 
#include "pitches.h"

// FILL THESE TWO NUMBERS IN
const double bpm = 170.0; // supply this number
const double beat_unit = 4.0; // the lower number in time signature


int treble[] = {
  NOTE_E3, NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_C4, NOTE_B3, NOTE_F3, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_B3, NOTE_A3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_AS3, NOTE_A3, NOTE_GS3, NOTE_A3, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4};

// note durations: 1.0/4.0 = quarter note, 1.0/8.0 = eighth note, 3.0/8.0 = quarter eigth note, etc
double noteType[] = {1.0/4.0, 1.0/16.0 , 1.0/16.0, 1.0/16.0, 1.0/16.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/16.0, 1.0/16.0, 1.0/16.0, 1.0/16.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/16.0, 1.0/16.0, 1.0/16.0, 1.0/16.0, 1.0/4.0, 3.0/8.0, 1.0/8.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};

double length_of_one_beat = 1.0/(bpm/60.0); // second(s)

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(treble)/2; i++) {
    tone(P8_6, treble[i], (noteType[i]*beat_unit)*length_of_one_beat*1000.0);

    // delay between each note
    double play_delay = (noteType[i]*beat_unit)*length_of_one_beat*1000.0;
    Serial.println(noteType[i], 4);
    
    delay(play_delay);
  }
}
void loop() {
  // no need to repeat the melody.
}
