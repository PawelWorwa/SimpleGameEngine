#include <utility>

#include "DummyState.hpp"

DummyState::DummyState() {
    prepareTexture( Assets::Textures::star );
    prepareTexture( Assets::Textures::blinkingStar );
    prepareAnimatedObjects( Assets::Textures::star, 1 );
    prepareAnimatedObjects( Assets::Textures::blinkingStar, 15 );
}

void DummyState::handleInput( sf::RenderWindow &window ) {
    sf::Event event;
    while ( window.pollEvent( event )) {
        if ( event.type == sf::Event::Closed ) {
            window.close();

        } else if ( event.type == sf::Event::KeyPressed ) {
            if ( event.key.code == sf::Keyboard::Q ) {
                stateOperation = StateOperation::REPLACE_STATE;
                nextStateName = StateName::DUMMY_STATE;

            } else if ( event.key.code == sf::Keyboard::W ) {
                stateOperation = StateOperation::ADD_STATE;
                nextStateName = StateName::DUMMY_STATE;

            } else if ( event.key.code == sf::Keyboard::E ) {
                stateOperation = StateOperation::CLOSE_STATE;
            }
        }
    }
}

void DummyState::update( Game &game ) {
    for ( auto &animation : animations ) {
        animation.increaseFrame();
    }
}

void DummyState::draw( sf::RenderWindow &window ) {
    window.clear( sf::Color::Black );

    dynamicView.reset( sf::FloatRect( 0.f, 0.f, window.getSize().x, window.getSize().y ));
    window.setView( dynamicView );
    for ( auto &animation : animations ) {
        window.draw( animation );
    }

    window.display();
}

void DummyState::prepareTexture( const std::string &texturePath ) {
    sf::Image image;
    image.loadFromFile( texturePath );
    sf::Color maskGreen = sf::Color( 0, 255, 128 );
    image.createMaskFromColor( maskGreen );

    sf::Texture texture;
    texture.loadFromImage( image );

    textures.add( texturePath, texture );
}

void DummyState::prepareAnimatedObjects( const std::string &asset, unsigned int frames ) {
    thread_local std::mt19937 generator{std::random_device{}()};
    unsigned int elements = std::uniform_int_distribution< unsigned int >{0, 100}( generator );

    for ( std::size_t i = 0; i < elements; ++i ) {
        Animation animation( textures.get( asset ), frames );
        unsigned int xPos = std::uniform_int_distribution< unsigned int >{0, 1024}( generator );
        unsigned int yPos = std::uniform_int_distribution< unsigned int >{0, 768}( generator );
        animation.setPosition( sf::Vector2f( xPos, yPos ));
        animation.randomizeStaringFrame();
        animations.push_back( animation );
    }
}