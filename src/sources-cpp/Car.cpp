//
// Created by Admin on 22.11.2023.
//

#include "../headers/Car.h"

const int Car::width = 80;
const int Car::height = 161;

Car::Car(): x(SCREEN_WIDTH / 2 - Car::getCarWidth() / 2),
            y(SCREEN_HEIGHT - getCarHeight() - 50),
            texture(LoadTexture("./textures/car2.png")),
            acceleration(7) {}

int Car::getX() const {
    return this->x;
}

int Car::getY() const{
    return this->y;
}

int Car::getAcceleration() const {
    return this->acceleration;
}

void Car::setAcceleration(int acceleration) {
    this->acceleration = acceleration;
}

const int Car::getCarWidth() {
    return Car::width;
}

const int Car::getCarHeight() {
    return Car::height;
}

void Car::setX(int x) {
    this->x = x;
}

void Car::setY(int y) {
    this->y = y;
}

void Car::draw() const {
    DrawTexture(texture, getX(), getY(), raylib::WHITE);
}

void Car::move() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        x += getAcceleration();
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        x -= getAcceleration();
    }
    if (x < X_LEFT_BOUND) {
        x = X_LEFT_BOUND;
    }
    if (x > X_RIGHT_BOUND) {
        x = X_RIGHT_BOUND;
    }
    draw();
}