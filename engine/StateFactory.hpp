#ifndef SIMPLEGAMEENGINE_STATEFACTORY_HPP
#define SIMPLEGAMEENGINE_STATEFACTORY_HPP

#include <functional>
#include <iostream>
#include <map>

#include "../states/AbstractState.hpp"
#include "../states/StateDummy.hpp"

class StateFactory {
    public:
        explicit StateFactory(Game &game);

        std::unique_ptr< AbstractState > createState(State state, Game &game);

    private:
        Game &game;

        std::map< State, std::function< std::unique_ptr< AbstractState >()>> states;

        void initialiseStateMap(Game &game);
};

#endif //SIMPLEGAMEENGINE_STATEFACTORY_HPP
