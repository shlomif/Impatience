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
#include <SDL/SDL.h>
#include "input_manager.h"
#include "game_card.h"
#include "game_manager.h"
#include "game_move.h"
#include "gui_manager.h"

namespace Input
{
    Game::Card * Manager::selected_card = NULL;
    int Manager::selection_x = 0;
    int Manager::selection_y = 0;

    void Manager::Load()
    {
        // TODO: Load here everything you need for the manager to function.
    }

    void Manager::Update()
    {
        SDL_Event event;
        while(SDL_PollEvent(&event)) // There are events to handle
        {
            if(GUI::Manager::HandleEvents(event) == false)
            {
                enum CONTROLTYPES
                {
                    NO_CONTROL,
                    POINT_AND_CLICK,
                    DRAG_AND_DROP
                };
                static int control = NO_CONTROL;
                bool controlled = false;

                if(control == NO_CONTROL)
                {
                    static int count = 0;

                    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                    {
                        count++;
                    }

                    if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
                    {
                        control = POINT_AND_CLICK;
                        count = 0;
                    }
                    else if(count > 12)
                    {
                        control = DRAG_AND_DROP;
                        count = 0;
                    }

                    if(control != NO_CONTROL)
                    {
                        Manager::selected_card = GUI::Manager::GetCardAt(event.motion.x, event.motion.y);
                        if(Manager::selected_card != NULL)
                        {
                            GUI::Manager::SnapToCursor(Manager::selected_card);
                            Manager::selection_x = event.motion.x;
                            Manager::selection_y = event.motion.y;
                        }
                    }
                }
                else // Card is a card selected
                {
                    switch(control)
                    {
                        case(POINT_AND_CLICK):
                        {
                            if(event.type == SDL_MOUSEBUTTONDOWN)
                            {
                                controlled = true;
                            }
                            break;
                        }
                        case(DRAG_AND_DROP):
                        {
                            if(event.type == SDL_MOUSEBUTTONUP)
                            {
                                controlled = true;
                            }
                            break;
                        }
                    }

                    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT)
                    {
                        GUI::Manager::UnsnapFromCursor();
                        Manager::selected_card = NULL;
                        control = NO_CONTROL;
                    }

                    if(controlled)
                    {
                        Game::Move * m = new Game::Move();
                        m->card  = Manager::selected_card;
                        m->fzone = GUI::Manager::GetZoneAt(Manager::selection_x, Manager::selection_y);
                        m->tzone = GUI::Manager::GetZoneAt(event.motion.x, event.motion.y);
                        m->fcol  = GUI::Manager::GetColumnAt(Manager::selection_x, Manager::selection_y);
                        m->tcol  = GUI::Manager::GetColumnAt(event.motion.x, event.motion.y);
                        if(Game::Manager::TryMove(m) || control == DRAG_AND_DROP)
                        {
                            GUI::Manager::UnsnapFromCursor();
                            Manager::selected_card = NULL;
                            control = NO_CONTROL;
                        }
                    }
                }
            }
        }
    }
}
