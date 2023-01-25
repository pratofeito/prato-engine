/**
 * @file game-state.hpp
 * @date 2023-01-06
 * 
 * @brief Example game state. Runs a bouncing ball demo.
 * 
 */

#ifndef PTE_GAME_STATE_HPP
#define PTE_GAME_STATE_HPP

#include <cmath>
#include "engine/include/generic-state.hpp"
#include "states/pause-state.hpp"
#include "definitions.hpp"


#define TILE_SIZE 32
#define WIDTH SCREEN_WIDTH / TILE_SIZE
#define HEIGHT SCREEN_HEIGHT / TILE_SIZE
#define SPEED 0.6

class GameState : public pte::GenericState
{
private:
    sf::Sprite pause_button;

    // input stack
    std::vector<int> key_stack;
    void push_stack(int input);
    void del_stack(int input);
    int update_control();

    // view
    sf::View default_view;
    sf::View view;

    // player
    sf::RectangleShape player;
    sf::Vector2i player_pos;
    sf::Vector2i new_player_pos;

    // movement
    bool moving;
    float moving_elapsed_time;
    sf::Vector2i pos_start;
    sf::Vector2i pos_end;
    sf::Vector2i center;

    // guidelines
    sf::RectangleShape guide_x[WIDTH];
    sf::RectangleShape guide_y[HEIGHT];

public:
    using GenericState::GenericState;

    void init();
    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);

    // movement methods
    void move_adjacent_tile(int x, int y);
    sf::Vector2i update_movement(float delta_time);
};

#endif