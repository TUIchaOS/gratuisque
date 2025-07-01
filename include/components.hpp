#pragma once

#include <cstdint>
#include <string>
#include <vector>

typedef std::pair<uint16_t, uint16_t> Coord;

// Base
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
        void SetFocus();
        bool IsEnabled() const;
        bool IsFocused() const;
        std::string GetLabel() const;
};

class TextBox : public Widget
{
private:
        std::string _text;

public:
        TextBox(uint16_t height, uint16_t width, Coord coord, const std::string &text)
            : Widget(height, width, coord), _text(text) {}

        void ChangeText(const std::string &new_text);
        void ClearText();
        int GetTextLength() const;
        std::string GetText() const;
};

class Window : public Widget
{
private:
        std::string _title;

public:
        Window(uint16_t height, uint16_t width, Coord coord, const std::string &title)
            : Widget(height, width, coord), _title(title) {}

        void Open();
        void Hide();
        void Minimize();
        void Maximize();
        void Close();
        void ChangeTitle(const std::string &new_title);
        std::string GetTitle() const;
};

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

class Slider : public Widget
{
private:
        int32_t _value;
        int32_t _min_value;
        int32_t _max_value;

public:
        Slider(uint16_t height, uint16_t width, Coord coord, int32_t min_value = 0, int32_t max_value = 100, int32_t value = 0)
            : Widget(height, width, coord), _value(value), _min_value(min_value), _max_value(max_value) {}

        void ChangeValue(int32_t value);
        int32_t GetValue() const;
};

class Notification : public Widget
{
private:
        std::string _message;
        bool _is_visible;

public:
        Notification(const std::string &message)
            : Widget(100, 250, {1080, 1920}), _message(message), _is_visible(false) {}

        void Show();
        void Hide();
        void SetMessage(const std::string &message);
        std::string GetMessage() const;
        bool IsVisible() const;
};

class Popup : public Widget
{
private:
        std::string _title;
        std::string _message;

public:
        Popup(const std::string &title, const std::string &message, uint16_t width = 300, uint16_t height = 150)
            : Widget(height, width, {0, 0}), _title(title), _message(message) {}

        void Show();
        void Close();
        void ChangeTitle(const std::string &title);
        void ChangeMessage(const std::string &message);
};