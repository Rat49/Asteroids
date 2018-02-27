#include "InputSystem.h"
#include <algorithm>

bool InputSystem::KeyboardInput::operator<(const InputSystem::KeyboardInput& other) const
{
    return static_cast<int>(Action) < static_cast<int>(other.Action);
}

bool InputSystem::KeyboardInput::operator==(const InputSystem::KeyboardInput& other) const
{
    return Action == other.Action;
}

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::BindAction(GameAction action, sf::Keyboard::Key key)
{
    const KeyboardInput tmp{ sf::Keyboard::Unknown, sf::Keyboard::Unknown, action, ActionState::InStill };
    auto it = std::lower_bound(mKeyboardInput.begin(), mKeyboardInput.end(), tmp);
    if (it == mKeyboardInput.end() || it->Action != action)
    {
        it = mKeyboardInput.insert(it, tmp);
    }

    if (it->Key == sf::Keyboard::Unknown)
    {
        it->Key = key;
        return;
    }

    if (it->Alt == sf::Keyboard::Unknown)
    {
        it->Alt = key;
        return;
    }

    //error. all keys already set.
}

void InputSystem::UnbindAction(GameAction action)
{
    const KeyboardInput tmp{ sf::Keyboard::Unknown, sf::Keyboard::Unknown, action, ActionState::InStill };
    auto it = std::find(mKeyboardInput.cbegin(), mKeyboardInput.cend(), tmp);
    if (it == mKeyboardInput.cend())
    {
        return;
    }

    mKeyboardInput.erase(it);
}

ActionState InputSystem::GetState(GameAction action) const
{
    const KeyboardInput tmp{ sf::Keyboard::Unknown, sf::Keyboard::Unknown, action, ActionState::InStill };
    auto it = std::lower_bound(mKeyboardInput.cbegin(), mKeyboardInput.cend(), tmp);
    if (it == mKeyboardInput.cend())
    {
        return ActionState::InStill;
    }

    return it->State;
}

ActionState InputSystem::operator[](GameAction action) const
{
    return GetState(action);
}

void InputSystem::OnUpdate(float)
{
    bool state;
    for (auto& kbi : mKeyboardInput)
    {
        state = sf::Keyboard::isKeyPressed(kbi.Key);
        if (sf::Keyboard::Unknown != kbi.Alt)
        {
            state |= sf::Keyboard::isKeyPressed(kbi.Alt);
        }

        if (state)
        {
            switch (kbi.State)
            {
            case ActionState::JustLeft:
            case ActionState::InStill:
                kbi.State = ActionState::JustEntered;
                break;
            case ActionState::JustEntered:
                kbi.State = ActionState::InAction;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (kbi.State)
            {
            case ActionState::InAction:
            case ActionState::JustEntered:
                kbi.State = ActionState::JustLeft;
                break;
            case ActionState::JustLeft:
                kbi.State = ActionState::InStill;
                break;
            default:
                break;
            }
        }
    }
}
