#include "InputManager.h"

void InputManager::ConsumeInput(RenderWindow& _window)
{
    while (const std::optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            _window.close();
        }

        else if (const KeyPressed* _key = _event->getIf<KeyPressed>())
        {
            for (InputData& _inputData : inputsData)
            {
                _inputData.TryToExecute(_key);
            }

        }
    }
}

void InputManager::BindAction(const vector<Code>& _codes, const function<void()>& _callback)
{
    inputsData.push_back(InputData(_callback, _codes, _codes.empty()));
}

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}


