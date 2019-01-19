#include "Engine.hpp"

Engine::Engine() {
    window.create( sf::VideoMode( 1024, 768 ), "Simple state engine!" );
    window.setFramerateLimit( 30 );
    addState( createState( StateName::DUMMY_STATE ));
}

void Engine::gameLoop() {
    while ( window.isOpen() && game.isRunning()) {
        StateName nextState = gameStates.top()->getNextStateName();
        StateOperation operation = gameStates.top()->getStateOperation();
        switch ( operation ) {
            case StateOperation::ADD_STATE:
                addState( createState( nextState ));
                std::cout << "states: " << gameStates.size() << " adding" << std::endl;
                break;

            case StateOperation::REPLACE_STATE:
                replaceState( createState( nextState ));
                std::cout << "states: " << gameStates.size() << " replacing" << std::endl;
                break;

            case StateOperation::CLOSE_STATE:
                if ( gameStates.size() > 1 ) {
                    popState();
                    std::cout << "states: " << gameStates.size() << " popping" << std::endl;

                } else {
                    std::cout << "can't pop last state!" << std::endl;
                }
                gameStates.top()->setStateOperation( StateOperation::RUNNING );

            default:
                break;
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