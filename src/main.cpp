#include <Arduino.h>
// #include <ArrayList.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MCP23X17.h>
#include <Note.h>
#include <Music.h>
#include <ServoNote.h>
#include <ServoPluck.h>


const int TEMPO = 1000;

bool isFirstStringBeingUsed = false;
bool isSecondStringBeingUsed = false;
bool isThirdStringBeingUsed = false;

Adafruit_MCP23X17 mcp;
Adafruit_MCP23X17 mcp1;


ServoNote servoNotes[12][3];

ServoPluck servoPluck[3] = {ServoPluck(1), ServoPluck(2), ServoPluck(3)};

void initializeServoNotes() {
  int notes[13] = {'E','F','G', 'G#', 'A', 'A#', 'B', 'B#', 'C', 'C#', 'D', 'D#', 'EH'};

  int portCount = 1;
  int noteCount = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 3; j++) {
        servoNotes[i][j] = ServoNote(portCount, notes[noteCount]);
        portCount = portCount + 1;
      }
      noteCount = noteCount + 1;
  }
}


void playNote(int note) {
  int stringOffset = 0;
  stringOffset = isFirstStringBeingUsed ? stringOffset + 1 : stringOffset;
  stringOffset = isSecondStringBeingUsed ? stringOffset + 2 : stringOffset;

  switch (note)
  {
  case 'E':
    break;
  case 'F':
    servoNotes[1][0 + stringOffset].bringServoDown();
    break;
  case 'G':
    servoNotes[2][0 + stringOffset].bringServoDown();
    break;
  case 'G#':
    servoNotes[3][0 + stringOffset].bringServoDown();
    break;
  case 'A':
    servoNotes[4][0 + stringOffset].bringServoDown();
    break;
  case 'A#':
    servoNotes[5][0 + stringOffset].bringServoDown();
    break;
  case 'B':
    servoNotes[6][0 + stringOffset].bringServoDown();
    break;
  case 'B#':
    servoNotes[7][0 + stringOffset].bringServoDown();
    break;
  case 'C':
    servoNotes[8][0 + stringOffset].bringServoDown();
    break;
  case 'C#':
    servoNotes[9][0 + stringOffset].bringServoDown();
    break;
  case 'D':
    servoNotes[10][0 + stringOffset].bringServoDown();
    break;
  case 'D#':
    servoNotes[11][0 + stringOffset].bringServoDown();
    break;
  case 'EH':
    servoNotes[12][0 + stringOffset].bringServoDown();
    break;
  }
  
  if (isFirstStringBeingUsed) {servoPluck[1].pluckString(); }
  if (isSecondStringBeingUsed) {servoPluck[2].pluckString(); }
  if (isThirdStringBeingUsed) {servoPluck[3].pluckString(); }
}

void reset() { //If it becomes a performance issue than only bring it up if there is an active servo on that string
  isFirstStringBeingUsed = false;
  isSecondStringBeingUsed = false;
  isThirdStringBeingUsed = false;
  for (int i = 0; i < 12; i++)
    for (int j = 0; j < 3; i++)
      servoNotes[i][j].bringServoUp(); // lazy solution for now
}

void playSong(Note song[])
{
  int noteBeingPlayed = 0;
  int noteChange = 0;
  reset();
  delay(song[noteBeingPlayed].getTiming());
  isFirstStringBeingUsed = true;
  playNote(song[noteBeingPlayed].getType());
  noteChange = 1;
  if (song[noteBeingPlayed].getIsPaired())
  {
    isSecondStringBeingUsed = true;
    playNote(song[noteBeingPlayed + 1].getType());
    noteChange = 2;
    if (song[noteBeingPlayed + 1].getIsPaired())
    {
      isThirdStringBeingUsed = true;
      playNote(song[noteBeingPlayed + 2].getType()); // lazy solution fix later if feel like it ig but like rest of the code sucks anyway
      noteChange = 3;
    }
  }
  noteBeingPlayed += noteChange;
}

Music music;

void setup() {

  Servo servo;
  Serial.begin(9600);
  initializeServoNotes();
}

void loop() {
  
  playSong(music.getTwinkleTwinkleLittleStar());
}
