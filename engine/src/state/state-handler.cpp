#include "state/state-handler.hpp"
#include <iostream>

namespace pte
{
    void StateHandler::add_state(state_ref new_state, bool replacing = true)
    {
        this->adding = true;
        this->replacing = replacing;
        this->new_state = std::move(new_state);
    }

    void StateHandler::remove_state()
    {
        this->removing = true;
    }

    void StateHandler::process_state_changes()
    {
        if (this->removing && !this->states.empty())
        {
            this->states.pop();

            if (!this->states.empty())
            {
                this->states.top()->resume();
            }

            this->removing = false;
        }

        if (this->adding)
        {
            if (!this->states.empty())
            {
                if (this->replacing)
                {
                    this->states.pop();
                }
                else
                {
                    this->states.top()->pause();
                }
            }

            this->states.push(std::move(this->new_state));
            this->states.top()->init();
            this->adding = false;
        }
    }

    state_ref &StateHandler::get_active_state()
    {
        return this->states.top();
    }

    bool StateHandler::have_state_active()
    {
        if (this->new_state == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}