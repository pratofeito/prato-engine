#ifndef PTE_GENERIC_STATE_HPP
#define PTE_GENERIC_STATE_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "state.hpp"
#include "game.hpp"

namespace pte
{

    class GenericState : public pte::State
    {
    protected:
        pte::game_data_ref data;
        sf::Clock clock;
        sf::Sprite background;

    public:
        GenericState(pte::game_data_ref data) : data(data) {}

        virtual void init() = 0;
        virtual void handle_input() = 0;
        virtual void update(float delta_time) = 0;
        virtual void draw(float delta_time) = 0;

        template <class T_state>
        void add_state(bool replacing)
        {
            this->data->state_handler.add_state(pte::state_ref(new T_state(data)), replacing);
        }
        
    };
}

#endif