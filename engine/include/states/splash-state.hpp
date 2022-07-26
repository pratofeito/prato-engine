#ifndef PTE_SPLASH_STATE_HPP
#define PTE_SPLASH_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "state.hpp"
#include "game.hpp"

#include "definitions.hpp"

namespace pte
{
    class SplashState : public State
    {
    private:
        game_data_ref data;
        sf::Clock clock;
        sf::Sprite background;

    public:
        SplashState(game_data_ref data);

        void init();

        void handle_input();
        void update(float dt);
        void draw(float dt);
    };
}

#endif