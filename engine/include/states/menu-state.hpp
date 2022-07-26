#ifndef PTE_MENU_STATE_HPP
#define PTE_MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "state.hpp"
#include "game.hpp"

namespace pte
{
    class MainMenuState : public State
    {
    private:
        game_data_ref data;

        sf::Sprite background;
        sf::Sprite play_button;
        sf::Sprite play_button_outer;
        sf::Sprite title;

    public:
        MainMenuState(game_data_ref data);

        void init();

        void handle_input();
        void update(float dt);
        void draw(float dt);
    };
}

#endif