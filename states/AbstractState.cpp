#include "AbstractState.hpp"

AbstractState::AbstractState(Game &game) :
        game(game),
        stateOperation(StateOperation::RUNNING),
        nextState(State::NOT_DEFINED) {
}

StateOperation AbstractState::getStateOperation() const {
    return stateOperation;
}

void AbstractState::setStateOperation(const StateOperation &stateOperation) {
    AbstractState::stateOperation = stateOperation;
}

State AbstractState::getNextState() const {
    return nextState;
}

void AbstractState::replaceCurrentState(const State &nextState) {
    AbstractState::stateOperation = StateOperation::REPLACE_EXISTING_STATE;
    AbstractState::nextState = nextState;
}

void AbstractState::addNewState(const State &nextState) {
    AbstractState::stateOperation = StateOperation::ADD_NEW_STATE;
    AbstractState::nextState = nextState;
}

void AbstractState::closeCurrentState() {
    AbstractState::stateOperation = StateOperation::CLOSE_STATE;
}
