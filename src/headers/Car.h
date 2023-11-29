//
// Created by Admin on 22.11.2023.
//

#ifndef GAME_1_CAR_H
#define GAME_1_CAR_H

#include "raylib-cpp.hpp"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define X_LEFT_BOUND 730
#define X_RIGHT_BOUND 1110

class Car {
private:
    int x;
    int y;
    static const int width;
    static const int height;
    int acceleration;
public:
    raylib::Texture2D texture;
    Car();
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void draw() const;
    int getAcceleration() const;
    void setAcceleration(int acceleration);
    static const int getCarWidth();
    static const int getCarHeight();
    void move();
};


#endif //GAME_1_CAR_H
