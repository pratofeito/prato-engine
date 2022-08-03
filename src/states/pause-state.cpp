#include "states/pause-state.hpp"

PauseState::PauseState(pte::game_data_ref data) : data(data)
{
}

void PauseState::init()
{
	// setup title
	this->data->assets.load_font("default_font", DEFAULT_FONT_PATH);
	this->title.setFont(this->data->assets.get_font("default_font"));
	this->title.setString("PAUSE MENU");
	this->title.setCharacterSize(55);
	this->title.setFillColor(sf::Color::White);
	this->title.setPosition((SCREEN_WIDTH / 2) - (this->title.getGlobalBounds().width / 2), SCREEN_HEIGHT * 0.2);

	// setup play button
	this->data->assets.load_texture("resume_button", PAUSE_MENU_RESUME_BUTTON);
	this->resume_button.setTexture(this->data->assets.get_texture("resume_button"));
	this->resume_button.setPosition((SCREEN_WIDTH / 2) - (this->resume_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) + this->resume_button.getGlobalBounds().height);

	// setup quit button
	this->data->assets.load_texture("home_button", PAUSE_MENU_HOME_BUTTON);
	this->home_button.setTexture(this->data->assets.get_texture("home_button"));
	this->home_button.setPosition((SCREEN_WIDTH / 2) - (this->home_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) + this->home_button.getGlobalBounds().height * 2.2);
}

void PauseState::handle_input()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}

		if (this->data->input.is_sprite_clicked(this->resume_button, sf::Mouse::Left, this->data->window))
		{
			// Resume Game By Popping Of The Current State (Pause State)
			this->data->state_handler.remove_state();
		}

		if (this->data->input.is_sprite_clicked(this->home_button, sf::Mouse::Left, this->data->window))
		{
			// Remove The Pause State Off The Stack
			this->data->state_handler.remove_state();

			// Switch To Main Menu State By Replacing The Game State
			this->data->state_handler.add_state(pte::state_ref(new MainMenuState(data)), true);
		}
	}
}

void PauseState::update(float delta_time)
{
}

void PauseState::draw(float delta_time)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->title);
	this->data->window.draw(this->resume_button);
	this->data->window.draw(this->home_button);

	this->data->window.display();
}
