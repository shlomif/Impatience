#include <SDL/SDL.h>
#include "game_manager.h"
#include "gui_manager.h"
#include "input_manager.h"

int main(int argc, char * argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        fprintf(stderr, SDL_GetError());
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
