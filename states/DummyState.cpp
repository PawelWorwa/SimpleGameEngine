#include "DummyState.hpp"

DummyState::DummyState() {
    srand(time(NULL));

    font.loadFromFile("../font.ttf");

    color = sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255);
    clock.restart();
}

void DummyState::handleInput(Game &game, sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();

        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::P) {
                game.setPaused(!game.isPaused());
            }

            if (!game.isPaused()) {
                if (event.key.code == sf::Keyboard::Q) {
                    stateOperation = StateOperation::REPLACE_EXISTING;
                    nextState = State::INITIAL;

                } else if (event.key.code == sf::Keyboard::W) {
                    stateOperation = StateOperation::ADD_NEW;
                    nextState = State::INITIAL;

                } else if (event.key.code == sf::Keyboard::E) {
                    stateOperation = StateOperation::CLOSE;
                }
            }
        }
    }
}

void DummyState::update(Game &game) {
    if (!game.isPaused()) {
        if (clock.getElapsedTime().asSeconds() > 1) {
            seconds++;
            clock.restart();
        }
    }
}

void DummyState::draw(sf::RenderWindow &window) {
    window.clear(color);

    float offset = 28.f;
    sf::Text pauseText = createText("Press P for pause");
    sf::Text replaceText = createText("Press Q to replace existing state");
    replaceText.setPosition(0.f, offset);
    sf::Text addNewText = createText("Press W to add new state");
    addNewText.setPosition(0.f, 2 * offset);
    sf::Text closeText = createText("Press E to close current state");
    closeText.setPosition(0.f, 3 * offset);
    sf::Text infoText = createText("State is running for seconds: " + std::to_string(seconds));
    infoText.setPosition(0.f, 4 * offset);

    window.draw(pauseText);
    window.draw(replaceText);
    window.draw(addNewText);
    window.draw(closeText);
    window.draw(infoText);

    window.display();
}

sf::Text DummyState::createText(std::string textMessage) {
    sf::Text text;
    text.setFont(font);
    text.setString(textMessage);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    return text;
}
