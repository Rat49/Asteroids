#pragma once
#include <Engine/Exports.h>
#include <Engine/UpdateMethod.h>
#include <vector>
#include <cstdint>
#include <SFML/Window/Keyboard.hpp>

enum class ActionState
{
    InStill = 0,
    JustLeft,
    JustEntered,
    InAction,
};

class ENGINE_EXPORT InputSystem final : UpdateMethod
{
public:
    InputSystem();
    ~InputSystem() override;

    void BindAction(int32_t action, sf::Keyboard::Key key);
    void UnbindAction(int32_t action);

    ActionState GetState(int32_t action) const;
    ActionState operator[](int32_t action) const;
    bool IsPressed(int32_t action) const;

    void OnUpdate(float deltaTime) override;

private:
    struct KeyboardInput
    {
        sf::Keyboard::Key Key;
        sf::Keyboard::Key Alt;
        int32_t Action;
        ActionState State;

        bool operator<(const KeyboardInput& other) const;
        bool operator==(const KeyboardInput& other) const;
    };

    std::vector<KeyboardInput> mKeyboardInput;
};
