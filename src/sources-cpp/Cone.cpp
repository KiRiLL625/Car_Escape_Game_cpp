//
// Created by Admin on 26.11.2023.
//

#include "../headers/Cone.h"

const int Cone::width = 75;
const int Cone::height = 78;

Cone::Cone(): x(chooseLane()), y(-Cone::getObjectHeight()),
              texture("./textures/cone5.png"),
              acceleration(10){}

int Cone::getX() const {
    return this->x;
}

int Cone::getY() const {
    return this->y;
}

const int Cone::getObjectWidth() const {
    return width;
}

const int Cone::getObjectHeight() const {
    return height;
}

void Cone::draw() const {
    DrawTexture(this->texture, getX(), getY(), raylib::WHITE);
}

void Cone::move() {
    this->y += acceleration;
    this->draw();
}
