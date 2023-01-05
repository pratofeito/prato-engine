#ifndef PTE_GAME_HPP
#define PTE_GAME_HPP

#include <memory>
#include <string>
#include "game-data.hpp"

namespace pte
{

    class Game
    {
    private:
        const float delta_time = 1.0f / 30.0f; // 30fps
        sf::Clock clock;

        game_data_ref data = std::make_shared<game_data>();

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