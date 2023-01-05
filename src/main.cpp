#include <iostream>
#include "engine/include/game.hpp"
#include "definitions.hpp"
#include "states/splash-state.hpp"

int main()
{
    pte::Game game = pte::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo");
    game.init_state<SplashState>();
    game.run();

    return 0;
}