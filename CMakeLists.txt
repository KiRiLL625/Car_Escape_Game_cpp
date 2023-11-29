cmake_minimum_required(VERSION 3.25)
project(Game_1)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is the main part:
set(SOURCES src/sources-cpp/main.cpp src/sources-cpp/Bus.cpp src/sources-cpp/Car.cpp
        src/sources-cpp/Cone.cpp src/sources-cpp/Field.cpp src/sources-cpp/GameScreen.cpp
        src/sources-cpp/MyWindow.cpp src/sources-cpp/Object.cpp src/sources-cpp/SpeedBump.cpp
        src/sources-cpp/Truck.cpp src/headers/Bus.h src/headers/Car.h src/headers/Cone.h
        src/headers/Field.h src/headers/GameScreen.h src/headers/MyWindow.h src/headers/Object.h
        src/headers/SpeedBump.h src/headers/Truck.h src/sources-cpp/Button.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")

    # Required linker flags for using Raylib with Emscripten
    target_link_options(${PROJECT_NAME} PRIVATE -sEXPORTED_FUNCTIONS=['_main','_malloc'] -sEXPORTED_RUNTIME_METHODS=ccall -sUSE_GLFW=3)
endif()

# That's it! You should have an example executable that you can run. Have fun!