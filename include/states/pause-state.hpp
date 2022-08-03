#ifndef PTE_PAUSE_STATE_HPP
#define PTE_PAUSE_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "engine/include/state/state.hpp"
#include "engine/include/game/game.hpp"
#include "states/menu-state.hpp"
#include "definitions.hpp"

class PauseState : public pte::State
{
private:
    pte::game_data_ref data;

    sf::Sprite resume_button;
    sf::Sprite home_button;
    sf::Text title;

public:
    PauseState(pte::game_data_ref data);

    void init();

    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};

#endif