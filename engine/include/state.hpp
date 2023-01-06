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

        // template <class T>
        // void add_state(pte::game_data_ref datas, bool replacing)
        // {
        //     datas->state_handler.add_state(pte::state_ref(new T(datas)), replacing);
        // }
    };
}

#endif