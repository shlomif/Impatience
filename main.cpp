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
#include "game_manager.h"
#include "gui_manager.h"
#include "input_manager.h"

int main(int argc, char * argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return 1;
    }
    atexit(SDL_Quit);

    SDL_WM_SetCaption("Impatience", NULL);

    Game::Manager::Load();
    GUI::Manager::Load();
    Input::Manager::Load();

    while(GUI::Manager::WindowIsOpen())
    {
        GUI::Manager::Update();
        Input::Manager::Update();
        Game::Manager::Update();
    }

    exit(0);
}
