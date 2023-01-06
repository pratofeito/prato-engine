#include "states/splash-state.hpp"

void SplashState::init()
{
    assets->load_texture("splash_scene_background", SPLASH_SCENE_BACKGROUND_FILEPATH);

    background.setTexture(assets->get_texture("splash_scene_background"));
    background.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (background.getLocalBounds().width / 2), (SCREEN_HEIGHT / 2) - (background.getLocalBounds().height / 2)));
}

void SplashState::handle_input()
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            window->close();
        }
    }
}

void SplashState::update(float delta_time)
{
    if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu
        add_state<MainMenuState>(true);
    }
}

void SplashState::draw(float delta_time)
{
    window->clear(sf::Color::White);
    window->draw(this->background);
    window->display();
}
