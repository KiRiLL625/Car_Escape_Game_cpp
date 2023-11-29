//
// Created by Admin on 21.11.2023.
//

#include "../headers/Field.h"
#include "../headers/Object.h"

const int Field::highwayWidth = 512;
const int Field::highwayHeight = 1024;

Field::Field(): highway(LoadTexture("./textures/highway.png")) {}

Field::Field(int highway_Y): highway_Y(highway_Y),
    highway(LoadTexture("./textures/highway.png")) {}

int Field::getAcceleration() const {
    return acceleration;
}

void Field::setAcceleration(int acceleration) {
    this->acceleration = acceleration;
}

const int Field::getHighwayWidth(){
    return highwayWidth;
}

const int Field::getHighwayHeight(){
    return highwayHeight;
}

int Field::getHighway_Y() const {
    return highway_Y;
}

void Field::setHighway_Y(int highway_Y) {
    this->highway_Y = highway_Y;
}

void Field::draw() const {
    DrawTexture(highway, SCREEN_WIDTH / 2 - (getHighwayWidth() / 2),
                getHighway_Y(), raylib::WHITE);
}

void Field::move() {
    highway_Y += getAcceleration();
    if (highway_Y >= highwayHeight) {
        highway_Y = -Field::getHighwayHeight() + acceleration;
    }
    draw();
}

[[gnu::unused]] void Field::add(std::unique_ptr<Object> object) {
    object->move();
}