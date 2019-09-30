#include "engine/Engine.hpp"

int main() {
    Engine engine;
    engine.initialState(State::INITIAL);
    engine.gameLoop();

    return EXIT_SUCCESS;
}