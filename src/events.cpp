#include <iostream>
#include <string>

#include "../include/events.hpp"

// MouseEvent implementation
MouseEvent::MouseEvent(int x, int y, int button) : _x(x), _y(y), _button(button) {}

void MouseEvent::Handle()
{
        std::cout << "Mouse Event: (" << _x << ", " << _y << ") Button: " << _button << std::endl;
}

int MouseEvent::GetX() const { return _x; }
int MouseEvent::GetY() const { return _y; }
int MouseEvent::GetButton() const { return _button; }

// KeyboardEvent implementation
KeyboardEvent::KeyboardEvent(char key) : _key(key) {}

void KeyboardEvent::Handle()
{
        std::cout << "Keyboard Event: Key Pressed - " << _key << std::endl;
}

char KeyboardEvent::GetKey() const { return _key; }

// EventManager implementation
void EventManager::ProcessEvent(Event &event) { event.Handle(); }
void EventManager::ProcessMouseEvent(MouseEvent &mouseEvent) { mouseEvent.Handle(); }
void EventManager::ProcessKeyboardEvent(KeyboardEvent &keyboardEvent) { keyboardEvent.Handle(); }

// Test
int main()
{
        EventManager eventManager;

        MouseEvent mouseEvent(100, 200, 1);
        eventManager.ProcessMouseEvent(mouseEvent);

        KeyboardEvent keyboardEvent('A');
        eventManager.ProcessKeyboardEvent(keyboardEvent);

        return 0;
}