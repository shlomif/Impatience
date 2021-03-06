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
        static Move  last_undos[];

    public:
        static State * GetState();
        static void Load();
        static void Update();
        static void Shuffle(); // Deletes all cards (if any), and generates a new card layout randomly.
        static bool TryMove(Move *); // Returns true if the move specified in the parameter is a legal move.
                                     // False otherwise. If the move is valid, it also executes the move.
        static void Undo(const int = 1); // Undoes an ammount of moves specified by its parameter.
        static void Redo(const int = 1); // Redoes an ammount of moves specified by its parameter.
    };
}

#endif
