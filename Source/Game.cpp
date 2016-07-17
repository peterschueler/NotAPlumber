#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y), background(window) {
}

bool Game::update(sf::Time delta) {
	return background.update(delta);
}

void Game::draw() {
	background.draw();
}

void Game::input(Command* command) {
}