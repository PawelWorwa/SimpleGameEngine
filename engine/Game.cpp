#include "Game.hpp"

Game::Game(sf::RenderWindow &window) :
        window(window),
        gameState(GameState::RUNNING) {
}

sf::RenderWindow &Game::getWindow() const {
    return window;
}

void Game::pause() {
    Game::gameState = GameState::PAUSE;
}

void Game::unPause() {
    Game::gameState = GameState::RUNNING;
}

void Game::exitGame() {
    Game::gameState = GameState::EXIT_GAME;
}

bool Game::isExitGame() {
    return Game::gameState == GameState::EXIT_GAME;
}

bool Game::isPaused() {
    return Game::gameState == GameState::PAUSE;
}
