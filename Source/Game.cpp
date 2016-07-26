#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y), background(window), foreground(window) {
	CharacterEntity* entity = new CharacterEntity(CharacterEntity::player, 100);
	
	character = std::move(entity);
	character->setPosition(100, 200);
}

bool Game::update(sf::Time delta) {
	character->update(delta);
	return foreground.update(delta);
}

void Game::draw() {
	background.draw();
	foreground.draw();
	window.draw(*character);
}

void Game::input(Command* command) {
	command->execute(*character);
	std::cout << character->getDirection().x << std::endl;
	background.move(character->getDirection().x / 30, character->getDirection().y / 30);
}