#ifndef SIMPLEGAMEENGINE_DUMMYSTATE_HPP
#define SIMPLEGAMEENGINE_DUMMYSTATE_HPP

#include <string>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../engine/GameState.hpp"

class DummyState : public GameState {
    private :
        sf::Color color;
        sf::Clock clock;
        sf::Font font;
        unsigned int seconds = 0;

        sf::Text createText(std::string textMessage);

    public :
        DummyState();

        void handleInput(Game &game, sf::RenderWindow &window) override;
        void update(Game &game) override;
        void draw(sf::RenderWindow &window) override;
};

#endif //SIMPLEGAMEENGINE_DUMMYSTATE_HPP
