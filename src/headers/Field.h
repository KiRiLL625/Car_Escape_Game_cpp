//
// Created by Admin on 21.11.2023.
//

#ifndef GAME_1_FIELD_H
#define GAME_1_FIELD_H

#include <memory>
#include "raylib-cpp.hpp"
#include "Object.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
//using namespace raylib;

class Field {
private:
    static const int highwayWidth;
    static const int highwayHeight;
    int highway_Y = 0;
    int acceleration = 10;
public:
    const raylib::Texture2D highway;
    Field();
    explicit Field(int highway_Y);
    int getAcceleration() const;
    void setAcceleration(int acceleration);
    static const int getHighwayWidth();
    static const int getHighwayHeight();
    int getHighway_Y() const;
    void setHighway_Y(int highway_Y);
    void draw() const;
    void move();
    static void add(std::unique_ptr<Object> object);
};


#endif //GAME_1_FIELD_H
