#ifndef GUI_MANAGER_H_INCLUDED
#define GUI_MANAGER_H_INCLUDED

#include "game_card.h"
#include "gui_area.h"

namespace GUI
{
    class Manager
    {
    private:
        static bool window_is_open;
        static Area columns;
        static Area foundations;
        static Area freecells;
        static int  spacing;

        static Game::Card * snapped_card;

    public:
        static void Load();
        static void Update();
        static Game::Card * GetCardAt(const int, const int);
        static int GetSlotAt(const int, const int);
        static void SnapToCursor(Game::Card*);
        static bool WindowIsOpen();
        static void Close();
    };
}

#endif
