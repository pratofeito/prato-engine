#include "states/menu-state.hpp"
#include "states/game-state.hpp"
#include "definitions.hpp"

namespace pte
{
    MainMenuState::MainMenuState(game_data_ref data) : data(data)
    {
    }

    void MainMenuState::init()
    {
        this->data->assets.load_texture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->data->assets.load_texture("Play Button", MAIN_MENU_PLAY_BUTTON);
        this->data->assets.load_texture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
        this->data->assets.load_texture("Game Title", MAIN_MENU_TITLE_FILEPATH);

        this->background.setTexture(this->data->assets.get_texture("Background"));
        this->play_button.setTexture(this->data->assets.get_texture("Play Button"));
        this->play_button_outer.setTexture(this->data->assets.get_texture("Play Button Outer"));
        this->title.setTexture(this->data->assets.get_texture("Game Title"));

        this->play_button.setPosition((SCREEN_WIDTH / 2) - (this->play_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->play_button.getGlobalBounds().height / 2));
        this->play_button_outer.setPosition((SCREEN_WIDTH / 2) - (this->play_button_outer.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->play_button_outer.getGlobalBounds().height / 2));

        this->title.setPosition((SCREEN_WIDTH / 2) - (this->title.getGlobalBounds().width / 2), this->title.getGlobalBounds().height * 0.1);
    }

    void MainMenuState::handle_input()
    {
        sf::Event event;

        while (this->data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->data->window.close();
            }

            if (this->data->input.is_sprite_clicked(this->play_button, sf::Mouse::Left, this->data->window))
            {
                std::cout << "Go To Game Screen" << std::endl;
                this->data->machine.add_state(state_ref(new GameState(data)), true);
            }
        }
    }

    void MainMenuState::update(float delta_time)
    {
    }

    void MainMenuState::draw(float delta_time)
    {
        this->data->window.clear(sf::Color::Cyan);

        this->data->window.draw(this->background);
        this->data->window.draw(this->play_button);
        this->data->window.draw(this->play_button_outer);
        this->data->window.draw(this->title);

        this->data->window.display();
    }
}