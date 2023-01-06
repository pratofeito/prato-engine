#ifndef PTE_GAME_HPP
#define PTE_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "state-handler.hpp"
#include "asset-manager.hpp"
#include "input-manager.hpp"

namespace pte
{
    class GameData
    {
    public:
        StateHandler state_handler;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> game_data_ref;

    class Game
    {
    private:
        const float delta_time = 1.0f / 30.0f; // 30fps
        sf::Clock clock;

        game_data_ref data = std::make_shared<GameData>();

    public:
        Game(int width, int height, std::string title);
        void run();

        template <class T_state>
        void init_state()
        {
            // start a new splash state
            data->state_handler.add_state(state_ref(new T_state(this->data)), true);
        }
    };

}

#endif