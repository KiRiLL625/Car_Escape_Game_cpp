//
// Created by Admin on 28.11.2023.
//

#include "../headers/GameScreen.h"

#include <utility>

GameScreen::GameScreen(std::string text) : text(std::move(text)) {}

void GameScreen::setText(const std::string &text) {
    this->text = text;
}

std::string GameScreen::getText() const {
    return this->text;
}

void GameScreen::show() {
    DrawRectanglePro({0, 0, static_cast<float>(GetScreenWidth()),
                      static_cast<float>(GetScreenHeight())},
                     {0, 0}, 0,
                     raylib::Color(0, 0, 0, 200));
    DrawText(this->text.c_str(), GetScreenWidth() / 2 -
                MeasureText(this->text.c_str(), 50) / 2,
             GetScreenHeight() / 2 - 350, 50, raylib::WHITE);
}

void GameScreen::hide() {
    DrawRectanglePro({0, 0, static_cast<float>(GetScreenWidth()),
                      static_cast<float>(GetScreenHeight())},
                     {0, 0}, 0,
                     raylib::Color(0, 0, 0, 0));
}

void GameScreen::addButton(Button button) {
    button.action();
}