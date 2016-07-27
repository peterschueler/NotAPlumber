#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y), background(window) {
	CharacterEntity* entity = new CharacterEntity(CharacterEntity::player, 100);
	
	character = std::move(entity);
	character->setPosition(100, 200);
	
	for (unsigned int x = 0; x < (192*3); x+= 192) {
		addRoadBlock(x, 400);
	}
	addRoadBlock(640, 350);
}

bool Game::update(sf::Time delta) {
	character->update(delta);
	return true;
}

void Game::draw() {
	background.draw();
	for (auto road : roads) {
		window.draw(*road);
	}
	
	window.draw(*character);
}

void Game::input(Command* command) {
	command->execute(*character);
	background.move(character->getDirection().x / 30, 0);
}

void Game::addRoadBlock(float x, float y) {
	RoadEntity* road = new RoadEntity();
	road->setPosition(x, y);
	roads.push_back(std::move(road));
}