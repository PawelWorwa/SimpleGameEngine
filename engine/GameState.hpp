#ifndef SIMPLEGAMEENGINE_GAMESTATE_HPP
#define SIMPLEGAMEENGINE_GAMESTATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.hpp"
#include "StateOperation.hpp"
#include "StateName.hpp"

class GameState {
    public:
        GameState() : stateOperation( StateOperation::RUNNING ), nextStateName( StateName::NONE ) {}

        virtual ~GameState() {};

        virtual void handleInput( sf::RenderWindow &window ) = 0;
        virtual void update( Game &game ) = 0;
        virtual void draw( sf::RenderWindow &window ) = 0;

        StateOperation getStateOperation() const {
            return stateOperation;
        }

        StateName getNextStateName() const {
            return nextStateName;
        }

        void setStateOperation( StateOperation stateOperation ) {
            GameState::stateOperation = stateOperation;
        }

    protected:
        StateOperation stateOperation;
        StateName nextStateName;
};

#endif //SIMPLEGAMEENGINE_GAMESTATE_HPP
