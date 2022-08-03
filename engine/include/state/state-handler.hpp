#ifndef PTE_STATE_HANDLER_HPP
#define PTE_STATE_HANDLER_HPP

#include <memory>
#include <stack> 
#include "state/state.hpp"

namespace pte
{
    typedef std::unique_ptr<State> state_ref;

    class StateHandler
    {
    private:
        std::stack<state_ref> states;
        state_ref new_state;

        bool removing;
        bool adding;
        bool replacing;

    public:
        StateHandler() {}
        ~StateHandler() {}

        void add_state(state_ref new_state, bool replacing);
        void remove_state();
        void process_state_changes();
        bool have_state_active();
        
        state_ref &get_active_state();
    };
}

#endif