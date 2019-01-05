#include "Game.hpp"

Game::Game() : running( true ) {
}

bool Game::isRunning() const {
    return running;
}

void Game::setRunning( bool running ) {
    Game::running = running;
}
