#ifndef SIMPLEGAMEENGINE_DUMMYSTATE_HPP
#define SIMPLEGAMEENGINE_DUMMYSTATE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include "../engine/GameState.hpp"

#include <string>

class DummyState : public GameState {
    private :
        sf::Font font;
        sf::Text text;
        unsigned int number = 0;

    public :
        DummyState();
    
        void handleInput( sf::RenderWindow &window ) override;
        void update( Game &game ) override;
        void draw( sf::RenderWindow &window ) override;
};

#endif //SIMPLEGAMEENGINE_DUMMYSTATE_HPP
