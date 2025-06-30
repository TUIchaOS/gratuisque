#pragma once

#include <iostream>
#include <string>

// Base Event class
class Event
{
public:
        virtual void Handle() = 0; // Pure virtual function to handle the event
        virtual ~Event() = default;
};

// MouseEvent class
class MouseEvent : public Event
{
private:
        u_int16_t _x;
        u_int16_t _y;
        int8_t _button;

public:
        MouseEvent(u_int16_t x, u_int16_t y, int8_t button);
        void Handle() override;
        u_int16_t GetX() const;
        u_int16_t GetY() const;
        int8_t GetButton() const;
};

// KeyboardEvent class
class KeyboardEvent : public Event
{
private:
        char _key;

public:
        explicit KeyboardEvent(char key);
        void Handle() override;
        char GetKey() const;
};

// EventManager class
class EventManager
{
public:
        void ProcessEvent(Event &event);
        void ProcessMouseEvent(MouseEvent &mouseEvent);
        void ProcessKeyboardEvent(KeyboardEvent &keyboardEvent);
};