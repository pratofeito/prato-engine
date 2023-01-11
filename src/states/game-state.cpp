#include "states/game-state.hpp"

void GameState::init()
{
    assets->load_texture("pause_button", PAUSE_BUTTON);
    pause_button.setTexture(assets->get_texture("pause_button"));
    pause_button.setPosition(window->getSize().x - pause_button.getLocalBounds().width - 10, pause_button.getPosition().y + 10);

    // view
    // view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    default_view = window->getView();
    // posso usar o .reset(). também o setCenter e setSize
    view = sf::View(sf::FloatRect(200, 200, 320, 240));
    // view.rotate(20.f);
    scale = 1;

    // init player
    player.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    player.setFillColor(sf::Color::White);
    player_pos.x = 10;
    player_pos.y = 10;
    moving = false;
    moving_elapsed_time = 0;

    // start player movement position
    player_pos_end.x = player_pos.x * PLAYER_SIZE;
    player_pos_end.y = player_pos.y * PLAYER_SIZE;

    // init guidelines
    for (int i = 0; i < WIDTH; i++)
    {
        guide_x[i].setSize(sf::Vector2f(1, SCREEN_HEIGHT));
        guide_x[i].setFillColor(sf::Color::Black);
        guide_x[i].setPosition((i * PLAYER_SIZE) - (PLAYER_SIZE / 2), 0);
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        guide_y[i].setSize(sf::Vector2f(SCREEN_WIDTH, 1));
        guide_y[i].setFillColor(sf::Color::Black);
        guide_y[i].setPosition(0, (i * PLAYER_SIZE) - (PLAYER_SIZE / 2));
    }
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        {
            view.zoom(0.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        {
            view.zoom(2);
        }

        if (input->is_sprite_clicked(this->pause_button, sf::Mouse::Left, *window))
        {
            // PAUSE
            add_state<PauseState>(false);
        }

        // player input

        if (sf::Event::EventType::KeyPressed == event.type)
        {
            system("clear");
            if (sf::Keyboard::Left == event.key.code)
            {
                std::cout << "ESQ" << std::endl;
                move_adjacent_tile(-1, 0);
            }
            else if (sf::Keyboard::Right == event.key.code)
            {
                std::cout << "DIR" << std::endl;
                move_adjacent_tile(1, 0);
            }
            else if (sf::Keyboard::Up == event.key.code)
            {
                std::cout << "TOP" << std::endl;
                move_adjacent_tile(0, -1);
            }
            else if (sf::Keyboard::Down == event.key.code)
            {
                std::cout << "DOW" << std::endl;
                move_adjacent_tile(0, 1);
            }
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        // {
        //     move_adjacent_tile(-1, 0);
        // }
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        // {
        //     move_adjacent_tile(1, 0);
        // }
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        // {
        //     move_adjacent_tile(0, -1);
        // }
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        // {
        //     move_adjacent_tile(0, 1);
        // }
    }
}

void GameState::update(float delta_time)
{
    // update player position
    new_player_pos = update_movement(delta_time);
    // player.setPosition(new_player_pos.x, new_player_pos.y);

    // set player to center and update view
    player.setPosition(new_player_pos.x - (PLAYER_SIZE / 2), new_player_pos.y - (PLAYER_SIZE / 2));
    view.setCenter(new_player_pos.x, new_player_pos.y);
}

void GameState::draw(float delta_time)
{
    window->clear(sf::Color(56, 42, 55));

    // view
    window->setView(view);

    // player
    // window->draw(player);

    // guidelines
    for (int i = 1; i < WIDTH; i++)
    {
        window->draw(guide_x[i]);
    }
    for (int i = 1; i < HEIGHT; i++)
    {
        window->draw(guide_y[i]);
    }

    window->draw(player);

    // default view
    window->setView(default_view);

    window->draw(this->pause_button);
    window->display();
}

// ------------------- custom -------------------

void GameState::move_adjacent_tile(int x, int y)
{
    if (!moving)
    {
        sf::Vector2i start_pos = sf::Vector2i(player_pos.x * PLAYER_SIZE, player_pos.y * PLAYER_SIZE);
        sf::Vector2i end_pos = sf::Vector2i((player_pos.x + x) * PLAYER_SIZE, (player_pos.y + y) * PLAYER_SIZE);

        if (move(start_pos, end_pos))
        {
            player_pos.x += x;
            player_pos.y += y;
        }
    }
}

bool GameState::move(sf::Vector2i player_pos_start, sf::Vector2i player_pos_end)
{
    if (!moving)
    {
        moving = true;
        this->player_pos_start = player_pos_start;
        this->player_pos_end = player_pos_end;
        moving_elapsed_time = 0;

        return true;
    }

    return false;
}

sf::Vector2i GameState::update_movement(float delta_time)
{
    if (!moving)
    {
        return player_pos_end;
    }

    sf::Vector2i transition_pos = player_pos_start;
    moving_elapsed_time += delta_time;

    transition_pos.x += (moving_elapsed_time * (player_pos_end.x - player_pos_start.x)) / (SPEED * 0.2);
    transition_pos.y += (moving_elapsed_time * (player_pos_end.y - player_pos_start.y)) / (SPEED * 0.2);

    bool l_overflow = std::abs(transition_pos.x - player_pos_start.x) >= std::abs(player_pos_end.x - player_pos_start.x);
    bool r_overflow = std::abs(transition_pos.y - player_pos_start.y) >= std::abs(player_pos_end.y - player_pos_start.y);

    if (l_overflow && r_overflow)
    {
        moving = false;
        return player_pos_end;
    }

    return transition_pos;
}