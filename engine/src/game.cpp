#include "game.hpp"
#include "states/splash-state.hpp"

namespace pte
{
    Game::Game(int width, int height, std::string title)
    {
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        data->machine.add_state(state_ref(new SplashState(this->data)), true);
        this->run();
    }

    void Game::run()
    {
        float new_time, frame_time, interpolation;
        float current_time = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->data->window.isOpen())
        {
            this->data->machine.process_state_changes();

            new_time = this->clock.getElapsedTime().asSeconds();
            frame_time = new_time - current_time;

            if (frame_time > 0.25f)
            {
                frame_time = 0.25f;
            }

            current_time = new_time;
            accumulator += frame_time;

            while (accumulator >= delta_time)
            {
                this->data->machine.get_active_state()->handle_input();
                this->data->machine.get_active_state()->update(delta_time);

                accumulator -= delta_time;
            }

            interpolation = accumulator / delta_time;
            this->data->machine.get_active_state()->draw(interpolation);
        }
    }
}