//
// Created by Admin on 20.11.2023.
//

#include "../headers/MyWindow.h"

//#include "Field.h"
#include "../headers/Car.h"
#include "../headers/Object.h"
#include "../headers/Cone.h"
#include "../headers/Truck.h"
#include "../headers/Bus.h"
#include "../headers/SpeedBump.h"
//#include "GameScreen.h"

bool MyWindow::game_stopped = true;
GameScreen MyWindow::menuScreen("Main menu");
GameScreen MyWindow::deathScreen("Game over");
std::vector<std::unique_ptr<Object>> MyWindow::objects(10);

MyWindow::MyWindow(){
    this->width = SCREEN_WIDTH;
    this->height = SCREEN_HEIGHT;
    this->title = "Car Escape";
    this->init();
}
/*
MyWindow::MyWindow(int width, int height, std::string title):
    width(width), height(height), title(std::move(title)) {
    this->init();
}
 */

void MyWindow::init() {
    window.Init(width, height, title);
    //fixme
    window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    //fixme
    window.SetIcon(LoadImage("./textures/icon.png"));
    window.SetTargetFPS(60);
    Field field;
    Field field2(-Field::getHighwayHeight());
    Car car;
    //std::vector<std::unique_ptr<Object>> objects(10);
    clearObjects();
    int time = 0;
    int i = 0;
    while(!window.ShouldClose()) {
        BeginDrawing();
        ClearBackground(raylib::DARKGRAY);
        field.move();
        field2.move();
        car.move();
        if(MyWindow::isGameStopped() || death(objects, car)) {
            //GameScreen menuScreen("Main menu");
            if(MyWindow::isGameStopped()) {
                menuScreen.show();
                menuScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                            SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2 -
                                            BUTTONS_DISTANCE,
                                            "Start game"));
                menuScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                            SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2,
                                            "Difficulty"));
                menuScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                            SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2 +
                                            BUTTONS_DISTANCE,
                                            "Exit"));
                this->stop_everything(objects, car, field, field2);
            }
            if(death(objects, car)){
                menuScreen.hide();
                DrawTexture(LoadTexture("textures/explosion.png"), car.getX() - 5,
                        car.getY() - 15, raylib::WHITE);
                //GameScreen deathScreen("Game over");
                this->stop_everything(objects, car, field, field2);
                deathScreen.show();
                deathScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                         SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2 -
                                         BUTTONS_DISTANCE,
                                         "Restart"));
                deathScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                         SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2,
                                         "Main menu"));
                deathScreen.addButton(Button(SCREEN_WIDTH / 2 - Button::getButtonWidth() / 2,
                                         SCREEN_HEIGHT / 2 - Button::getButtonHeight() / 2 +
                                         BUTTONS_DISTANCE,
                                         "Exit"));
            }
        }
        else{
            addObjects(objects, time, i);
            field.setAcceleration(10);
            field2.setAcceleration(10);
            car.setAcceleration(7);
            for(auto & object : objects) {
                if (object != nullptr) {
                    object->setAcceleration(10);
                    object->draw();
                }
            }
        }
        EndDrawing();
    }
}

void MyWindow::close() {
    window.Close();
}

void MyWindow::addObjects(std::vector<std::unique_ptr<Object>>& objects, int& time, int& i) {
    int random = rand() % 4;
    //int random = 2;
    int random_time = rand() % 60 + 30;
    if (time % random_time == 0 && objects[i] == nullptr) {
        switch (random) {
            case 0:
                objects[i] = std::make_unique<SpeedBump>();
                break;
            case 1:
                objects[i] = std::make_unique<Cone>();
                break;
            case 2:
                objects[i] = std::make_unique<Truck>();
                break;
            case 3:
                objects[i] = std::make_unique<Bus>();
                break;
            default:
                break;
        }
    }
    for (auto &object: objects) {
        if (object != nullptr) {
            object->move();
        }
        //fixme: for test SCREEN_HEIGHT - 200
        if (object != nullptr && object->getY() >= SCREEN_HEIGHT) {
            object = nullptr;
        }
    }
    time++;
    if (time % random_time == 0 && i < 9) {
        i++;
    } else if (time % random_time == 0 && i == 9) {
        i = 0;
    }
}

bool MyWindow::death(std::vector<std::unique_ptr<Object>>& objects, Car& car) {
    for (auto &object: objects) {
        if(object != nullptr) {
            if (car.getX() <= object->getX() + object->getObjectWidth() &&
                car.getX() + Car::getCarWidth() >= object->getX() &&
                car.getY() <= object->getY() + object->getObjectHeight()) {
                //MyWindow::game_stopped = true;
                return true;
            }
        }
    }
    return false;
}

bool MyWindow::isGameStopped() {
    return game_stopped;
}

void MyWindow::startGame() {
    game_stopped = false;
}

void MyWindow::stopGame() {
    game_stopped = true;
}

void MyWindow::stop_everything(std::vector<std::unique_ptr<Object>> &objects, Car &car,
                               Field &field, Field &field2) {
    car.setAcceleration(0);
    field.setAcceleration(0);
    field2.setAcceleration(0);
    for (auto &object: objects) {
        if (object != nullptr) {
            object->setAcceleration(0);
            object->draw();
        }
    }
}

GameScreen& MyWindow::getMenuScreen() {
    return menuScreen;
}

GameScreen& MyWindow::getDeathScreen() {
    return deathScreen;
}

void MyWindow::clearObjects() {
    for(auto & object : objects) {
        object = nullptr;
    }
}