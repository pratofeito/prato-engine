#include "states/menu-state.hpp"

MainMenuState::MainMenuState(pte::game_data_ref data) : data(data)
{
}

void MainMenuState::init()
{
    // setup title
    this->data->assets.load_font("default_font", DEFAULT_FONT_PATH);
    this->title.setFont(this->data->assets.get_font("default_font"));
    this->title.setString("MAIN MENU");
    this->title.setCharacterSize(55);
    this->title.setFillColor(sf::Color::White);
    this->title.setPosition((SCREEN_WIDTH / 2) - (this->title.getGlobalBounds().width / 2), SCREEN_HEIGHT * 0.2);

    // setup play button
    this->data->assets.load_texture("play_button", MAIN_MENU_PLAY_BUTTON);
    this->play_button.setTexture(this->data->assets.get_texture("play_button"));
    this->play_button.setPosition((SCREEN_WIDTH / 2) - (this->play_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) + this->play_button.getGlobalBounds().height);

    // setup quit button
    this->data->assets.load_texture("quit_button", MAIN_MENU_QUIT_BUTTON);
    this->quit_button.setTexture(this->data->assets.get_texture("quit_button"));
    this->quit_button.setPosition((SCREEN_WIDTH / 2) - (this->quit_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) + this->quit_button.getGlobalBounds().height * 2.2);
}

void MainMenuState::handle_input()
{
    sf::Event event;

    while (this->data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type || this->data->input.is_sprite_clicked(this->quit_button, sf::Mouse::Left, this->data->window))
        {
            this->data->window.close();
        }

        if (this->data->input.is_sprite_clicked(this->play_button, sf::Mouse::Left, this->data->window))
        {
            this->data->state_handler.add_state(pte::state_ref(new GameState(this->data)), true);
        }
    }
}

void MainMenuState::update(float delta_time)
{
}

void MainMenuState::draw(float delta_time)
{
    this->data->window.clear(sf::Color(65, 11, 95));

    this->data->window.draw(this->title);
    this->data->window.draw(this->play_button);
    this->data->window.draw(this->quit_button);

    this->data->window.display();
}
