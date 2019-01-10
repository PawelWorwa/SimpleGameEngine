#ifndef SIMPLEGAMEENGINE_DUMMYSTATE_HPP
#define SIMPLEGAMEENGINE_DUMMYSTATE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.hpp"
#include "../engine/Animation.hpp"
#include "../engine/GameState.hpp"
#include "../engine/Random.hpp"
#include "../engine/Resolution.hpp"
#include "../engine/ResourceManager.hpp"

#include <string>

class DummyState : public GameState {
    private :
        ResourceManager< sf::Texture > textures;
        std::vector< Animation > animations;
        sf::View dynamicView;

        void prepareTexture( const std::string &texturePath );

    public :
        DummyState();

        void handleInput( sf::RenderWindow &window ) override;
        void update( Game &game ) override;
        void draw( sf::RenderWindow &window ) override;
};

#endif //SIMPLEGAMEENGINE_DUMMYSTATE_HPP
