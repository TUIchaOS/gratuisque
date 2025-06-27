#include "../include/components.hpp"
#include <string>
#include <iostream>

// Widget implementation
void Widget::Draw() {}
void Widget::Resize(const int new_height, const int new_width) {}
void Widget::Move(const int new_pos) {}
void Widget::Update() {}

// Button implementation
void Button::Click() {}
void Button::ChangeLabel(const std::string &new_label) { _label = new_label; }
std::string Button::GetLabel() const { return _label; }

// TextBox implementation
void TextBox::ChangeText(const std::string &new_text) { _text = new_text; }
std::string TextBox::GetText() const { return _text; }
int TextBox::GetTextLength() const { return _text.length(); }
void TextBox::ClearText() { _text.clear(); }

// Window implementation
void Window::ChangeTitle(const std::string &new_title) { _title = new_title; }
std::string Window::GetTitle() const { return _title; }

// InputField implementation
void InputField::SetPlaceholder(const std::string &placeholder) { _placeholder = placeholder; }
void InputField::SetValue(const std::string &value) { _value = value; }
std::string InputField::GetValue() const { return _value; }
std::string InputField::GetPlaceholder() const { return _placeholder; }
bool InputField::IsValid() const { return true; }
bool InputField::IsEnabled() const { return true; }
bool InputField::IsReadOnly() const { return false; }
int InputField::GetMaxLength() const { return 0; }
int InputField::GetMinLength() const { return 0; }

// Test
int main()
{
        Button button(50, 100, 0, "Click Me");
        TextBox textBox(30, 200, 1, "Hello World");

        button.Click();
        textBox.ChangeText("New Text");

        return 0;
}