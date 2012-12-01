#ifndef GAME_MANAGER_H_INCLUDED
#define GAME_MANAGER_H_INCLUDED

#include "game_move.h"
#include "game_state.h"

namespace Game
{
    class Manager
    {
    private:
        static State state;
        static Move  last_moves[];

    public:
        static void Load();
        static void Update();
        static void Shuffle();
        static bool TryMove(Move *);
        static void Undo(const int = 1);
        static void Redo(const int = 1);

        Manager();
    };
}

#endif
