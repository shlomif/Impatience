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
#include "gui_manager.h"

namespace GUI
{
    bool Manager::window_is_open;
    Area Manager::columns;
    Area Manager::foundations;
    Area Manager::freecells;
    int  Manager::spacing;

    SDL_Surface * Manager::window;
    Game::Card  * Manager::snapped_card;

    void Manager::Load()
    {
        Manager::window_is_open = true;
        Manager::spacing        = 8;

        Manager::window = SDL_SetVideoMode(852, 480, 0, SDL_SWSURFACE);
        if(Manager::window == NULL)
        {
            fprintf(stderr, SDL_GetError());
            exit(1);
        }
    }

    void Manager::Update() // ASSIGNED: Ivan
    {
        SDL_Rect rect;

        Manager::columns.x = Manager::spacing*2;
        Manager::columns.y = window->h/3;
        Manager::columns.w = window->w - Manager::spacing*2*2;
        Manager::columns.h = window->h - window->h/3 - Manager::spacing*2;
        Manager::foundations.x = Manager::spacing*2;
        Manager::foundations.y = Manager::spacing*2;
        Manager::foundations.w = window->w/2 - Manager::spacing*2*2 + Manager::spacing;
        Manager::foundations.h = window->h/3 - Manager::spacing*2*2;
        Manager::freecells.x = window->w/2 + Manager::spacing;
        Manager::freecells.y = Manager::spacing*2;
        Manager::freecells.w = window->w/2 - Manager::spacing*2*2 + Manager::spacing;
        Manager::freecells.h = window->h/3 - Manager::spacing*2*2;

        /* GRAPHICS: */

        SDL_FillRect(Manager::window, NULL, 0); // Clear the window of colours

        rect.x = Manager::columns.x;
        rect.y = Manager::columns.y;
        rect.w = Manager::columns.w;
        rect.h = Manager::columns.h;
        SDL_FillRect(Manager::window, &rect, SDL_MapRGB(Manager::window->format, 255, 0, 0));

        rect.x = Manager::foundations.x;
        rect.y = Manager::foundations.y;
        rect.w = Manager::foundations.w;
        rect.h = Manager::foundations.h;
        SDL_FillRect(Manager::window, &rect, SDL_MapRGB(Manager::window->format, 0, 255, 0));

        rect.x = Manager::freecells.x;
        rect.y = Manager::freecells.y;
        rect.w = Manager::freecells.w;
        rect.h = Manager::freecells.h;
        SDL_FillRect(Manager::window, &rect, SDL_MapRGB(Manager::window->format, 0, 0, 255));

        SDL_Flip(Manager::window);
    }

    Game::Card * Manager::GetCardAt(const int x, const int y)
    {
        // TODO: Figure out which card is at x/y, return a pointer to it
    }

    int Manager::GetColumnAt(const int x, const int y)
    {
        // TODO: Figure out which zone type (column/foundation/freecell) are the x/y in.
        //       Figure out which column in this zone the x/y are, and return it.
    }

    void Manager::SnapToCursor(Game::Card * to_snap)
    {
        Manager::snapped_card = to_snap;
    }

    bool Manager::WindowIsOpen()
    {
        return Manager::window_is_open;
    }

    void Manager::Close()
    {
        Manager::window_is_open = false;
    }
}
