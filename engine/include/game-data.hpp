#ifndef PTE_GAME_DATA_HPP
#define PTE_GAME_DATA_HPP

#include <SFML/Graphics.hpp>
#include "state-handler.hpp"
#include "asset-manager.hpp"
#include "input-manager.hpp"

namespace pte
{
    struct game_data
    {
        StateHandler state_handler;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<game_data> game_data_ref;
}

#endif