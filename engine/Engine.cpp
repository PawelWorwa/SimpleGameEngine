#include "Engine.hpp"

Engine::Engine() :
        game(window),
        stateFactory(game) {

    window.create(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            GAME_TITLE);

    window.setFramerateLimit(FPS);
}

void Engine::gameLoop() {
    while (window.isOpen() && !game.isExitGame()) {
        StateOperation operation = states.top()->getStateOperation();
        handleOperation(operation);

        states.top()->handleInput();
        states.top()->update();
        states.top()->draw();
    }

    window.close();
}

void Engine::addState(std::unique_ptr< AbstractState > gameState) {
    states.push(std::move(gameState));

    std::cout << "states: " << states.size() << " adding" << std::endl;
}

void Engine::replaceState(std::unique_ptr< AbstractState > gameState) {
    states.pop();
    addState(std::move(gameState));

    std::cout << "states: " << states.size() << " replacing" << std::endl;
}

void Engine::addState(State state) {
    addState(stateFactory.createState(state, game));
}

void Engine::handleOperation(const StateOperation &operation) {
    State nextState = states.top()->getNextState();
    switch (operation) {
        case StateOperation::ADD_NEW_STATE:
            addState(stateFactory.createState(nextState, game));
            break;

        case StateOperation::REPLACE_EXISTING_STATE:
            replaceState(stateFactory.createState(nextState, game));
            break;

        case StateOperation::CLOSE_STATE:
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
