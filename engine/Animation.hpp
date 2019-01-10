#ifndef SIMPLEGAMEENGINE_ANIMATION_HPP
#define SIMPLEGAMEENGINE_ANIMATION_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Animation {
    private :
        const unsigned int frames;
        const sf::Texture &texture;

        unsigned int animationFrame = 0;
        unsigned int width = 0;
        unsigned int height = 0;

        sf::Sprite sprite;

    public:
        explicit Animation( const sf::Texture &texture, unsigned int maxFrames );

        void draw( sf::RenderWindow &window );
        void setPosition( sf::Vector2f position );
        void increaseFrame();
        void randomizeStaringFrame();
};


#endif //SIMPLEGAMEENGINE_ANIMATION_HPP
