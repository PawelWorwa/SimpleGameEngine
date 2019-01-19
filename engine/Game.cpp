#include "Game.hpp"

Game::Game() : running( true ), paused( false ) {
}

bool Game::isRunning() const {
    return running;
}

bool Game::isPaused() const {
    return paused;
}

void Game::setRunning( bool running ) {
    Game::running = running;
}

void Game::setPaused( bool paused ) {
    Game::paused = paused;
}
