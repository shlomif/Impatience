/* Copyright (c) 2012 Ivan Rubinson
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef GUI_MANAGER_H_INCLUDED
#define GUI_MANAGER_H_INCLUDED

#include "game_card.h"
#include "gui_area.h"
#include "freecell.h"
#include <SDL/SDL.h>

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
        static SDL_Surface * window;
        static SDL_Surface * window_background;
        static Game::Card  * snapped_card;
        static SDL_Surface * card_graphic[Constants::CARDS];

        static void SetBackground(const char*); // Sets the windows background to the file located at the path specified by the parameter.

    public:
        static void Load();
        static void Update();
        static Game::Card * GetCardAt(const int, const int); // Returns a pointer to the card at the x/y specified by its parameters.
        static int GetColumnAt(const int, const int); // Returns in which column the x/y specified by its parameters are. Not a column as a zone, but a column inside a zone.
        static void SnapToCursor(Game::Card*); // Attaches the card specified by its parameter to the cursor. The card will follow the cursor.
        static bool WindowIsOpen(); // Returns false if the window is closed. True otherwise.
        static bool HandleEvents(const SDL_Event); // Gets an SDL event and processes it. Returns true if the event is relevant to the manager, false otherwise.
    };
}

#endif
