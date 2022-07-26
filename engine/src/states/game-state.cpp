#include "states/game-state.hpp"
#include "states/menu-state.hpp"
#include "states/pause-state.hpp"
#include "definitions.hpp"

#include <iostream>

namespace pte
{
    GameState::GameState(game_data_ref data) : data(data)
    {
    }

    void GameState::init()
    {
        game_state = STATE_PLAYING;
        turn = PLAYER_PIECE;

        this->data->assets.load_texture("Pause Button", PAUSE_BUTTON);

        background.setTexture(this->data->assets.get_texture("Background"));
        pause_button.setTexture(this->data->assets.get_texture("Pause Button"));

        pause_button.setPosition(this->data->window.getSize().x - pause_button.getLocalBounds().width, pause_button.getPosition().y);
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
                std::cout << "Pause The Game" << std::endl;
                this->data->machine.add_state(state_ref(new PauseState(data)), false);
            }
        }
    }

    void GameState::update(float delta_time)
    {
    }

    void GameState::draw(float delta_time)
    {
        this->data->window.clear(sf::Color::Magenta);
        this->data->window.draw(this->background);
        this->data->window.draw(this->pause_button);
        this->data->window.display();
    }
}