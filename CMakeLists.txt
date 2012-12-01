Project(Impatience)
Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if(NOT SDL_FOUND)
    message( FATAL_ERROR "SDL not found!")
endif(NOT SDL_FOUND)

add_executable(impatience
    game_card.cpp
    game_manager.cpp
    game_move.cpp
    game_state.cpp
    gui_area.cpp
    gui_manager.cpp
    input_manager.cpp
    main.cpp
)

# MESSAGE ( FATAL_ERROR "SDL = ${SDL_LIBRARY}")
# MESSAGE ( FATAL_ERROR "SDL = ${SDLIMAGE_LIBRARY}")
target_link_libraries(
    impatience
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY}
)
