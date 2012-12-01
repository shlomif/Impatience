/*
Copyright (C) 2012 Ivan Rubinson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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
