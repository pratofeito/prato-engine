#ifndef PTE_SPLASH_STATE_HPP
#define PTE_SPLASH_STATE_HPP

#include "engine/include/generic-state.hpp"
#include "states/menu-state.hpp"
#include "definitions.hpp"

class SplashState : public pte::GenericState
{

public:
    using GenericState::GenericState;

    void init();
    void handle_input();
    void update(float delta_time);
    void draw(float delta_time);
};

#endif