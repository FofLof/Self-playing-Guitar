

class ServoNote 
{

int UP_DEGREES = 0;
int DOWN_DEGREES = 0; //@TODO get correct values
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