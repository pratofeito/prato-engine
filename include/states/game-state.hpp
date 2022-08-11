#ifndef PTE_GAME_STATE_HPP
#define PTE_GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include "engine/include/state/state.hpp"
#include "engine/include/game/game.hpp"
#include "states/pause-state.hpp"
#include "definitions.hpp"

class GameState : public pte::State
{
private:
    pte::game_data_ref data;

    sf::Sprite background;
    sf::Sprite pause_button;

    // demo things
    float pi = 3.14159f;
    float ballRadius = 10.f;
    float ballSpeed = 400.f;
    float ballAngle = 0.f;
    sf::CircleShape ball;

    void init_ball();
    void update_ball(float delta_time);

public:
    GameState(pte::game_data_ref data);

    void init();

    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};

#endif