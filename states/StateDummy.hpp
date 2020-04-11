#ifndef SIMPLEGAMEENGINE_DUMMYSTATE_HPP
#define SIMPLEGAMEENGINE_DUMMYSTATE_HPP

#include <string>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>

#include "AbstractState.hpp"

class StateDummy : public AbstractState {
    public :
        explicit StateDummy(Game &game);

        void handleInput() override;
        void update() override;
        void draw() override;

    private :
        const std::string FONT_PATH = "../font.ttf";
        static constexpr float LINES_OFFSET_PIXELS = 28.f;
        static constexpr unsigned int TEXT_FONT_SIZE = 24;

        std::vector< sf::Text > staticTexts;
        sf::Color color;
        sf::Clock clock;
        sf::Font font;
        unsigned int seconds = 0;

        sf::Text createText(const std::string &textMessage);
        sf::Color randomColor();
        void addText(const std::string &textMessage);
};

#endif //SIMPLEGAMEENGINE_DUMMYSTATE_HPP
