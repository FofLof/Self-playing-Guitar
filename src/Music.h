
class Music
{

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
public:

    Note* getTwinkleTwinkleLittleStar()
    {
        static Note twinkleTwinkleLittleStar[] = {
            Note(250  + 350, G),
            Note(250 + 350, G),
            Note(250 + 350, D),
            Note(250 + 350, D),

            Note(250 + 350, EH),
            Note(250 + 350, EH),
            Note(500 + 350, D),

            Note(250 + 350, C),
            Note(250 + 350, C),
            Note(250 + 350, B),
            Note(250 + 350, B),

            Note(250 + 350, A),
            Note(250+ 350, A),
            Note(500+ 350, G),

            Note(250 + 350, D),
            Note(250+ 350, D),
            Note(250+ 350, C),
            Note(250+ 350, C),

            Note(250+ 350, B),
            Note(250+ 350, B),
            Note(500+ 350, A),

            Note(250 + 350, D),
            Note(250+ 350 , D),
            Note(250 + 350, C),
            Note(250 + 350, C),

            Note(250 + 350, B),
            Note(250 + 350, B),
            Note(500 + 350, A),

            Note(250  + 350, G),
            Note(250 + 350, G),
            Note(250 + 350, D),
            Note(250 + 350, D),

            Note(250 + 350, EH),
            Note(250 + 350, EH),
            Note(500 + 350, D),

            Note(250 + 350, C),
            Note(250 + 350, C),
            Note(250 + 350, B),
            Note(250 + 350, B),

            Note(250 + 350, A),
            Note(250+ 350, A),
            Note(500+ 350, G),
        };

        return twinkleTwinkleLittleStar;
    }

    Note* getOctave() {
        static Note octave[] = {
            Note(2000, E),
            Note(2000, F),
            Note(2000, FSHARP),
            Note(2000, G),
            Note(2000, GSHARP),
            Note(2000, A),
            Note(2000, ASHARP),
            Note(2000, B),
            Note(2000, C),
            Note(2000, CSHARP),
            Note(2000, D),
            Note(2000, DSHARP),
            Note(2000, EH),
            Note(2000, E)
        };
        return octave;
    }

    Note* getNandemonaiya() {
        static Note nandemonaiya[] = {
            Note(250, GSHARP),
            Note(250, ASHARP),
            Note(250, GSHARP),

            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(300, CSHARP),
            Note(200, CSHARP),
            Note(200, DSHARP),
            Note(150, FSHARP),
            Note(200, F),

            Note(200, DSHARP),
            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(500, ASHARP),

            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, CSHARP),
            Note(200, ASHARP),
            Note(200, GSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(300, GSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(800, FSHARP),
            Note(200, ASHARP),
            Note(200, GSHARP),

            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, CSHARP),
            Note(200, CSHARP),
            Note(200, DSHARP),
            Note(200, FSHARP),
            Note(200, F),

            Note(200, DSHARP),
            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(800, ASHARP),
            Note(200, ASHARP),
            Note(200, GSHARP),

            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, CSHARP),
            Note(200, ASHARP),
            Note(200, GSHARP),
            Note(200, FSHARP),
            Note(300, FSHARP),
            Note(200, FSHARP),

            Note(300, GSHARP),
            Note(200, FSHARP),
            Note(500, FSHARP),

            Note(170, GSHARP),
            Note(170, ASHARP),
            Note(170, CSHARP),
            Note(170, DSHARP),
            Note(170, FSHARP),
            Note(170, GSHARP),
            Note(170, ASHARP),
            Note(170, FSHARP),
            Note(170, CSHARP),
            Note(170, CSHARP),

            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(200, ASHARP),
            Note(200, FSHARP),
            Note(200, DSHARP),
            Note(400, CSHARP),

            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(200, ASHARP),
            Note(200, DSHARP),
            Note(200, CSHARP),
            Note(200, GSHARP),
            Note(200, ASHARP),
            Note(1000, CSHARP),

            Note(200, GSHARP),
            Note(200, ASHARP),
            Note(200, CSHARP),
            Note(200, DSHARP),
            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(200, FSHARP),

            Note(200, ASHARP),
            Note(200, GSHARP),
            Note(250, FSHARP),
            Note(250, FSHARP),
            Note(250, FSHARP),
            Note(300, CSHARP),
            Note(300, CSHARP),
            Note(200, DSHARP),

            Note(200, FSHARP),
            Note(200, F),
            Note(200, DSHARP),
            Note(200, FSHARP),
            Note(200, GSHARP),
            Note(600, ASHARP),

            Note(200, ASHARP),
            Note(200, GSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, FSHARP),
            Note(200, CSHARP),
             Note(200, ASHARP),
            Note(200, GSHARP),
            Note(150, FSHARP),
            Note(300, FSHARP),

            Note(200, FSHARP),
            Note(300, GSHARP),
            Note(150, FSHARP),
            Note(400, FSHARP),
            Note(200, FSHARP),

            Note(200, FSHARP),
            Note(400, A),
            Note(200, ASHARP),
            Note(500, FSHARP),
            Note(200, FSHARP)
        };
        return nandemonaiya;
    }

    Note* getHotCrossBuns() {
        static Note hotCrossBuns[] = {
            Note(250 , B),
            Note(250 , A),
            Note(500 , G),

            Note(250, B),
            Note(250, A),
            Note(500, G),

           Note(125, G),
          Note(125, G),
          Note(125, G),
          Note(125, G),

           Note(125, A),
           Note(125, A),
           Note(125, A),
           Note(125, A),

            Note(250, B),
            Note(250, A),
            Note(500, G)
        };
        return hotCrossBuns;
    }
};