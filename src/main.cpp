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

class Note
{
    public:
        int timing;
        int type;
        bool isComplete;

        // Note();
        Note(int timing, int type, bool isComplete) {
            this->timing = timing;
            this->type = type;
            this->isComplete = isComplete;
        }

        int getTiming() { return timing;}

        int getType() { return type; }

        bool getIsComplete() { return isComplete; }
        void setIsComplete(bool isComplete) { this->isComplete = isComplete; }
        
};

class ServoNote 
{
  public:
    String note;
    Servo servo;
    ServoNote(int portNumber, String note) {
      this->note = note;
      servo.attach(portNumber);
    }
    
    void bringServoUp() {
      servo.write(UP_DEGREES);
    }

    void bringServoDown() {
      servo.write(DOWN_DEGREES);
    }
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




void setup() {
  Vector<Note> music;


  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}