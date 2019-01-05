cmake_minimum_required(VERSION 3.10)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleGameEngine
        main.cpp engine/Engine.cpp engine/Engine.hpp engine/Game.cpp engine/Game.hpp engine/GameState.hpp states/DummyState.cpp states/DummyState.hpp)

# ToDO - pass as parameter
set(SFML_DIR "C:/01_SFML/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio)

target_link_libraries(SimpleGameEngine sfml-graphics sfml-audio)