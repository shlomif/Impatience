#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

#include "freecell.h"
#include "game_card.h"

namespace Game
{
    class State
    {
    public:
        Card column[Constants::COLUMNS][Constants::CARDS];
        Card founcation[Constants::FOUNDATIONS][Constants::CARDS/4];
        Card freecell[Constants::FREECELLS];

        State();
    };
}

#endif
