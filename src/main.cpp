#include <iostream>
#include "engine/include/game.hpp"
#include "definitions.hpp"
#include "states/splash-state.hpp"
#include "states/game-state.hpp"
#include "states/debug-state.hpp"
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

int main()
{
    // First, create a new game. Before starting, set initial state
    pte::Game game = pte::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo");
    game.init_state<DebugState>();
    game.run(); /*
     bool *demo;
     *demo = true;
     ImGui::SFML::ShowDemoWindow(); */

    return 0;
}
