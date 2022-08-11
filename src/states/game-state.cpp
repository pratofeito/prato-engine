#include "states/game-state.hpp"

GameState::GameState(pte::game_data_ref data) : data(data)
{
}

void GameState::init()
{
    this->data->assets.load_texture("Pause Button", PAUSE_BUTTON);
    pause_button.setTexture(this->data->assets.get_texture("Pause Button"));
    pause_button.setPosition(this->data->window.getSize().x - pause_button.getLocalBounds().width - 10, pause_button.getPosition().y + 10);

    init_ball();
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
    update_ball(delta_time);
}

void GameState::draw(float delta_time)
{
    this->data->window.clear(sf::Color(56, 42, 55));
    this->data->window.draw(this->ball);
    this->data->window.draw(this->pause_button);
    this->data->window.display();
}

void GameState::init_ball()
{
    ball.setRadius(ballRadius - 3);
    ball.setOutlineThickness(3);
    ball.setOutlineColor(sf::Color::White);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);
    ball.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    do
    {
        ballAngle = (std::rand() % 360) * 2 * pi / 360;
    } while (std::abs(std::cos(ballAngle)) < 0.7f);
}

void GameState::update_ball(float delta_time)
{
    // move ball
    float factor = ballSpeed * delta_time;
    ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);

    // check colisions
    if (ball.getPosition().x - ballRadius < 0.f)
    {
        ballAngle = -ballAngle + pi;
        ball.setPosition(ballRadius + 0.1f, ball.getPosition().y);
    }
    if (ball.getPosition().x + ballRadius > SCREEN_WIDTH)
    {
        ballAngle = -ballAngle + pi;
        ball.setPosition(SCREEN_WIDTH - ballRadius - 0.1f, ball.getPosition().y);
    }
    if (ball.getPosition().y - ballRadius < 0.f)
    {
        ballAngle = -ballAngle;
        ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);
    }
    if (ball.getPosition().y + ballRadius > SCREEN_HEIGHT)
    {
        ballAngle = -ballAngle;
        ball.setPosition(ball.getPosition().x, SCREEN_HEIGHT - ballRadius - 0.1f);
    }
}