#pragma once

#include <cstdint>
#include <string>
#include <vector>

typedef std::pair<uint16_t, uint16_t> Coord;

// Base Widget class
class Widget
{
protected:
        uint16_t _height;
        uint16_t _width;
        Coord _coord;

public:
        Widget(uint16_t height, uint16_t width, Coord coord)
            : _height(height), _width(width), _coord(coord) {}

        virtual ~Widget() = default;

        virtual void Draw();
        virtual void Resize(int new_height, int new_width);
        virtual void Move(int new_pos);
        virtual void Update();
};

// Button class
class Button : public Widget
{
private:
        std::string _label;

public:
        Button(uint16_t height, uint16_t width, Coord coord, const std::string &label)
            : Widget(height, width, coord), _label(label) {}

        void Click();
        void ChangeLabel(const std::string &new_label);
        void SetEnabled(bool enabled);
        bool IsEnabled() const;
        void SetFocus();
        bool IsFocused() const;
        std::string GetLabel() const;
};

// TextBox class
class TextBox : public Widget
{
private:
        std::string _text;

public:
        TextBox(uint16_t height, uint16_t width, Coord coord, const std::string &text)
            : Widget(height, width, coord), _text(text) {}

        void ChangeText(const std::string &new_text);
        std::string GetText() const;
        int GetTextLength() const;
        void ClearText();
};

// Window class
class Window : public Widget
{
private:
        std::string _title;

public:
        Window(uint16_t height, uint16_t width, Coord coord, const std::string &title)
            : Widget(height, width, coord), _title(title) {}

        void ChangeTitle(const std::string &new_title);
        void Show();
        void Hide();
        void Minimize();
        void Maximize();
        void Close();
        std::string GetTitle() const;
};

// InputField class
class InputField : public Widget
{
private:
        std::string _placeholder;
        std::string _value;

public:
        InputField(uint16_t height, uint16_t width, Coord coord, const std::string &placeholder)
            : Widget(height, width, coord), _placeholder(placeholder), _value("") {}

        void SetPlaceholder(const std::string &placeholder);
        void SetValue(const std::string &value);
        bool IsValid() const;
        std::string GetValue() const;
        std::string GetPlaceholder() const;
};

// ListBox class
class ListBox : public Widget
{
private:
        std::vector<std::string> _items;
        int _selected_index;

public:
        ListBox(uint16_t height, uint16_t width, Coord coord)
            : Widget(height, width, coord), _selected_index(-1) {}

        void AddItem(const std::string &item);
        void RemoveItem(const std::string &item);
        void SelectItem(int index);
        std::string GetSelectedItem() const;
        std::vector<std::string> GetItems() const;
};

// ProgressBar class
class ProgressBar : public Widget
{
private:
        uint16_t _value;
        uint16_t _max_value;
        bool _indeterminate;

public:
        ProgressBar(uint16_t height, uint16_t width, Coord coord, int32_t max_value = 100, int32_t value = 0)
            : Widget(height, width, coord), _value(value), _max_value(max_value), _indeterminate(false) {}

        void SetValue(int32_t value);
        void SetMaxValue(int32_t max_value);
        bool IsIndeterminate() const;
        int32_t GetValue() const;
        int32_t GetMaxValue() const;
};

// CheckBox class
class CheckBox : public Widget
{
private:
        bool _checked;
        std::string _label;

public:
        CheckBox(uint16_t height, uint16_t width, Coord coord, const std::string &label)
            : Widget(height, width, coord), _checked(false), _label(label) {}

        void SetChecked(bool checked);
        bool IsChecked() const;
        std::string GetLabel() const;
};

// RadioButton class
class RadioButton : public Widget
{
private:
        bool _checked;
        std::string _label;
        uint8_t _group;

public:
        RadioButton(uint16_t height, uint16_t width, Coord coord, const std::string &label, uint8_t group = 0)
            : Widget(height, width, coord), _checked(false), _label(label), _group(group) {}

        void SetChecked(bool checked);
        bool IsChecked() const;
        std::string GetLabel() const;
        uint8_t GetGroup() const;
};

// Slider class
class Slider : public Widget
{
private:
        int32_t _value;
        int32_t _min_value;
        int32_t _max_value;

public:
        Slider(uint16_t height, uint16_t width, Coord coord, int32_t min_value = 0, int32_t max_value = 100, int32_t value = 0)
            : Widget(height, width, coord), _value(value), _min_value(min_value), _max_value(max_value) {}

        void SetValue(int32_t value);
        int32_t GetValue() const;
};

// Notification class
class Notification : public Widget
{
private:
        std::string _message;
        bool _is_visible;

public:
        Notification(uint16_t height, uint16_t width, Coord coord, const std::string &message)
            : Widget(height, width, coord), _message(message), _is_visible(false) {}

        void SetMessage(const std::string &message);
        std::string GetMessage() const;
        void Show();
        void Hide();
        bool IsVisible() const;
};