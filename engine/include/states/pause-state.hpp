#ifndef PTE_PAUSE_STATE_HPP
#define PTE_PAUSE_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "state.hpp"
#include "game.hpp"

namespace pte
{
    class PauseState : public State
    {
    private:
        game_data_ref data;
        
        sf::Sprite resume_button;
        sf::Sprite home_button;
        sf::Text title;

    public:
        PauseState(game_data_ref data);

        void init();

        void handle_input();
        void update(float delta_time);
        void draw(float delta_time);
    };
}

#endif