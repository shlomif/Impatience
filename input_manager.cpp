#include <SDL/SDL.h>
#include "input_manager.h"
#include "gui_manager.h"

namespace Input
{
    Game::Card * Manager::selected_card;

    void Manager::Load()
    {

    }

    void Manager::Update()
    {
        SDL_Event Event;
        while(SDL_PollEvent(&Event)) // There are events to handle
        {
            if(Event.type != SDL_QUIT)
            {
                // TODO: Handle events
            }
            else // Event.type == SDL_QUIT
            {
                GUI::Manager::Close();
            }
        }
    }
}
