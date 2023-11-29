//
// Created by Admin on 28.11.2023.
//

#ifndef GAME_1_GAMESCREEN_H
#define GAME_1_GAMESCREEN_H


#include <string>
#include "raylib-cpp.hpp"
#include "Button.h"

class GameScreen {
private:
    std::string text;
public:
    explicit GameScreen(std::string text);
    ~GameScreen() = default;
    void show();
    void hide();
    std::string getText() const;
    void setText(const std::string &text);
    void addButton(Button button);
};


#endif //GAME_1_GAMESCREEN_H
