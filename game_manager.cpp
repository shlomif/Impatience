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
#include "game_manager.h"

namespace Game
{
    State Manager::state;
    Move  Manager::last_moves[0];
    Move  Manager::last_undos[0];

    void Manager::Load()
    {
        // TODO: Load here everything you need in order for the manager to function.
    }

    void Manager::Update()
    {
        // TODO: Write whatever the manager will do every main-loop iteration.
    }

    void Manager::Shuffle() // ASSIGNED: Nitin
    {
        // TODO: Delete all cards (if any) and create a random layout.
    }

    bool Manager::TryMove(Move * move)
    {
        // TODO: Check if move is a legal move.
        //       If it is, execute it an return true.
        //       Else, return false.
    }

    void Manager::Undo(const int ammount)
    {
        // TODO: Undo an ammount of moves from last_moves[], add them to last_undos[] and remove them from last_moves[]
    }

    void Manager::Redo(const int ammount)
    {
        // TODO: TryMove an ammount of moves from last_undos[], add them to last_moves and remove them from last_undos[]
    }
}
