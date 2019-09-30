#include "Engine.hpp"

Engine::Engine() {
    window.create(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "Simple state engine!");
    window.setFramerateLimit(FPS);
}

void Engine::gameLoop() {
    while (window.isOpen() && game.isRunning()) {
        StateOperation operation = states.top()->getStateOperation();
        handleOperation(operation);

        states.top()->handleInput(game, window);
        states.top()->update(game);
        states.top()->draw(window);
    }

    window.close();
}

void Engine::addState(std::unique_ptr< GameState > gameState) {
    states.push(
            std::move(gameState));

    std::cout << "states: " << states.size() << " adding" << std::endl;
}

void Engine::replaceState(std::unique_ptr< GameState > gameState) {
    states.pop();
    addState(
            std::move(gameState));

    std::cout << "states: " << states.size() << " replacing" << std::endl;
}

void Engine::initialState(State state) {
    addState(
            stateFactory.createState(state));
}

void Engine::handleOperation(StateOperation operation) {
    State nextState = states.top()->getNextState();
    switch (operation) {
        case StateOperation::ADD_NEW:
            addState(
                    stateFactory.createState(nextState));
            break;

        case StateOperation::REPLACE_EXISTING:
            replaceState(
                    stateFactory.createState(nextState));
            break;

        case StateOperation::CLOSE:
            closeState();
            break;

        default:
            break;
    }
}

void Engine::closeState() {
    if (states.size() > 1) {
        states.pop();
        std::cout << "states: " << states.size() << " popping" << std::endl;
    }

    states.top()->setStateOperation(StateOperation::RUNNING);
}
