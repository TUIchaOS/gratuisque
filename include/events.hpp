#include <iostream>
#include <string>

class Event
{
public:
        virtual void Handle() = 0; // Pure virtual function to handle the event
        virtual ~Event() = default;
};

class MouseEvent : public Event
{
private:
        int _x;
        int _y;
        int _button;

public:
        MouseEvent(int x, int y, int button);
        void Handle() override;
        int GetX() const;
        int GetY() const;
        int GetButton() const;
};

class KeyboardEvent : public Event
{
private:
        char _key;

public:
        KeyboardEvent(char key);
        void Handle() override;
        char GetKey() const;
};

class EventManager
{
public:
        void ProcessEvent(Event &event);
        void ProcessMouseEvent(MouseEvent &mouseEvent);
        void ProcessKeyboardEvent(KeyboardEvent &keyboardEvent);
};