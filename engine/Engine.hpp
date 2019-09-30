#ifndef SIMPLEGAMEENGINE_ENGINE_HPP
#define SIMPLEGAMEENGINE_ENGINE_HPP

#include <iostream>
#include <memory>
#include <stack>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.hpp"
#include "GameState.hpp"
#include "StateFactory.hpp"

class Engine {
    public :
        Engine();

        void initialState(State state);
        void gameLoop();

    private :
        static const unsigned int WINDOW_WIDTH = 1024;
        static const unsigned int WINDOW_HEIGHT = 768;
        static const unsigned int FPS = 30;

        Game game;
        StateFactory stateFactory;
        sf::RenderWindow window;

        std::stack< std::unique_ptr< GameState>> states;

        void addState(std::unique_ptr< GameState > gameState);
        void closeState();
        void handleOperation(StateOperation operation);
        void replaceState(std::unique_ptr< GameState > gameState);
};

#endif //SIMPLEGAMEENGINE_ENGINE_HPP
