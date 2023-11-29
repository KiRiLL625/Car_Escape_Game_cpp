//
// Created by Admin on 28.11.2023.
//

#include "../headers/SpeedBump.h"

const int SpeedBump::width = 80;
const int SpeedBump::height = 60;

SpeedBump::SpeedBump(): x(chooseLane()), y(-SpeedBump::getObjectHeight()),
              texture("./textures/speed_bump.png"),
              acceleration(10){}

int SpeedBump::getX() const {
    return this->x;
}

int SpeedBump::getY() const {
    return this->y;
}

const int SpeedBump::getObjectWidth() const {
    return width;
}

const int SpeedBump::getObjectHeight() const {
    return height;
}

void SpeedBump::draw() const {
    DrawTexture(this->texture, getX(), getY(), raylib::WHITE);
}

void SpeedBump::move() {
    this->y += acceleration;
    this->draw();
}