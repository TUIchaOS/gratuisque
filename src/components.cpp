#include <string>
#include <iostream>
#include <algorithm>

#include "components.hpp"

// Widget implementation
void Widget::Draw() {}
void Widget::Resize(int new_height, int new_width) {}
void Widget::Move(int new_pos) {}
void Widget::Update() {}

// Button implementation
void Button::Click() { std::cout << "Button clicked: " << _label << std::endl; }
void Button::ChangeLabel(const std::string &new_label) { _label = new_label; }
void Button::SetEnabled(bool enabled) { /* Implementation here */ }
bool Button::IsEnabled() const { return true; /* Placeholder */ }
void Button::SetFocus() { /* Implementation here */ }
bool Button::IsFocused() const { return false; /* Placeholder */ }
std::string Button::GetLabel() const { return _label; }

// TextBox implementation
void TextBox::ChangeText(const std::string &new_text) { _text = new_text; }
void TextBox::ClearText() { _text.clear(); }
int TextBox::GetTextLength() const { return static_cast<int>(_text.length()); }
std::string TextBox::GetText() const { return _text; }

// Window implementation
void Window::ChangeTitle(const std::string &new_title) { _title = new_title; }
std::string Window::GetTitle() const { return _title; }
void Window::Show() { std::cout << "Window shown: " << _title << std::endl; }
void Window::Hide() { std::cout << "Window hidden: " << _title << std::endl; }
void Window::Minimize() { std::cout << "Window minimized: " << _title << std::endl; }
void Window::Maximize() { std::cout << "Window maximized: " << _title << std::endl; }
void Window::Close() { std::cout << "Window closed: " << _title << std::endl; }

// InputField implementation
void InputField::SetPlaceholder(const std::string &placeholder) { _placeholder = placeholder; }
void InputField::SetValue(const std::string &value) { _value = value; }
std::string InputField::GetValue() const { return _value; }
std::string InputField::GetPlaceholder() const { return _placeholder; }
bool InputField::IsValid() const { return !_value.empty(); }

// ListBox implementation
void ListBox::AddItem(const std::string &item) { _items.push_back(item); }
void ListBox::RemoveItem(const std::string &item)
{
        _items.erase(std::remove(_items.begin(), _items.end(), item), _items.end());
}
void ListBox::SelectItem(int index) { _selected_index = index; }
std::string ListBox::GetSelectedItem() const
{
        return (_selected_index >= 0 && _selected_index < _items.size()) ? _items[_selected_index] : "";
}
std::vector<std::string> ListBox::GetItems() const { return _items; }

// ProgressBar implementation
void ProgressBar::SetValue(int32_t value) { _value = std::min(value, static_cast<int32_t>(_max_value)); }
void ProgressBar::SetMaxValue(int32_t max_value) { _max_value = max_value; }
bool ProgressBar::IsIndeterminate() const { return _indeterminate; }
int32_t ProgressBar::GetValue() const { return _value; }
int32_t ProgressBar::GetMaxValue() const { return _max_value; }

// CheckBox implementation
void CheckBox::SetChecked(bool checked) { _checked = checked; }
bool CheckBox::IsChecked() const { return _checked; }
std::string CheckBox::GetLabel() const { return _label; }

// RadioButton implementation
void RadioButton::SetChecked(bool checked) { _checked = checked; }
bool RadioButton::IsChecked() const { return _checked; }
std::string RadioButton::GetLabel() const { return _label; }
uint8_t RadioButton::GetGroup() const { return _group; }

// Slider implementation
void Slider::SetValue(int32_t value)
{
        _value = std::clamp(value, _min_value, _max_value);
}
int32_t Slider::GetValue() const { return _value; }

// Notification implementation
void Notification::SetMessage(const std::string &message) { _message = message; }
std::string Notification::GetMessage() const { return _message; }
void Notification::Show() { _is_visible = true; }
void Notification::Hide() { _is_visible = false; }
bool Notification::IsVisible() const { return _is_visible; }

// Test
int main()
{
        Button button(50, 100, {0, 10}, "Click Me");
        TextBox textBox(30, 200, {30, 1}, "Hello World");
        Window window(300, 400, {0, 0}, "Main Window");
        InputField inputField(20, 150, {10, 5}, "Enter text...");

        button.Click();
        textBox.ChangeText("New Text");
        std::cout << "TextBox content: " << textBox.GetText() << std::endl;

        window.Show();
        window.ChangeTitle("Updated Window");
        std::cout << "Window title: " << window.GetTitle() << std::endl;

        inputField.SetValue("Sample Input");
        std::cout << "InputField value: " << inputField.GetValue() << std::endl;

        return 0;
}