/**
 * @file game-state.hpp
 * @date 2023-01-06
 * 
 * @brief Example game state. Runs a bouncing ball demo.
 * 
 */

#ifndef PTE_DEMO_GAME_STATE_HPP
#define PTE_DEMO_GAME_STATE_HPP

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <cmath>
#include "generic-state.hpp"


class GameState : public pte::GenericState
{
private:
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
    using GenericState::GenericState;

    void init();
    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};


#endif