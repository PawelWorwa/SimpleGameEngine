cmake_minimum_required(VERSION 3.9)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleGameEngine
        main.cpp
        engine/Engine.cpp
        engine/Engine.hpp
        engine/Game.cpp
        engine/Game.hpp
        engine/GameState.hpp
        engine/StateFactory.cpp
        engine/StateFactory.hpp
        states/AbstractState.hpp
        states/AbstractState.cpp
        states/State.hpp
        states/StateDummy.cpp
        states/StateDummy.hpp
        states/StateOperation.hpp)

set(SFML_DIR "${SFML_PATH}")

find_package(SFML 2.5 COMPONENTS graphics)

target_link_libraries(SimpleGameEngine sfml-graphics)