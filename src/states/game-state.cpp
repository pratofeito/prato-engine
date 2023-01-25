#include "states/game-state.hpp"

void GameState::init()
{
    window->setFramerateLimit(60);

    assets->load_texture("pause_button", PAUSE_BUTTON);
    pause_button.setTexture(assets->get_texture("pause_button"));
    pause_button.setPosition(window->getSize().x - pause_button.getLocalBounds().width - 10, pause_button.getPosition().y + 10);

    // view
    default_view = window->getView();
    view = sf::View(sf::FloatRect(200, 200, 320, 240)); // posso usar o .reset(). também o setCenter e setSize

    // init player
    player.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    player.setFillColor(sf::Color::White);
    player_pos.x = 10;
    player_pos.y = 10;
    moving = false;
    moving_elapsed_time = 0;

    // movement
    center.x = (player_pos.x * TILE_SIZE) + (TILE_SIZE / 2);
    center.y = (player_pos.y * TILE_SIZE) + (TILE_SIZE / 2);

    // start player movement position
    pos_end.x = player_pos.x * TILE_SIZE;
    pos_end.y = player_pos.y * TILE_SIZE;

    // init guidelines
    for (int i = 0; i < WIDTH; i++)
    {
        guide_x[i].setSize(sf::Vector2f(1, SCREEN_HEIGHT));
        guide_x[i].setFillColor(sf::Color::Black);
        guide_x[i].setPosition((i * TILE_SIZE), 0);
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        guide_y[i].setSize(sf::Vector2f(SCREEN_WIDTH, 1));
        guide_y[i].setFillColor(sf::Color::Black);
        guide_y[i].setPosition(0, (i * TILE_SIZE));
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

        if (input->is_sprite_clicked(this->pause_button, sf::Mouse::Left, *window))
        {
            // PAUSE
            add_state<PauseState>(false);
        }

        // zoom
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        {
            view.zoom(0.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        {
            view.zoom(2);
        }
    }

    // new input system using stack
    int last_key_pressed = update_control();

    // what to do
    if (last_key_pressed == sf::Keyboard::Left)
    {
        move_adjacent_tile(-1, 0);
    }
    else if (last_key_pressed == sf::Keyboard::Right)
    {
        move_adjacent_tile(1, 0);
    }
    else if (last_key_pressed == sf::Keyboard::Up)
    {
        move_adjacent_tile(0, -1);
    }
    else if (last_key_pressed == sf::Keyboard::Down)
    {
        move_adjacent_tile(0, 1);
    }

}

void GameState::update(float delta_time)
{
    // update player position
    sf::Vector2i center_update = update_movement(delta_time);

    // set player to center and update view
    player.setPosition(center_update.x - (TILE_SIZE / 2), center_update.y - (TILE_SIZE / 2));
    view.setCenter(center_update.x, center_update.y);
}

void GameState::draw(float delta_time)
{
    window->clear(sf::Color(56, 42, 55));

    // view
    window->setView(view);

    // guidelines
    for (int i = 1; i < WIDTH; i++)
    {
        window->draw(guide_x[i]);
    }
    for (int i = 1; i < HEIGHT; i++)
    {
        window->draw(guide_y[i]);
    }

    // player
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
        sf::Vector2i pos_after_move = sf::Vector2i(center.x + (x * TILE_SIZE), center.y + (y * TILE_SIZE));

        moving = true;
        this->pos_start = center;
        this->pos_end = pos_after_move;
        moving_elapsed_time = 0;
    }
}

sf::Vector2i GameState::update_movement(float delta_time)
{
    if (!moving)
    {
        return center;
    }

    sf::Vector2i transition_pos = center;
    moving_elapsed_time += delta_time;

    transition_pos.x += (moving_elapsed_time * (pos_end.x - pos_start.x)) / SPEED;
    transition_pos.y += (moving_elapsed_time * (pos_end.y - pos_start.y)) / SPEED;

    if (moving_elapsed_time >= SPEED)
    {
        moving = false;
        center = pos_end;
        return center;
    }

    return transition_pos;
}

// ------------------- stack -------------------

void GameState::push_stack(int input)
{
    if (key_stack.empty())
    {
        key_stack.push_back(input);
        return;
    }

    for (int i = 0; i < (int)key_stack.size(); i++)
    {
        if (key_stack[i] == input)
        {
            return;
        }
    }

    key_stack.push_back(input);
}

void GameState::del_stack(int input)
{
    for (int i = 0; i < (int)key_stack.size(); i++)
    {
        if (key_stack[i] == input)
        {
            key_stack.erase(key_stack.begin() + i);
        }
    }
}

int GameState::update_control()
{
    // left update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        push_stack(sf::Keyboard::Left);
    else
        del_stack(sf::Keyboard::Left);

    // right update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        push_stack(sf::Keyboard::Right);
    else
        del_stack(sf::Keyboard::Right);

    // up update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        push_stack(sf::Keyboard::Up);
    else
        del_stack(sf::Keyboard::Up);

    // down update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        push_stack(sf::Keyboard::Down);
    else
        del_stack(sf::Keyboard::Down);

    // return the last key pressed
    if (!key_stack.empty())
        return key_stack.back();
    else
        return 0;
}