/**
 * @file game.hpp
 * @date 2023-01-06
 * 
 * @brief The game. Has the definitions of the data, controls gameloop and start other handlers.
 * 
 */

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

        /**
         * @brief Construct a new Game object
         * 
         * @param width Window width
         * @param height Window Height
         * @param title Window title
         */
        Game(int width, int height, std::string title);

        /// @brief Start the game
        void run();

        /**
         * @brief Start the fisrt state, defining the game data in it
         * 
         * @tparam T_state State class
         */
        template <class T_state>
        void init_state()
        {
            // start the first state, with the game data from this instance
            data->state_handler.add_state(state_ref(new T_state(this->data)), true);
        }
    };

}

#endif