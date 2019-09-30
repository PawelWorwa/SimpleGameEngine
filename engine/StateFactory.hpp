#ifndef SIMPLEGAMEENGINE_STATEFACTORY_HPP
#define SIMPLEGAMEENGINE_STATEFACTORY_HPP

#include "GameState.hpp"

#include "../states/DummyState.hpp"

#include <functional>
#include <iostream>
#include <map>

class StateFactory {
    public:
        StateFactory();

        std::unique_ptr< GameState > createState(State state);

    private:
        std::map<State, std::function<std::unique_ptr< GameState >()>> states;

        void initialiseStateMap();
};

#endif //SIMPLEGAMEENGINE_STATEFACTORY_HPP
