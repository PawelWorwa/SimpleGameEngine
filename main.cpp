#include "engine/Engine.hpp"

int main() {
    Engine engine;
    engine.addState(State::INITIAL_STATE);
    engine.gameLoop();

    return EXIT_SUCCESS;
}