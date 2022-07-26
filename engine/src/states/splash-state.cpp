#include "states/splash-state.hpp"
#include "states/menu-state.hpp"

namespace pte
{
    SplashState::SplashState(game_data_ref data) : data(data)
    {
    }

    void SplashState::init()
    {
        this->data->assets.load_texture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

        background.setTexture(this->data->assets.get_texture("Splash State Background"));
    }

    void SplashState::handle_input()
    {
        sf::Event event;

        while (this->data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->data->window.close();
            }
        }
    }

    void SplashState::update(float delta_time)
    {
        if (this->clock.getElapsedTime().asSeconds() > 3)
        {
            // Switch To Main Menu
            // std::cout << "Go To Main Menu" << std::endl;
            this->data->machine.add_state(state_ref(new MainMenuState(data)), true);
        }
    }

    void SplashState::draw(float delta_time)
    {
        this->data->window.clear(sf::Color::Red);
        this->data->window.draw(this->background);
        this->data->window.display();
    }
}