#ifndef SIMPLEGAMEENGINE_GAME_HPP
#define SIMPLEGAMEENGINE_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameState.hpp"

class Game {
    public:
        explicit Game(sf::RenderWindow &window);

        sf::RenderWindow &getWindow() const;
        bool isExitGame();
        bool isPaused();

        void pause();
        void unPause();
        void exitGame();

    private:
        GameState gameState;
        sf::RenderWindow &window;
};

#endif //SIMPLEGAMEENGINE_GAME_HPP
