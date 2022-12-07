#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Note.h>
#include <Music.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>

// Servo test[12][3];

#define SERVOMIN  150 // This is the minimum pulse length count (out of 4096)
#define SERVOMAX  600 // This is the maximum pulse length count (out of 4096)
#define USMIN  600 // This is the rounded minimum microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded maximum microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define E 1
#define F 2
#define FSHARP 13
#define G 3
#define GSHARP 4
#define A 5
#define ASHARP 6
#define B 7
#define C 8
#define CSHARP 9
#define D 10
#define DSHARP 11
#define EH 12


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
bool isDonePlaying = false;
int arrayLength  = 0;

class PWMServo {
  int port;
  int note;
  public:
    PWMServo(int port, int note) {
      this->port = port;
      this->note = note;
  
    }

    void setServo(int degree) {
      int pulselength = map(degree, 0, 180, SERVOMIN, SERVOMAX);

       pwm.setPWM(port, 0, pulselength);
    }
};

class ServoPluck
{
    int LEFT_PLUCK_PULSE = 0;
    int RIGHT_PLUCK_PULSE = 0;
    int settledPulse = 0;

public:
  
    bool pluckState; 
    int portNumber;
    bool atSettledPosition = false;

    ServoPluck(int portNumber, int leftPluckPulse, int rightPluckPulse) {
      this->portNumber = portNumber;
      this->LEFT_PLUCK_PULSE = leftPluckPulse;
      RIGHT_PLUCK_PULSE = rightPluckPulse;
      settledPulse = (leftPluckPulse + rightPluckPulse) /2;
    }
    void pluckString(){
      if (atSettledPosition) {
        if (pluckState) {
          pwm.setPWM(portNumber, 0, RIGHT_PLUCK_PULSE);
        }
        else {
          pwm.setPWM(portNumber, 0, LEFT_PLUCK_PULSE);
        }
        atSettledPosition = false;
        delay(100);
      }
      //false = currently at left Pulse
      //true = currently at right pulse
      if (pluckState) {
       pwm.setPWM(portNumber, 0, LEFT_PLUCK_PULSE);
      } else {
       pwm.setPWM(portNumber, 0, RIGHT_PLUCK_PULSE);
      }
      pluckState = !pluckState;
    }

    void sendToSettledPosition() {
      pwm.setPWM(portNumber, 0, settledPulse);
      atSettledPosition = true;
    }

    void reset() {
      pwm.setPWM(portNumber, 0, LEFT_PLUCK_PULSE);
      pluckState = false;
    }
};

class ServoNote 
{
int UP_PULSE = 550;
int DOWN_PULSE = 410;
int UP_DEGREES = 100;
int DOWN_DEGREES = 0; //@TODO get correct values
  public:
    int note;
    int portNumber;
    ServoNote() {
      note = 0;
    }
    ServoNote(int portNumber, int note, int upPulse, int downPulse) {
      this->note = note;
      this->portNumber = portNumber;
      UP_PULSE = upPulse;
      DOWN_PULSE = downPulse;
    }
    
    void bringServoUp() {
      // int pulselength = map(UP_DEGREES, 0, 180, SERVOMIN, SERVOMAX);

       pwm.setPWM(portNumber, 0, UP_PULSE);
    }

    void bringServoDown() {
      // int pulselength = map(UP_DEGREES, 0, 180, SERVOMIN, SERVOMAX);

       pwm.setPWM(portNumber, 0, DOWN_PULSE);
    }

    int getNote() { return note;}
};

ServoNote* servoNotes[11];


ServoPluck* servoPluck[2];

void initializePluckNotes() {
  servoPluck[0] = new ServoPluck(14, 300, 200);
  servoPluck[1] = new ServoPluck(15, 400, 210);
}

void initializeServoNotes() {
  // int portNumber = 0;

  // for (int i = 0; i < 11; i++) {
  //   if (portNumber == 9) { portNumber = 10; }
  //   servoNotes[i] = new ServoNote(portNumber, notes[i]);
  //   portNumber++;
  // } 

  
   servoNotes[0]  = new ServoNote(0, F, 600, 410);
   servoNotes[1]  =  new ServoNote(1, FSHARP, 150, 250);
   servoNotes[2]  =  new ServoNote(2, G, 120, 350);
   servoNotes[3]  =  new ServoNote(3, GSHARP, 50, 250);
   servoNotes[4]  =  new ServoNote(4, A, 100, 200);
   servoNotes[5]  =  new ServoNote(5, ASHARP, 100, 200); //Particularly bad
   servoNotes[6]  =  new ServoNote(6, B, 100, 300); //Literally Impossible
   servoNotes[7]  =  new ServoNote(7, CSHARP, 590, 300); //Shakes too much to work
   servoNotes[8]  =  new ServoNote(8, D, 100, 250);
   servoNotes[9]  =  new ServoNote(10, DSHARP, 130, 330);
   servoNotes[10]  =  new ServoNote(11, EH, 130, 350); //Misses sometimes
  
  
}

void reset() { //If it becomes a performance issue than only bring it up if there is an active servo on that string

  // servoNotes[6]->bringServoUp();
  for (int i = 0; i < 11; i++){
  // delay(10);
      servoNotes[i]->bringServoUp(); // lazy solution for now
  }
}



void playNote(Note playingNote) {
  
  int note = playingNote.getType();
//  Serial.println(note);
  bool useSecondString = false;

  switch (note)
  {
  case E:
    break;
  case F:
    servoNotes[0]->bringServoDown();
    break;
  case FSHARP:
    servoNotes[1]->bringServoDown();
    break;
  case G:
    servoNotes[2]->bringServoDown();
    break;
  case GSHARP:
    servoNotes[3]->bringServoDown();
    break;
  case A:
    servoNotes[4]->bringServoDown();
    break;
  case ASHARP:
    servoNotes[5]->bringServoDown();
    break;
  case B:
    servoNotes[6]->bringServoDown();
    break;
  case C:
  useSecondString = true;
    break;
  case CSHARP:
  useSecondString = true;
    servoNotes[7]->bringServoDown();
    break;
  case D:
  useSecondString = true;
    servoNotes[8]->bringServoDown();
    break;
  case DSHARP:
  useSecondString = true;
    servoNotes[9]->bringServoDown();
    break;
  case EH:
  useSecondString = true;
    servoNotes[10]->bringServoDown();
    break;
  }

  delay(500);
 if (!(abs(note) > 13) && note != 0) {
  if (useSecondString) {
    servoPluck[0]->sendToSettledPosition();
    servoPluck[1]->pluckString();
  } else {
    servoPluck[1]->sendToSettledPosition();
    servoPluck[0]->pluckString();
  }
 }
}

int noteBeingPlayed = 0;

void playSong(Note song[])
{

// Serial.println(arrayLength);
if (noteBeingPlayed + 1 == 42) {
    isDonePlaying = true;
  }
  int noteChange = 0;

  delay(song[noteBeingPlayed].getTiming());
  if (noteBeingPlayed - 1 !=  42) {
  reset();
  }
  playNote(song[noteBeingPlayed]);

  // Serial.println(song[noteBeingPlayed].getType());
  // if (song[noteBeingPlayed].getIsPaired())
  // {
  //   isSecondStringBeingUsed = true;
  //   playNote(song[noteBeingPlayed + 1]);
  //   noteChange = 2;
    
  // }

  noteBeingPlayed++;
}

Music music;

 Servo servo;
void setup() {
  Serial.begin(9600);
   pwm.reset();
//  ServoNote(1, A);
pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  initializePluckNotes();
  initializeServoNotes();

  reset();
  // servoNotes[6]->bringServoUp();
  servoPluck[0]->reset();
  servoPluck[1]->reset();
  delay(5000);
  // arrayLength = (sizeof(music.getHotCrossBuns()) / sizeof(music.getHotCrossBuns()[0]));
  // Serial.println(sizeof(music.getHotCrossBuns()));
  // Serial.println(sizeof(music.getHotCrossBuns()[0]));
  
}

int setAmount = 0;
 
void loop() {
  
  if (!isDonePlaying) {
  playSong(music.getTwinkleTwinkleLittleStar());
  }
   
}


