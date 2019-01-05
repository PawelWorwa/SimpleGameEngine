#include "DummyState.hpp"

DummyState::DummyState() {
    font.loadFromFile( "../media/arial.ttf" );

    text.setFont( font );
    text.setCharacterSize( 80 );
    text.setOrigin( 40.f, 40.f );
    text.setPosition( 400.f, 300.f );
    text.setFillColor( sf::Color::White );
}

void DummyState::handleInput( sf::RenderWindow &window ) {
    sf::Event event;
    while ( window.pollEvent( event )) {
        if ( event.type == sf::Event::Closed ) {
            window.close();

        } else if ( event.type == sf::Event::KeyPressed ) {
            if ( event.key.code == sf::Keyboard::Q ) {
                replaceState = true;
                nextGameState = std::unique_ptr< GameState >( new DummyState());

            } else if ( event.key.code == sf::Keyboard::W ) {
                addState = true;
                nextGameState = std::unique_ptr< GameState >( new DummyState());

            } else if ( event.key.code == sf::Keyboard::E ) {
                closeState = true;
            }
        }
    }
}

void DummyState::update( Game &game ) {
    number++;
    text.setString( std::to_string( number ));
}

void DummyState::draw( sf::RenderWindow &window ) {
    window.clear( sf::Color::Black );
    window.draw( text );
    window.display();
}