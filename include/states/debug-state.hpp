#ifndef DEBUG_GAME_STATE_HPP
#define DEBUG_GAME_STATE_HPP

#include "engine/include/generic-state.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

#include <filesystem>

class DebugState : public pte::GenericState
{
private:
    sf::View view;
    sf::Clock dtTime;
    const char **names;
    unsigned int nameSize;
    std::vector<std::string> teste;

public:
    using GenericState::GenericState;
    void init();
    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};

#endif