/* Copyright (c) 2012 Ivan Rubinson, Nitin Reddy Katkam
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
#include "game_manager.h"
#include <cstdlib>
#include <ctime>
#include <assert.h>

namespace Game
{
    State Manager::state;
    Move  Manager::last_moves[0];
    Move  Manager::last_undos[0];

    void Manager::Load()
    {
        int i, j;

        //init column pointers
        for(i=0; i<Constants::COLUMNS; i++)
        {
            for(j=0; j<Constants::CARDS/4; j++)
            {
                Game::Manager::state.column[i][j] = NULL;
            }
        }

        //init clear freecells ptrs
        for (i=0; i<Constants::FREECELLS; i++)
        {
            Game::Manager::state.freecell[i] = NULL;
        }

        //init foundation ptrs
        for (i=0; i<Constants::FOUNDATIONS; i++)
        {
            for (j=0; j<Constants::CARDS/4; j++)
            {
                Game::Manager::state.foundation[i][j] = NULL;
            }
        }

        Shuffle();
    }

    void Manager::Update()
    {
        // TODO: Write whatever the manager will do every main-loop iteration.
    }

    void Manager::Shuffle() //ASSIGNED: Nitin
    {
        int cards[Constants::CARDS];
        int i, j, temp;
        int val;

        //pre-populate
        for(i=0; i<Constants::CARDS; i++)
        {
            cards[i] = i;
        }

        //shuffle
        for(j=0; j<Constants::CARDS; j++)
        {
            for (i=0; i<Constants::CARDS; i++)
            {
                srand(time(NULL));
                if (rand()%2)
                {
                    temp = cards[i];
                    cards[i] = cards[j];
                    cards[j] = temp;
                }
            }
        }

        //clear columns
        for(i=0; i<Constants::COLUMNS; i++)
        {
            for(j=0; j<Constants::CARDS/4; j++)
            {
                if (Game::Manager::state.column[i][j] != NULL)
                {
                    delete Game::Manager::state.column[i][j];
                    Game::Manager::state.column[i][j] = NULL;
                }
            }
        }

        //clear freecells
        for (i=0; i<Constants::FREECELLS; i++)
        {
            if (Game::Manager::state.freecell[i] != NULL)
            {
                delete Game::Manager::state.freecell[i];
                Game::Manager::state.freecell[i] = NULL;
            }
        }

        //clear foundation
        for (i=0; i<Constants::FOUNDATIONS; i++)
        {
            for (j=0; j<Constants::CARDS/4; j++)
            {
                if (Game::Manager::state.foundation[i][j] != NULL)
                {
                    delete Game::Manager::state.foundation[i][j];
                    Game::Manager::state.foundation[i][j] = NULL;
                }
            }
        }

        //build state
        for (i=0; i<Constants::CARDS; i++)
        {
            val = cards[i];
            Game::Card* currCard = new Game::Card((char)val/(Constants::CARDS/4), val%(Constants::CARDS/4)+1);
            //currCard->suit = val/13;
            //currCard->rank = val%13+1;
            Game::Manager::state.column[i%Constants::COLUMNS][i/Constants::COLUMNS] = currCard;
        }
    }

    bool Manager::TryMove(Move * move)
    {
        // TODO: Check if move is a legal move.
        //       If it is, execute it an return true.
        //       Else, return false.
        return false;
    }

    void Manager::Undo(const int ammount)
    {
        // TODO: Undo an ammount of moves from last_moves[], add them to last_undos[] and remove them from last_moves[]
    }

    void Manager::Redo(const int ammount)
    {
        // TODO: TryMove() an ammount of moves from last_undos[], add them to last_moves and remove them from last_undos[]
    }

    Card * * Manager::GetCards()
    {
        // TODO: Create a null-terminated array of pointers to all the cards in Manager::state.
        //       Make sure there are no nulls in the middle, if there are - strip them away.
        //       Return it.
        // Important: Make sure it lives outside the function!
        return NULL;
    }
}
