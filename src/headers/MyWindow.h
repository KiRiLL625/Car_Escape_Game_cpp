//
// Created by Admin on 20.11.2023.
//

#ifndef GAME_1_MYWINDOW_H
#define GAME_1_MYWINDOW_H

#include <memory>
#include "raylib-cpp.hpp"
#include "Object.h"
#include "Car.h"
#include "Field.h"
#include "GameScreen.h"

//using namespace raylib;

class MyWindow {
private:
    int width;
    int height;
    std::string title;
    raylib::Window window;
    static bool game_stopped;
    static GameScreen menuScreen;
    static GameScreen deathScreen;
    static std::vector<std::unique_ptr<Object>> objects;

    /*
    int getScreenWidth();
    int getScreenHeight();
     */
public:
    MyWindow();
    MyWindow(int width, int height, std::string title);
    void init();
    void close();
    void addObjects(std::vector<std::unique_ptr<Object>>& objects, int& time, int& i);
    bool death(std::vector<std::unique_ptr<Object>>& objects, Car& car);
    static bool isGameStopped();
    static void startGame();
    static void stopGame();
    void stop_everything(std::vector<std::unique_ptr<Object>>& objects, Car& car,
                         Field& field, Field& field2);
    static GameScreen& getMenuScreen();
    static GameScreen& getDeathScreen();
    static void clearObjects();
};


#endif //GAME_1_MYWINDOW_H
