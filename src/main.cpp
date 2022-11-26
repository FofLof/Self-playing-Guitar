#include <Arduino.h>
// #include <ArrayList.h>
#include <Vector.h>
#include <Servo.h>
using namespace std;

const int TEMPO = 1000;
const int UP_DEGREES = 0;
const int DOWN_DEGREES = 0; //@TODO get correct values
const int LEFT_PLUCK_POSITION = 0;
const int RIGHT_PLUCK_POSITION = 0;

bool isFirstStringBeingUsed = false;
bool isSecondStringBeingUsed = false;
bool isThirdStringBeingUsed = false;

class Note
{
public:
  int timing;
  int type;
  bool isComplete = false;
  bool isPaired;

  // Note();
  Note(int time, int type, bool isPaired)
  {
    timing = time;
    this->type = type;
    this->isPaired = isPaired;
  }

  int getTiming() { return timing; }

  int getType() { return type; }

  bool getIsComplete() { return isComplete; }
  void setIsComplete(bool isComplete) { this->isComplete = isComplete; }
};

class ServoNote 
{
  public:
    int note;
    Servo servo;
    ServoNote() {
      note = 0;
    }
    ServoNote(int portNumber, int note) {
      this->note = note;
      servo.attach(portNumber);
    }
    
    void bringServoUp() {
      servo.write(UP_DEGREES);
    }

    void bringServoDown() {
      servo.write(DOWN_DEGREES);
    }

    int getNote() { return note;}
};

class ServoPluck 
{
  public:
    Servo servo;
    bool pluckState; 
    ServoPluck(int portNumber) {
      servo.attach(portNumber);
    }
    void pluckString(){
      if (pluckState) {
        servo.write(LEFT_PLUCK_POSITION);
      } else {
        servo.write(RIGHT_PLUCK_POSITION);
      }
      pluckState = !pluckState;
    }
};

ServoNote servoNotes[12][3];

// ServoNote* servoNotes[12][3] = {
//   {new ServoNote(1, 'A'), new ServoNote(2, 'A'), new ServoNote(3, 'A')},
//   {new ServoNote(4, 'B#'), new ServoNote(5, 'B#'), new ServoNote(6, 'B#')},
//   {new ServoNote(7, 'B'), new ServoNote(8, 'B'), new ServoNote(9, 'B')},
//   {new ServoNote(10, 'C'), new ServoNote(11, 'C'), new ServoNote(12, 'C')},
//   {new ServoNote(13, 'D#'), new ServoNote(14, 'D#'), new ServoNote(15, 'D#')},
//   {new ServoNote(16, 'D'), new ServoNote(19, 'D'), new ServoNote(21, 'D')},
//   {new ServoNote(22, 'E#'), new ServoNote(23, 'E#'), new ServoNote(24, 'E#')},
//   {new ServoNote(22, 'E'), new ServoNote(23, 'E'), new ServoNote(24, 'E')},
//   {new ServoNote(25, 'F'), new ServoNote(26, 'F'), new ServoNote(27, 'F')},
//   {new ServoNote(28, 'G#'), new ServoNote(29, 'G#'), new ServoNote(27, 'G#')},
//   {new ServoNote(28, 'G'), new ServoNote(29, 'G'), new ServoNote(27, 'G')},
//   {new ServoNote(28, 'A#'), new ServoNote(29, 'A#'), new ServoNote(27, 'A#')}
// };

Note twinkleTwinkleLittleStar[] = {
    Note(250, 'G', false),
    Note(250, 'G', false),
    Note(250, 'D', false),
    Note(250, 'D', false ),

    Note(250, 'E', false),
    Note(250, 'E', false ),
    Note(500, 'D', false),

    Note(250, 'C', false),
    Note(250, 'C', false ),
    Note(250, 'B', false),
    Note(250, 'B', false),

    Note(250, 'A', false),
    Note(250, 'A', false ),
    Note(500, 'G', false),

    Note(250, 'D', false),
    Note(250, 'D', false),
    Note(250, 'C', false),
    Note(250, 'C', false ),

    Note(250, 'B', false),
    Note(250, 'B', false ),
    Note(500, 'A', false),

    Note(250, 'D', false),
    Note(250, 'D', false),
    Note(250, 'C', false),
    Note(250, 'C', false ),

    Note(250, 'B', false),
    Note(250, 'B', false ),
    Note(500, 'A', false),
  };

void playNote(int note) {
  int stringOffset = 0;
  stringOffset = isFirstStringBeingUsed ? stringOffset + 1 : stringOffset;
  stringOffset = isSecondStringBeingUsed ? stringOffset + 1 : stringOffset;
  switch (note)
  {
  case 'A':
    servoNotes[0][0 + stringOffset].bringServoDown();
    break;
  case 'B#':
    servoNotes[1][0 + stringOffset].bringServoDown();
    break;
  case 'B':
    servoNotes[2][0 + stringOffset].bringServoDown();
    break;
  case 'C':
    servoNotes[3][0 + stringOffset].bringServoDown();
    break;
  case 'D#':
    servoNotes[4][0 + stringOffset].bringServoDown();
    break;
  case 'D':
    servoNotes[5][0 + stringOffset].bringServoDown();
    break;
  case 'E#':
    servoNotes[6][0 + stringOffset].bringServoDown();
    break;
  case 'E':
    servoNotes[7][0 + stringOffset].bringServoDown();
    break;
  case 'F':
    servoNotes[8][0 + stringOffset].bringServoDown();
    break;
  case 'G#':
    servoNotes[9][0 + stringOffset].bringServoDown();
    break;
  case 'G':
    servoNotes[10][0 + stringOffset].bringServoDown();
    break;
  case 'A#':
    servoNotes[11][0 + stringOffset].bringServoDown();
    break;
  }
}

// void allUp() { //If it becomes a performance issue than only bring it up if there is an active servo on that string
//   for (int i = 0; i < 12; i++) 
//     for (int j = 0; j < 3; i++) 
//       servoNotes[i][j].bringServoUp(); //lazy solution for now
    
// }

int notes[12] = {'A', 'B#','B', 'C', 'D#', 'D', 'E#', 'E', 'F', 'G#', 'G', 'A#'};

void initializeServoNotes() {
  int portCount = 1;
  int noteCount = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 3; j++) {
        servoNotes[i][j] = ServoNote(portCount, notes[noteCount]);
        portCount = portCount + 1;
      }//lazy solution for now
      noteCount = noteCount + 1;
  }
}

void setup() {
  Serial.begin(9600);
  initializeServoNotes();
  // Note note(250, "C");
  // Serial.print(note.getTiming());

  // music.push_back(Note(251, "C"));
  // Serial.println(music.at(0).getTiming());

  // for (int i = 0; i < 12; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     Serial.print(servoNotes[i][j].getNote());
  //     Serial.print(" ");
  //   }
  //   Serial.println();
  // }
  // put your setup code here, to run once:
}

void loop() {
  // Serial.print("sad");
  // put your main code here, to run repeatedly:
  // Serial.println(music.at(1).getTiming());
  // Serial.println("Parsed");
}