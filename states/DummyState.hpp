#ifndef SIMPLEGAMEENGINE_DUMMYSTATE_HPP
#define SIMPLEGAMEENGINE_DUMMYSTATE_HPP

#include <string>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Assets.hpp"
#include "Animation.hpp"
#include "../engine/GameState.hpp"
#include "Resource.hpp"

class DummyState : public GameState {
    private :
        std::vector< Animation > animations;
        Resource< sf::Texture > textures;
        sf::View dynamicView;

        void prepareTexture( const std::string &texturePath );
        void prepareAnimatedObjects(const std::string &asset, unsigned int frames);

    public :
        DummyState();

        void handleInput( Game &game, sf::RenderWindow &window ) override;
        void update( Game &game ) override;
        void draw( sf::RenderWindow &window ) override;
};

#endif //SIMPLEGAMEENGINE_DUMMYSTATE_HPP
