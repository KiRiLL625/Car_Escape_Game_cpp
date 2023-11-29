//
// Created by Admin on 26.11.2023.
//

#ifndef GAME_1_CONE_H
#define GAME_1_CONE_H


#include "Object.h"

class Cone: public Object {
private:
    int x;
    int y;
    static const int width;
    static const int height;
    int acceleration;
public:
    raylib::Texture2D texture;
    Cone();
    ~Cone() = default;
    int getX() const override;
    int getY() const override;
    const int getObjectWidth() const override;
    const int getObjectHeight() const override;
    void draw() const override;
    void move() override;
};


#endif //GAME_1_CONE_H
