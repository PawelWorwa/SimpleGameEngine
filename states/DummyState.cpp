#include "DummyState.hpp"

DummyState::DummyState() {
    prepareTexture( Assets::Textures::star );
    prepareTexture( Assets::Textures::blinkingStar );

    Random random;
    for ( std::size_t i = 0; i < random.randomInteger( 1, 100 ); ++i ) {
        Animation star( textures.get( Assets::Textures::star ), 1 );
        star.setPosition( sf::Vector2f( random.randomFloat( 0.f, Resolution::normal.width ),
                                        random.randomFloat( 0.f, Resolution::normal.height )));
        star.randomizeStaringFrame();
        animations.push_back( star );
    }

    for ( std::size_t i = 0; i < random.randomInteger( 1, 100 ); ++i ) {
        Animation blinkingStar( textures.get( Assets::Textures::blinkingStar ), 15 );
        blinkingStar.setPosition(
                sf::Vector2f( random.randomFloat( 0.f, Resolution::normal.width ),
                              random.randomFloat( 0.f, Resolution::normal.height )));
        blinkingStar.randomizeStaringFrame();
        animations.push_back( blinkingStar );
    }
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

            } else if ( event.key.code == sf::Keyboard::P ) {
                statePaused = !statePaused;
            }
        }
    }
}

void DummyState::update( Game &game ) {
    if ( !statePaused ) {
        for ( auto &animation : animations ) {
            animation.increaseFrame();
        }
    }
}

void DummyState::draw( sf::RenderWindow &window ) {
    window.clear( sf::Color::Black );

    dynamicView.reset( sf::FloatRect( 0.f, 0.f, window.getSize().x, window.getSize().y ));
    window.setView( dynamicView );
    for ( auto &animation : animations ) {
        animation.draw( window );
    }

    window.display();
}

void DummyState::prepareTexture( const std::string &texturePath ) {
    sf::Image image;
    image.loadFromFile( texturePath );
    image.createMaskFromColor( sf::Color( 0, 255, 128 ));

    sf::Texture texture;
    texture.loadFromImage( image );

    textures.add( texturePath, texture );
}