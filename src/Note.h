
class Note
{
    int timing;
    int type;
    bool isComplete = false;
    bool isPaired;

public:
    Note(int time, int type, bool isPaired)
    {
        timing = time;
        this->type = type;
        this->isPaired = isPaired;
    }
    int getTiming() { return timing; }
    int getType() { return type; };
    bool getIsPaired() { return isPaired; }
};