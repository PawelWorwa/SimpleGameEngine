#include "Animation.hpp"

Animation::Animation( const sf::Texture &texture, const unsigned int frames )
        : texture( texture ), frames( frames ) {
    width = texture.getSize().x / frames;
    height = texture.getSize().y;
}

void Animation::setPosition( sf::Vector2f position ) {
    Animation::position = position;
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

void Animation::draw( sf::RenderTarget &target, sf::RenderStates states ) const {
    sf::Sprite sprite;
    sprite.setTexture( texture );
    sprite.setPosition( position );
    sprite.setTextureRect( sf::IntRect( animationFrame * width, 0, width, height ));

    target.draw( sprite, states );
}