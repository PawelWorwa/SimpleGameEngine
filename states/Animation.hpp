#ifndef SIMPLEGAMEENGINE_ANIMATION_HPP
#define SIMPLEGAMEENGINE_ANIMATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation : public sf::Drawable {
    private :
        const unsigned int frames;
        const sf::Texture &texture;

        unsigned int animationFrame = 0;
        unsigned int width = 0;
        unsigned int height = 0;

        sf::Vector2f position;

    public:
        explicit Animation( const sf::Texture &texture, unsigned int maxFrames );

        void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;
        void increaseFrame();
        void setPosition( sf::Vector2f position );
        void randomizeStaringFrame();
};


#endif //SIMPLEGAMEENGINE_ANIMATION_HPP
