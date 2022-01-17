#include "Game.hpp"

Game::Game() {
	this->pointsGoal = 3;
	this->running = true;
}

void Game::setRunning(bool value) {
	this->running = value;
}

bool Game::checkWin(int points) {
	return this->pointsGoal == points;
}

bool Game::isRunning() {
	return running;
}
