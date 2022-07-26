#include "states/pause-state.hpp"
#include "states/game-state.hpp"
#include "states/menu-state.hpp"
#include "definitions.hpp"

namespace pte
{
	PauseState::PauseState(game_data_ref data) : data(data)
	{
	}

	void PauseState::init()
	{
		this->data->assets.load_texture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->data->assets.load_texture("Resume Button", RESUME_BUTTON);
		this->data->assets.load_texture("Home Button", HOME_BUTTON);

		this->background.setTexture(this->data->assets.get_texture("Pause Background"));
		this->resume_button.setTexture(this->data->assets.get_texture("Resume Button"));
		this->home_button.setTexture(this->data->assets.get_texture("Home Button"));

		this->resume_button.setPosition((this->data->window.getSize().x / 2) - (this->resume_button.getLocalBounds().width / 2), (this->data->window.getSize().y / 3) - (this->resume_button.getLocalBounds().height / 2));
		this->home_button.setPosition((this->data->window.getSize().x / 2) - (this->home_button.getLocalBounds().width / 2), (this->data->window.getSize().y / 3 * 2) - (this->home_button.getLocalBounds().height / 2));
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
				this->data->machine.remove_state();
			}

			if (this->data->input.is_sprite_clicked(this->home_button, sf::Mouse::Left, this->data->window))
			{
				// Remove The Pause State Off The Stack
				this->data->machine.remove_state();

				// Switch To Main Menu State By Replacing The Game State
				this->data->machine.add_state(state_ref(new MainMenuState(data)), true);
			}
		}
	}

	void PauseState::update(float dt)
	{
	}

	void PauseState::draw(float dt)
	{
		this->data->window.clear(sf::Color::Red);

		this->data->window.draw(this->background);
		this->data->window.draw(this->resume_button);
		this->data->window.draw(this->home_button);

		this->data->window.display();
	}
}