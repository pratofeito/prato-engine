#include "states/game-state.hpp"

void GameState::init()
{
    assets->load_texture("pause_button", PAUSE_BUTTON);
    pause_button.setTexture(assets->get_texture("pause_button"));
    pause_button.setPosition(window->getSize().x - pause_button.getLocalBounds().width - 10, pause_button.getPosition().y + 10);

    init_ball();
}

void GameState::handle_input()
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            window->close();
        }

        if (input->is_sprite_clicked(this->pause_button, sf::Mouse::Left, *window))
        {
            // PAUSE
            add_state<PauseState>(false);
        }
    }
}

void GameState::update(float delta_time)
{
    update_ball(delta_time);
}

void GameState::draw(float delta_time)
{
    window->clear(sf::Color(56, 42, 55));
    window->draw(this->ball);
    window->draw(this->pause_button);
    window->display();
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