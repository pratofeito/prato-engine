#include <iostream>
#include "game.hpp"
#include "game-state.hpp"

int main()
{
    // First, create a new game. Before starting, set initial state
    pte::Game game = pte::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo");
    game.init_state<GameState>();
    game.run();

    return 0;
}