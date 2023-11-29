//
// Created by Admin on 27.11.2023.
//

#include "../headers/Bus.h"

const int Bus::width = 80;
const int Bus::height = 265;

//fixme: уменьшить текстуру автобуса по высоте (слишком длинный)
Bus::Bus(): x(chooseLane()), y(-Bus::getObjectHeight()),
              texture("./textures/bus.png"),
              acceleration(8){}

int Bus::getX() const{
    return this->x;
}

int Bus::getY() const{
    return this->y;
}

void Bus::draw() const {
    DrawTexture(this->texture, this->getX(), this->getY(), raylib::WHITE);
}

const int Bus::getObjectWidth() const {
    return width;
}

const int Bus::getObjectHeight() const {
    return height;
}

void Bus::move() {
    this->y += acceleration;
    this->draw();
}