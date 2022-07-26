#ifndef PTE_GAME_STATE_HPP
#define PTE_GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include "state.hpp"
#include "game.hpp"

namespace pte
{
    class GameState : public State
    {
    private:
        game_data_ref data;

        sf::Sprite background;
        sf::Sprite pause_button;

        int turn;
        int game_state;

    public:
        GameState(game_data_ref data);

        void init();

        void handle_input();
        void update(float delta_time);
        void draw(float delta_time);
    };
}

#endif