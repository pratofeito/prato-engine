#include <iostream>
#include "engine/include/game.hpp"
#include "definitions.hpp"
#include "states/splash-state.hpp"
#include "states/game-state.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    // First, create a new game. Before starting, set initial state
    pte::Game game = pte::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo");
    game.init_state<GameState>();
    game.run();

    return 0;
}
