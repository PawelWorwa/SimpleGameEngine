cmake_minimum_required(VERSION 3.10)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleGameEngine
        main.cpp
        engine/Engine.cpp
        engine/Engine.hpp
        engine/Game.cpp
        engine/Game.hpp
        engine/GameState.hpp
        engine/StateOperation.hpp
        engine/StateName.hpp
        states/Animation.cpp
        states/Animation.hpp
        states/Resource.hpp
        states/DummyState.cpp
        states/DummyState.hpp
        states/Assets.hpp
        states/Assets.cpp
        )


set(SFML_DIR "${SFML_PATH}")

find_package(SFML 2.5 COMPONENTS graphics)

target_link_libraries(SimpleGameEngine sfml-graphics)