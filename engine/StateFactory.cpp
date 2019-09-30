#include "StateFactory.hpp"

StateFactory::StateFactory() {
    initialiseStateMap();
}

std::unique_ptr< GameState > StateFactory::createState(State state) {
    if (states.find(state) == states.end()) {
        std::cerr << "State not found!" << std::endl;
    }

    return states.at(state)();
}

void StateFactory::initialiseStateMap() {
    states.emplace(State::INITIAL, []() { return std::unique_ptr< GameState >(new DummyState()); });
}