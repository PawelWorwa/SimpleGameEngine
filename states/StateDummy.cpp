#include "StateDummy.hpp"

StateDummy::StateDummy(Game &game) : AbstractState(game) {
    srand(static_cast<unsigned int>(time(nullptr)));

    font.loadFromFile(FONT_PATH);
    color = randomColor();
    clock.restart();

    addText("Press P for pause");
    addText("Press Q to replace existing state");
    addText("Press W to add new state");
    addText("Press E to close current state");
}

void StateDummy::handleInput() {
    sf::Event event;
    while (game.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();

        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::P) {
                if (game.isPaused()) {
                    game.unPause();

                } else {
                    game.pause();
                }
            }

            if (!game.isPaused()) {
                if (event.key.code == sf::Keyboard::Q) {
                    replaceCurrentState(State::INITIAL_STATE);

                } else if (event.key.code == sf::Keyboard::W) {
                    addNewState(State::INITIAL_STATE);

                } else if (event.key.code == sf::Keyboard::E) {
                    closeCurrentState();
                }
            }
        }
    }
}

void StateDummy::update() {
    if (!game.isPaused()) {
        if (clock.getElapsedTime().asSeconds() > 1) {
            seconds++;
            clock.restart();
        }
    }
}

void StateDummy::draw() {
    game.getWindow().clear(color);

    if (game.isPaused()) {
        sf::Text paused = createText("Game paused. Press P to resume state");
        paused.setPosition(0.f, (staticTexts.size() + 1) * LINES_OFFSET_PIXELS);
        game.getWindow().draw(paused);
    }

    sf::Text dynamicText = createText("State is running for seconds: " + std::to_string(seconds));
    dynamicText.setPosition(0.f, staticTexts.size() * LINES_OFFSET_PIXELS);
    game.getWindow().draw(dynamicText);

    for (const auto &staticText : staticTexts) {
        game.getWindow().draw(staticText);
    }

    game.getWindow().display();
}

sf::Text StateDummy::createText(const std::string &textMessage) {
    sf::Text text;
    text.setFont(font);
    text.setString(textMessage);
    text.setCharacterSize(TEXT_FONT_SIZE);
    text.setFillColor(sf::Color::White);

    return text;
}

sf::Color StateDummy::randomColor() {
    unsigned int maxValue = 255;
    sf::Uint8 r = static_cast<sf::Uint8>(rand() % maxValue);
    sf::Uint8 g = static_cast<sf::Uint8>(rand() % maxValue);
    sf::Uint8 b = static_cast<sf::Uint8>(rand() % maxValue);
    sf::Uint8 a = static_cast<sf::Uint8>(rand() % maxValue);

    return {r, g, b, a};
}

void StateDummy::addText(const std::string &textMessage) {
    sf::Text text = createText(textMessage);
    text.setPosition(0.f, staticTexts.size() * LINES_OFFSET_PIXELS);
    staticTexts.emplace_back(text);
}

