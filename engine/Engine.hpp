#ifndef SIMPLEGAMEENGINE_ENGINE_HPP
#define SIMPLEGAMEENGINE_ENGINE_HPP

#include <memory>
#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.hpp"
#include "GameState.hpp"

class Engine {
    private :
        sf::RenderWindow window;
        Game game;

        std::stack< std::unique_ptr< GameState>> gameStates;

    public :
        void gameLoop();

        sf::RenderWindow &getWindow();
        void addState( std::unique_ptr< GameState > gameState );
        void popState();
        void replaceState( std::unique_ptr< GameState > gameState );
};

#endif //SIMPLEGAMEENGINE_ENGINE_HPP
