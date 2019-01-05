#ifndef SIMPLEGAMEENGINE_GAMESTATE_HPP
#define SIMPLEGAMEENGINE_GAMESTATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.hpp"

class GameState {
    public:
        virtual void handleInput( sf::RenderWindow &window ) = 0;
        virtual void update( Game &game ) = 0;
        virtual void draw( sf::RenderWindow &window ) = 0;

        bool isReplaceState() const {
            return replaceState;
        }

        bool isAddState() const {
            return addState;
        }

        bool isCloseState() const {
            return closeState;
        }

        void setAddState( bool addState ) {
            GameState::addState = addState;
        }

        std::unique_ptr< GameState > getNextState() {
            return std::move( nextGameState );
        }

    protected:
        std::unique_ptr< GameState > nextGameState = nullptr;
        bool replaceState = false;
        bool addState = false;
        bool closeState = false;
};

#endif //SIMPLEGAMEENGINE_GAMESTATE_HPP
