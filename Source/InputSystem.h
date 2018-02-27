#pragma once
#include "UpdateMethod.h"
#include "InputGameAction.h"
#include <vector>
#include <SFML/Window/Keyboard.hpp>

enum class ActionState
{
    InStill = 0,
    JustLeft,
    JustEntered,
    InAction,
};

class InputSystem final : UpdateMethod
{
public:
    InputSystem();
    ~InputSystem() override;

    void BindAction(GameAction action, sf::Keyboard::Key key);
    void UnbindAction(GameAction action);

    ActionState GetState(GameAction action) const;
    ActionState operator[](GameAction action) const;

    void OnUpdate(float deltaTime) override;

private:
    struct KeyboardInput
    {
        sf::Keyboard::Key Key;
        sf::Keyboard::Key Alt;
        GameAction Action;
        ActionState State;

        bool operator<(const KeyboardInput& other) const;
        bool operator==(const KeyboardInput& other) const;
    };

    std::vector<KeyboardInput> mKeyboardInput;
};
