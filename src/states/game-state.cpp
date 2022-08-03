#include "states/game-state.hpp"

GameState::GameState(pte::game_data_ref data) : data(data)
{
}

void GameState::init()
{
    this->data->assets.load_texture("Pause Button", PAUSE_BUTTON);
    pause_button.setTexture(this->data->assets.get_texture("Pause Button"));
    pause_button.setPosition(this->data->window.getSize().x - pause_button.getLocalBounds().width - 10, pause_button.getPosition().y + 10);
}

void GameState::handle_input()
{
    sf::Event event;

    while (this->data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->data->window.close();
        }

        if (this->data->input.is_sprite_clicked(this->pause_button, sf::Mouse::Left, this->data->window))
        {
            // PAUSE
            this->data->state_handler.add_state(pte::state_ref(new PauseState(data)), false);
        }
    }
}

void GameState::update(float delta_time)
{
}

void GameState::draw(float delta_time)
{
    this->data->window.clear(sf::Color(56, 42, 55));
    this->data->window.draw(this->pause_button);
    this->data->window.display();
}
