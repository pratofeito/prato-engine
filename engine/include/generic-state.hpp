/**
 * @file generic-state.hpp
 * @date 2023-01-06
 *
 * @brief Basic components for a functional state, using the "state" concept.
 *
 */

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
    private:
        pte::game_data_ref data;

    protected:
        sf::Clock clock;
        sf::Sprite background;

        /// @brief window component
        sf::RenderWindow *window = &data->window;

        /// @brief tool for managing assets
        AssetManager *assets = &data->assets;

        /// @brief tool for managing inputs
        InputManager *input = &data->input;

    public:
        GenericState(pte::game_data_ref data) : data(data) {}

        /// @brief Run on state startup
        virtual void init() = 0;

        /// @brief Input handler component, all input related code has to be inserted here
        virtual void handle_input() = 0;

        /// @brief Executed every new frame, update logic has to be inserted here
        virtual void update(float delta_time) = 0;

        /// @brief Elements to be drawn every frame, in order
        virtual void draw(float delta_time) = 0;

        /**
         * @brief Add a new state into the state stack
         *
         * @tparam T_state Type of state to be inserted
         * @param replacing Replace or not current state
         */
        template <class T_state>
        void add_state(bool replacing)
        {
            this->data->state_handler.add_state(pte::state_ref(new T_state(data)), replacing);
        }

        /// @brief Remove current state from the stack
        void remove_state()
        {
            this->data->state_handler.remove_state();
        }
    };
}

#endif