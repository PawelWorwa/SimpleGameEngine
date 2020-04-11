#ifndef SIMPLEGAMEENGINE_GAMESTATE_HPP
#define SIMPLEGAMEENGINE_GAMESTATE_HPP

#include "../engine/Game.hpp"
#include "StateOperation.hpp"
#include "State.hpp"

class AbstractState {
    public:
        explicit AbstractState(Game &game);
        virtual ~AbstractState() = default;

        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

        StateOperation getStateOperation() const;
        State getNextState() const;

        void setStateOperation(const StateOperation &stateOperation);

    protected:
        Game &game;

        void replaceCurrentState(const State &nextState);
        void addNewState(const State &nextState);
        void closeCurrentState();

    private:
        StateOperation stateOperation;
        State nextState;
};

#endif //SIMPLEGAMEENGINE_GAMESTATE_HPP
