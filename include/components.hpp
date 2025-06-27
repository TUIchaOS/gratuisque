#pragma once
#include <string>

class Widget
{
public:
        int Height;
        int Width;
        int Pos;

        Widget(const int height, const int width, const int pos)
            : Height(height), Width(width), Pos(pos) {}

        virtual ~Widget() = default;

        void Draw();
        void Resize(const int new_height, const int new_width);
        void Move(const int new_pos);
        void Update();
};

class Button : public Widget
{
private:
        std::string _label;

public:
        Button(const int height, const int width, const int pos, const std::string &label)
            : Widget(height, width, pos), _label(label) {}

        void Click();
        void ChangeLabel(const std::string &new_label);
        void SetEnabled(bool enabled);
        void SetDisabled(bool disabled);
        bool IsEnabled() const;
        bool IsDisabled() const;
        bool IsVisible() const;
        bool IsHidden() const;
        void SetFocus();
        bool IsFocused() const;
        std::string GetLabel() const;
};

class TextBox : public Widget
{
private:
        std::string _text;

public:
        TextBox(const int height, const int width, const int pos, const std::string &text)
            : Widget(height, width, pos), _text(text) {}

        void ChangeText(const std::string &new_text);
        std::string GetText() const;
        int GetTextLength() const;
        void ClearText();
};

class Window : public Widget
{
private:
        std::string _title;

public:
        Window(const int height, const int width, const int pos, const std::string &title)
            : Widget(height, width, pos), _title(title) {}

        void ChangeTitle(const std::string &new_title);
        void Show();
        void Hide();
        void Minimize();
        void Maximize();
        void Close();
        std::string GetTitle() const;
};

class InputField : public Widget
{
private:
        std::string _placeholder;
        std::string _value;

public:
        InputField(const int height, const int width, const int pos, const std::string &placeholder)
            : Widget(height, width, pos), _placeholder(placeholder), _value("") {}

        void SetPlaceholder(const std::string &placeholder);
        void SetValue(const std::string &value);
        void SetReadOnly(bool read_only);
        void SetMinLength(int min_length);
        void SetMaxLength(int max_length);
        void Focus();
        void ClearValue();
        void Validate();
        void ShowError(const std::string &error_message);
        void HideError();
        void Enable();
        void Disable();
        bool IsValid() const;
        bool IsEnabled() const;
        bool IsReadOnly() const;
        int GetMaxLength() const;
        int GetMinLength() const;
        std::string GetValue() const;
        std::string GetPlaceholder() const;
        std::string GetError() const;
};
