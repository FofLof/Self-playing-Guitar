
class Music
{
public:

    Note* getTwinkleTwinkleLittleStar()
    {
        static Note twinkleTwinkleLittleStar[] = {
            Note(250, 'G', false),
            Note(250, 'G', false),
            Note(250, 'D', false),
            Note(250, 'D', false),

            Note(250, 'EH', false),
            Note(250, 'EH', false),
            Note(500, 'D', false),

            Note(250, 'C', false),
            Note(250, 'C', false),
            Note(250, 'B', false),
            Note(250, 'B', false),

            Note(250, 'A', false),
            Note(250, 'A', false),
            Note(500, 'G', false),

            Note(250, 'D', false),
            Note(250, 'D', false),
            Note(250, 'C', false),
            Note(250, 'C', false),

            Note(250, 'B', false),
            Note(250, 'B', false),
            Note(500, 'A', false),

            Note(250, 'D', false),
            Note(250, 'D', false),
            Note(250, 'C', false),
            Note(250, 'C', false),

            Note(250, 'B', false),
            Note(250, 'B', false),
            Note(500, 'A', false),
        };

        return twinkleTwinkleLittleStar;
    }
};