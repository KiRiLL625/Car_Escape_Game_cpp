//
// Created by Admin on 24.11.2023.
//

#ifndef GAME_1_OBJECT_H
#define GAME_1_OBJECT_H

#include "raylib-cpp.hpp"
#define LEFT_LANE_X_BOUND 750
#define MIDDLE_LANE_X_BOUND 910
#define RIGHT_LANE_X_BOUND 1060

class Object{
private:
    int x;
    int y;
    int acceleration;
public:
    raylib::Texture2D texture;
    Object();
    virtual ~Object() = default;
    virtual int getX() const;
    virtual int getY() const;
    int getAcceleration() const;
    void setAcceleration(int acceleration);
    virtual const int getObjectWidth() const = 0;
    virtual const int getObjectHeight() const = 0;
    int chooseLane();
    virtual void draw() const;
    virtual void move();
};


#endif //GAME_1_OBJECT_H
