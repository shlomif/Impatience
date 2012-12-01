#ifndef INPUT_MANAGER_H_INCLUDED
#define INPUT_MANAGER_H_INCLUDED

#include "game_card.h"

namespace Input
{
    class Manager
    {
    private:
        static Game::Card * selected_card;

    public:
        static void Load();
        static void Update();
    };
}

#endif
