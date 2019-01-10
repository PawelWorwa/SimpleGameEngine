#include "Animation.hpp"

Animation::Animation( const sf::Texture &texture, const unsigned int frames )
        : texture( texture ), frames( frames ) {
    width = texture.getSize().x / frames;
    height = texture.getSize().y;
    sprite.setTexture( texture );
}

void Animation::draw( sf::RenderWindow &window ) {
    sf::IntRect currentSprite( animationFrame * width, 0, width, height );
    sprite.setTextureRect( currentSprite );
    window.draw( sprite );
}

void Animation::setPosition( sf::Vector2f position ) {
    sprite.setPosition( position );
}

void Animation::increaseFrame() {
    animationFrame++;
    if ( animationFrame > frames - 1 ) {
        animationFrame = 0;
    }
}

void Animation::randomizeStaringFrame() {
    thread_local std::mt19937 generator{std::random_device{}()};
    animationFrame = std::uniform_int_distribution< unsigned int >{0, frames}( generator );
}
