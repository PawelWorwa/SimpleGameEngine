#include "Engine.hpp"

Engine::Engine() {
    window.create( sf::VideoMode( 1024, 768 ), "Simple state engine!" );
    window.setFramerateLimit( 30 );
    addState( createState( StateName::DUMMY_STATE ));
}

void Engine::gameLoop() {
    while ( window.isOpen() && game.isRunning()) {
        StateOperation operation = gameStates.top()->getStateOperation();
        if ( operation == StateOperation::ADD_STATE ) {
            StateName nextState = gameStates.top()->getNextStateName();
            addState( createState( nextState ));
            std::cout << "states: " << gameStates.size() << " adding" << std::endl;

        } else if ( operation == StateOperation::REPLACE_STATE ) {
            StateName nextState = gameStates.top()->getNextStateName();
            replaceState( createState( nextState ));
            std::cout << "states: " << gameStates.size() << " replacing" << std::endl;

        } else if ( operation == StateOperation::CLOSE_STATE ) {
            if ( gameStates.size() > 1 ) {
                popState();
                std::cout << "states: " << gameStates.size() << " popping" << std::endl;

            } else {
                std::cout << "can't pop last state!" << std::endl;
            }
            gameStates.top()->setStateOperation( StateOperation::RUN_STATE );
        }

        gameStates.top()->handleInput( game, window );
        gameStates.top()->update( game );
        gameStates.top()->draw( window );
    }

    window.close();
}

void Engine::addState( std::unique_ptr< GameState > gameState ) {
    gameStates.push( std::move( gameState ));
}

void Engine::replaceState( std::unique_ptr< GameState > gameState ) {
    popState();
    addState( std::move( gameState ));
}

void Engine::popState() {
    if ( !gameStates.empty()) {
        gameStates.pop();
    }
}

std::unique_ptr< GameState > Engine::createState( StateName state ) {
    switch ( state ) {
        case StateName::DUMMY_STATE :
            return std::unique_ptr< GameState >( new DummyState());

        default:
            break;
    }
}