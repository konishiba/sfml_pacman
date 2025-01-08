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
            for (const InputData& _inputData : inputDatas )
            {
                if (_inputData.TryToExecute(_key)) break;
            }
        }
    }
}

void InputManager::BindAction(const function<void()>& _callback, const Code& _code)
{
    inputDatas.push_back(InputData(_callback, { _code }));
}

void InputManager::BindAction(const function<void()>& _callback, const vector<Code>& _codes)
{
    inputDatas.push_back(InputData(_callback, _codes, _codes.empty()));
}

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}
