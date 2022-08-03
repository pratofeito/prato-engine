#ifndef PTE_GAME_STATE_HPP
#define PTE_GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "engine/include/state.hpp"
#include "engine/include/game.hpp"
#include "states/pause-state.hpp"
#include "definitions.hpp"

class GameState : public pte::State
{
private:
    pte::game_data_ref data;

    sf::Sprite background;
    sf::Sprite pause_button;

public:
    GameState(pte::game_data_ref data);

    void init();

    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};

#endif