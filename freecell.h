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
#ifndef FREECELL_H_INCLUDED
#define FREECELL_H_INCLUDED

namespace Constants
{
    enum CARDSUITS
    {
        CARDSUITS_HEART,
        CARDSUITS_CLUB,
        CARDSUITS_DIAMOND,
        CARDSUITS_SPADE,
        CARDSUITS_EOF
    };

    enum CARDRANKS
    {
        CARDRANKS_ACE,
        CARDRANKS_TWO,
        CARDRANKS_THREE,
        CARDRANKS_FOUR,
        CARDRANKS_FIVE,
        CARDRANKS_SIX,
        CARDRANKS_SEVEN,
        CARDRANKS_EIGHT,
        CARDRANKS_NINE,
        CARDRANKS_JACK,
        CARDRANKS_QUEEN,
        CARDRANKS_KING,
        CARDRANKS_EOF
    };

    const int CARDS       = CARDSUITS_EOF * CARDRANKS_EOF;
    const int FOUNDATIONS = 4;
    const int FREECELLS   = 4;
    const int COLUMNS     = 8;
}

#endif
