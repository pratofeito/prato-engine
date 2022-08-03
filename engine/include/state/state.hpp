#ifndef PTE_STATE_HPP
#define PTE_STATE_HPP

namespace pte
{
    class State
    {
    public:
        virtual void init() = 0;
        virtual void handle_input() = 0;

        virtual void update(float delta_time) = 0;
        virtual void draw(float delta_time) = 0;

        virtual void pause() {}
        virtual void resume() {}
    };
}

#endif