#include "Engine.hpp"
#include "../states/DummyState.hpp"
#include <iostream>

void Engine::gameLoop() {
    while ( window.isOpen() && game.isRunning()) {
        std::cout << "states: " << gameStates.size() << '\n';

        if ( gameStates.top()->isAddState()) {
            gameStates.top()->setAddState( false );
            addState( gameStates.top()->getNextState());

        } else if ( gameStates.top()->isReplaceState()) {
            replaceState( gameStates.top()->getNextState());

        } else if ( gameStates.top()->isCloseState()) {
            gameStates.pop();
        }

        gameStates.top()->handleInput( window );
        gameStates.top()->update( game );
        gameStates.top()->draw( window );
    }
}

sf::RenderWindow &Engine::getWindow() {
    return window;
}

void Engine::addState( std::unique_ptr< GameState > gameState ) {
    gameStates.push( std::move( gameState ));
}

void Engine::replaceState( std::unique_ptr< GameState > gameState ) {
    gameStates.pop();
    addState( std::move( gameState ));
}
