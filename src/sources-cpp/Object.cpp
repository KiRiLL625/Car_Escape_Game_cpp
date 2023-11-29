//
// Created by Admin on 24.11.2023.
//

#include "../headers/Object.h"
#include "../headers/Field.h"

Object::Object(): x(chooseLane()),
                    acceleration(10){}

int Object::getX() const {
    return this->x;
}

int Object::getY() const {
    return this->y;
}

int Object::getAcceleration() const {
    return this->acceleration;
}

void Object::setAcceleration(int acceleration) {
    this->acceleration = acceleration;
}

int Object::chooseLane() {
    int lane = std::rand() % 3;
    switch(lane) {
        case 0:
            return LEFT_LANE_X_BOUND;
        case 1:
            return MIDDLE_LANE_X_BOUND;
        case 2:
            return RIGHT_LANE_X_BOUND;
    }
    return 0;
}

void Object::draw() const {
    DrawTexture(texture, getX(), getY(), raylib::WHITE);
}

void Object::move() {
    this->y += getAcceleration();
    draw();
}
