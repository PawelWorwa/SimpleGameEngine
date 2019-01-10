#include "engine/Engine.hpp"

#include "states/DummyState.hpp"
#include "engine/Resolution.hpp"

int main() {
    Engine engine;
    engine.getWindow().create( sf::VideoMode( Resolution::normal ), "Simple state engine!" );
    engine.getWindow().setFramerateLimit( 30 );
    engine.addState( std::unique_ptr< GameState >( new DummyState()));
    engine.gameLoop();
    engine.getWindow().close();

    return EXIT_SUCCESS;
}