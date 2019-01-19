#ifndef SIMPLEGAMEENGINE_ENGINE_HPP
#define SIMPLEGAMEENGINE_ENGINE_HPP

#include <iostream>
#include <memory>
#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>
#include "../states/DummyState.hpp"
#include "Game.hpp"
#include "GameState.hpp"

class Engine {
    private :
        Game game;
        sf::RenderWindow window;

        std::stack< std::unique_ptr< GameState>> gameStates;
        std::unique_ptr< GameState > createState( StateName state );

        void addState( std::unique_ptr< GameState > gameState );
        void popState();
        void replaceState( std::unique_ptr< GameState > gameState );

    public :
        Engine();

        void gameLoop();
};

#endif //SIMPLEGAMEENGINE_ENGINE_HPP
