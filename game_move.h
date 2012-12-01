#ifndef GAME_MOVE_H_INCLUDED
#define GAME_MOVE_H_INCLUDED

#include "game_card.h"

namespace Game
{
    class Move
    {
    public:
        Card * card;
        int    type;
        int    place;

        Move();
    };
}

#endif
