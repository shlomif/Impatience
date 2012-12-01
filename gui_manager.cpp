#include <SDL/SDL.h>
#include "gui_manager.h"

SDL_Surface* window;

namespace GUI
{
    bool Manager::window_is_open;
    Area Manager::columns;
    Area Manager::foundations;
    Area Manager::freecells;
    int  Manager::spacing;

    Game::Card * Manager::snapped_card;

    void Manager::Load()
    {
        Manager::window_is_open = true;
        Manager::spacing        = 8;

        window = SDL_SetVideoMode(852, 480, 0, SDL_SWSURFACE);
        if(window == NULL)
        {
            fprintf(stderr, SDL_GetError());
            exit(1);
        }
    }

    void Manager::Update()
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

        SDL_FillRect(window, NULL, 0); // Clear the window of colours

        rect.x = Manager::columns.x;
        rect.y = Manager::columns.y;
        rect.w = Manager::columns.w;
        rect.h = Manager::columns.h;
        SDL_FillRect(window, &rect, SDL_MapRGB(window->format, 255, 0, 0));

        rect.x = Manager::foundations.x;
        rect.y = Manager::foundations.y;
        rect.w = Manager::foundations.w;
        rect.h = Manager::foundations.h;
        SDL_FillRect(window, &rect, SDL_MapRGB(window->format, 0, 255, 0));

        rect.x = Manager::freecells.x;
        rect.y = Manager::freecells.y;
        rect.w = Manager::freecells.w;
        rect.h = Manager::freecells.h;
        SDL_FillRect(window, &rect, SDL_MapRGB(window->format, 0, 0, 255));

        SDL_Flip(window);
    }

    Game::Card * Manager::GetCardAt(const int x, const int y)
    {

    }

    int Manager::GetSlotAt(const int x, const int y)
    {

    }

    void Manager::SnapToCursor(Game::Card*)
    {

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
