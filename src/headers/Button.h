//
// Created by Admin on 28.11.2023.
//

#ifndef GAME_1_BUTTON_H
#define GAME_1_BUTTON_H

#include "raylib-cpp.hpp"
#define BUTTONS_DISTANCE 120


class Button {
private:
    int x;
    int y;
    static const int width;
    static const int height;
    raylib::Color color;
    raylib::Color textColor;
    std::string text;
    raylib::Rectangle rec;
    MouseCursor cursor;
public:
    //Button() = delete;
    Button(int x, int y, const std::string& text);
    ~Button() = default;
    static const int getButtonWidth();
    static const int getButtonHeight();
    void action();
    bool is_on_button() const;
    void draw() const;
};


#endif //GAME_1_BUTTON_H
