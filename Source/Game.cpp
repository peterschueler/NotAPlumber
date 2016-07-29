#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y), background(window) {
	CharacterEntity* entity = new CharacterEntity(CharacterEntity::player, 100);
	
	character = std::move(entity);
	character->setPosition(100, 272);
	character->setGrounded(272);
	
	for (unsigned int x = 0; x < (192*3); x+= 192) {
		addRoadBlock(x, 400);
	}
	addRoadBlock(700, 350);
	addRoadBlock(700+192, 350);
	addRoadBlock(1200, 200);
}

bool Game::update(sf::Time delta) {
	character->update(delta);
	background.move(character->setVelocity().x * delta.asSeconds(), 0);
	for (auto road : roads) {
		if (character->getPosition().x >= road->getPosition().x && character->getPosition().x <= road->getPosition().x + road->borders().width) {
			if (road->getPosition().y - (character->getPosition().y + character->borders().height) < 0) {
				character->setGrounded(road->getPosition().y - character->borders().height);
			} else if (road->getPosition().y - (character->getPosition().y + character->borders().height) > 10 && character->getGrounded() > road->getPosition().x) {
				character->setGrounded(road->getPosition().y - character->borders().height);
			}
		}
	}
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
}

void Game::addRoadBlock(float x, float y) {
	RoadEntity* road = new RoadEntity();
	road->setPosition(x, y);
	std::cout << road->getPosition().y << std::endl;
	roads.push_back(std::move(road));
}