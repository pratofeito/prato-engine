#include "states/splash-state.hpp"

SplashState::SplashState(pte::game_data_ref data) : data(data)
{
}

void SplashState::init()
{
    this->data->assets.load_texture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

    background.setTexture(this->data->assets.get_texture("Splash State Background"));
    background.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (background.getLocalBounds().width / 2), (SCREEN_HEIGHT / 2) - (background.getLocalBounds().height / 2)));
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
    if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu
        this->data->state_handler.add_state(pte::state_ref(new MainMenuState(data)), true);
    }
}

void SplashState::draw(float delta_time)
{
    this->data->window.clear(sf::Color::White);
    this->data->window.draw(this->background);
    this->data->window.display();
}
