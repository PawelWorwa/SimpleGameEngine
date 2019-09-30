#ifndef SIMPLEGAMEENGINE_GAMESTATE_HPP
#define SIMPLEGAMEENGINE_GAMESTATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.hpp"
#include "StateOperation.hpp"
#include "State.hpp"

class GameState {
    public:
        GameState() :
                stateOperation(StateOperation::RUNNING),
                nextState(State::NONE) {
        }

        virtual ~GameState() = default;

        virtual void handleInput(Game &game, sf::RenderWindow &window) = 0;
        virtual void update(Game &game) = 0;
        virtual void draw(sf::RenderWindow &window) = 0;

        StateOperation getStateOperation() const {
            return stateOperation;
        }

        State getNextState() const {
            return std::move(nextState);
        }

        void setStateOperation(StateOperation stateOperation) {
            GameState::stateOperation = stateOperation;
        }

    protected:
        StateOperation stateOperation;
        State nextState;
};

#endif //SIMPLEGAMEENGINE_GAMESTATE_HPP
