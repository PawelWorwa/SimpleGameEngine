#include "StateFactory.hpp"

StateFactory::StateFactory(Game &game) : game(game) {
    initialiseStateMap(game);
}

std::unique_ptr< AbstractState > StateFactory::createState(State state, Game &game) {
    if (states.find(state) == states.end()) {
        std::cerr << "State not found!" << std::endl;
    }

    return states.at(state)();
}

void StateFactory::initialiseStateMap(Game &game) {
    states.emplace(State::INITIAL_STATE, [&game]() { return std::unique_ptr< AbstractState >(new StateDummy(game)); });
}
