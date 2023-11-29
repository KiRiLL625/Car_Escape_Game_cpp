//
// Created by Admin on 28.11.2023.
//

#include <iostream>
#include "../headers/Button.h"
#include "../headers/MyWindow.h"

const int Button::width = 250;
const int Button::height = 100;

Button::Button(int x, int y, const std::string& text) {
    this->x = x;
    this->y = y;
    this->text = text;
    this->color = raylib::Color(7, 86, 245, 150);
    this->textColor = raylib::RAYWHITE;
    this->rec = Rectangle({static_cast<float>(this->x),
                           static_cast<float>(this->y),
                           static_cast<float>(Button::width),
                           static_cast<float>(Button::height)});
    this->cursor = MOUSE_CURSOR_DEFAULT;
    SetMouseCursor(this->cursor);
    draw();
}

const int Button::getButtonWidth() {
    return Button::width;
}

const int Button::getButtonHeight() {
    return Button::height;
}

void Button::action() {
    if(this->is_on_button()) {
        this->color = raylib::Color(7, 174, 255, 50);
        this->cursor = MOUSE_CURSOR_POINTING_HAND;
        SetMouseCursor(this->cursor);
        draw();
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if(this->text == "Start game"){
                MyWindow::startGame();
            }
            if(this->text == "Main menu"){
                MyWindow::getDeathScreen().hide();
                MyWindow::clearObjects();
                MyWindow::stopGame();
                MyWindow::getMenuScreen().show();
            }
            if(this->text == "Restart") {
                MyWindow::getDeathScreen().hide();
                MyWindow::clearObjects();
                MyWindow::startGame();
            }
            if (this->text == "Exit") {
                exit(0);
            }
        }
    }
}

bool Button::is_on_button() const {
    return CheckCollisionPointRec(GetMousePosition(),
                                  {static_cast<float>(this->x),
                                   static_cast<float>(this->y),
                                   static_cast<float>(Button::width),
                                   static_cast<float>(Button::height)});
}

void Button::draw() const {
    DrawRectangleRec(rec, this->color);
    DrawRectangleLines(this->x, this->y, Button::width, Button::height, raylib::WHITE);
    DrawRectangleLines(this->x + 1, this->y + 1, Button::width - 2, Button::height - 2, raylib::WHITE);
    DrawText(this->text.c_str(), this->x + Button::width / 2 - MeasureText(this->text.c_str(), 40) / 2,
             this->y + Button::height / 2 - 40 / 2, 40, this->textColor);
}