#ifndef PTE_GAME_HPP
#define PTE_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "state/state-handler.hpp"
#include "asset-manager/asset-manager.hpp"
#include "input-manager/input-manager.hpp"

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

    class Game
    {
    private:
        const float delta_time = 1.0f / 30.0f; // 30fps
        sf::Clock clock;

        game_data_ref data = std::make_shared<game_data>();

        void run();

    public:
        Game(int width, int height, std::string title);
    };

}

#endif