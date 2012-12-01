#ifndef GAME_CARD_H_INCLUDED
#define GAME_CARD_H_INCLUDED

namespace Game
{
    class Card
    {
    private:
        bool is_hidden;
        char suit;
        int  rank;

    public:
        int  GetSuit();
        int  GetRank();
        bool IsHidden();
        void Flip();

        Card();
    };
}

#endif
