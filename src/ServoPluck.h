class ServoPluck
{
    int LEFT_PLUCK_POSITION = 0;
    int RIGHT_PLUCK_POSITION = 0;

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
