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
#include "game_manager.h"

namespace GUI
{
    bool Manager::window_is_open;
    Area Manager::columns;
    Area Manager::foundations;
    Area Manager::freecells;
    int  Manager::spacing;
    SDL_Surface * Manager::window;
    SDL_Surface * Manager::window_background;
    Game::Card  * Manager::snapped_card;
    SDL_Surface * Manager::card_graphic[];

    void Manager::Load()
    {
        Manager::window_is_open = true;
        Manager::spacing        = 8;

        Manager::window = SDL_SetVideoMode(852, 480, 0, SDL_RESIZABLE);
        if(Manager::window == NULL)
        {
            fprintf(stderr, "%s\n", SDL_GetError());
            exit(1);
        }

        Manager::SetBackground("assets/bg.bmp");

        for(int s = 0; s < Constants::CARDSUITS_EOF; s++)
        {
            for(int r = 0; r < Constants::CARDRANKS_EOF; r++)
            {
                char path[200];
                sprintf(path, "assets/%1d_%02d.bmp", s+1, r+1);

                Manager::card_graphic[(s * Constants::CARDRANKS_EOF) + r] = SDL_LoadBMP(path);
                if(Manager::card_graphic[(s * Constants::CARDRANKS_EOF) + r] == NULL)
                {
                    fprintf(stderr, "%s\n", SDL_GetError());
                }
            }
        }
    }

    void Manager::Update() // ASSIGNED: Ivan
    {
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

        // Render background:
        if(Manager::window_background != NULL)
        {
            SDL_BlitSurface(Manager::window_background, NULL, Manager::window, NULL);
        }

        // Render cards:
        Game::State* state = Game::Manager::GetState();
        if(state != NULL)
        {
            for(int i = 0; i < Constants::COLUMNS; i++)
            {
                for(int j = 0; j < Constants::CARDS/4; j++)
                {
                    if(state->column[i][j] != NULL && state->column[i][j] != Manager::snapped_card)
                    {
                        // TODO: Render card
                    }
                }
            }

            for(int i = 0; i < Constants::FOUNDATIONS; i++)
            {
                for(int j = 0; j < Constants::CARDS/4; j++)
                {
                    if(state->foundation[i][j] != NULL && state->column[i][j] != Manager::snapped_card)
                    {
                        // TODO: Render card
                    }
                }
            }

            for(int i = 0; i < Constants::FREECELLS; i++)
            {
                for(int j = 0; j < Constants::CARDS / Constants::FREECELLS; j++)
                {
                    if(state->freecell[i][j] != NULL && state->column[i][j] != Manager::snapped_card)
                    {
                        // TODO: Render card
                    }
                }
            }
        }
        else // state == NULL
        {
            static int errcount = 1;
            if(errcount <= 3)
            {
                fprintf(stderr, "Game state is uninitialised x%d.\n", errcount);
                errcount++;
            }
            else // errcount > 3
            {
                fprintf(stderr, "Stopped saying Game state is uninitialised.\n");
            }
        }

        // Render snapped card:
        if(Manager::snapped_card != NULL)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect r;
            r.x = x;
            r.y = y;
            SDL_BlitSurface(Manager::window, &r, Manager::card_graphic[(Manager::snapped_card->GetSuit() * Constants::CARDRANKS_EOF) + Manager::snapped_card->GetRank()], NULL);
        }

        SDL_Flip(Manager::window);
    }

    Game::Card * Manager::GetCardAt(const int x, const int y)
    {
        // TODO: Figure out which card is at x/y, return a pointer to it
        return NULL;
    }

    int Manager::GetColumnAt(const int x, const int y)
    {
        // TODO: Figure out which zone type (column/foundation/freecell) are the x/y in.
        //       Figure out which column in this zone the x/y are, and return it.
        return -1;
    }

    void Manager::SnapToCursor(Game::Card * to_snap)
    {
        Manager::snapped_card = to_snap;
    }

    void Manager::UnsnapFromCursor()
    {
        Manager::snapped_card = NULL;
    }

    bool Manager::WindowIsOpen()
    {
        return Manager::window_is_open;
    }

    void Manager::SetBackground(const char* path)
    {
        Manager::window_background = SDL_LoadBMP(path);
        if(Manager::window_background == NULL)
        {
            fprintf(stderr, "%s", SDL_GetError());
        }
    }

    bool Manager::HandleEvents(const SDL_Event event)
    {
        if(event.type == SDL_QUIT)
        {
            Manager::window_is_open = false;
            return true;
        }
        else if(event.type == SDL_VIDEORESIZE)
        {
            Manager::window = SDL_SetVideoMode(event.resize.w, event.resize.h, 0, SDL_RESIZABLE);
            return true;
        }

        return false;
    }
}
