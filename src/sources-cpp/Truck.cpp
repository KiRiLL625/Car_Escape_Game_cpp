//
// Created by Admin on 27.11.2023.
//

#include "../headers/Truck.h"

//
// Created by Admin on 26.11.2023.
//

const int Truck::width = 80;
const int Truck::height = 208;

Truck::Truck(): x(chooseLane()), y(-Truck::getObjectHeight()),
              texture("./textures/truck_still.png"),
              acceleration(10){}

//FIXME ПОЧЕМУ ЭТО НЕ РАБОТАЕТ КАК ПРЕЖДЕ?!
int Truck::getX() const {
    return this->x;
}

int Truck::getY() const {
    return this->y;
}

const int Truck::getObjectWidth() const {
    return width;
}

const int Truck::getObjectHeight() const {
    return height;
}

void Truck::draw() const {
    DrawTexture(this->texture, this->getX(), this->getY(), raylib::WHITE);
}

void Truck::move() {
    this->y += acceleration;
    this->draw();
}