#include "engine/Engine.hpp"

#include "states/DummyState.hpp"

int main() {
    Engine engine;
    engine.getWindow().create( sf::VideoMode( 800u, 600u ), "Simple state engine!" );
    engine.getWindow().setFramerateLimit( 30u );
    engine.addState( std::unique_ptr< GameState >( new DummyState()));
    engine.gameLoop();
    engine.getWindow().close();

    return EXIT_SUCCESS;
}