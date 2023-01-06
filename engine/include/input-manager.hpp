/**
 * @file input-manager.hpp
 * @date 2023-01-06
 *
 * @brief Tools to manage multiple inputs
 *
 */

#ifndef PTE_INPUT_MANAGER_HPP
#define PTE_INPUT_MANAGER_HPP

#include <SFML/Graphics.hpp>

namespace pte
{
    class InputManager
    {
    public:
        InputManager() {}
        ~InputManager() {}

        /**
         * @brief Checks if the object is clicked
         * 
         * @param object Sprite to verify click
         * @param button Which mouse button
         * @param window Application window
         * @return true 
         * @return false 
         */
        bool is_sprite_clicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        /**
         * @brief Get the mouse position
         * 
         * @param window 
         * @return sf::Vector2i Vector containing mouse position
         */
        sf::Vector2i get_mouse_position(sf::RenderWindow &window);
    };
}

#endif