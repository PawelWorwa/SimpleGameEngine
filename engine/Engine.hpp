#ifndef SIMPLEGAMEENGINE_ENGINE_HPP
#define SIMPLEGAMEENGINE_ENGINE_HPP

#include <iostream>
#include <memory>
#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../states/AbstractState.hpp"
#include "Game.hpp"
#include "StateFactory.hpp"

class Engine {
    public :
        Engine();

        void addState(State state);
        void gameLoop();

    private :
        const std::string GAME_TITLE = "Simple state engine";
        static constexpr unsigned int WINDOW_WIDTH = 640;
        static constexpr unsigned int WINDOW_HEIGHT = 480;
        static constexpr unsigned int FPS = 30;

        std::stack< std::unique_ptr< AbstractState>> states;
        Game game;
        StateFactory stateFactory;
        sf::RenderWindow window;

        void addState(std::unique_ptr< AbstractState > gameState);
        void closeState();
        void handleOperation(const StateOperation &operation);
        void replaceState(std::unique_ptr< AbstractState > gameState);
};

#endif //SIMPLEGAMEENGINE_ENGINE_HPP
