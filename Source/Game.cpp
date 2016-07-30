#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y), background(window) {
	CharacterEntity* entity = new CharacterEntity(CharacterEntity::player, 100);
	
	character = std::move(entity);
	character->setPosition(80, 272);
	character->setGrounded(272);
	
	for (unsigned int x = 0; x < (192*3); x+= 192) {
		addRoadBlock(x, 400);
	}
	for (unsigned int x = 160; x < (192*3); x+= 192) {
		addRoadBlock(x, 270);
	}
	addRoadBlock(700, 350);
	addRoadBlock(700+192, 350);
	addRoadBlock(1200, 200);
}

bool CompareRoads(RoadEntity* a, RoadEntity* b) {
	return a->getPosition().y < b->getPosition().y;
}

bool Game::update(sf::Time delta) {
	character->update(delta);
	background.move(character->getVelocity().x * delta.asSeconds(), 0);
	
	auto characterWidth = character->getPosition().x + character->borders().width;
	
	std::vector<RoadEntity*> roadsToCheck;
	for (auto road : roads) {
		auto roadWidth = road->getPosition().x + road->borders().width;
		auto characterOverFloor = characterWidth >= road->getPosition().x && characterWidth <= roadWidth;
		if (characterOverFloor) {
			roadsToCheck.push_back(road);
		}
	}
	
	if (roadsToCheck.size() == 0) {
		character->setVelocity(character->getVelocity().x, 100);
	}
	
	for (auto road : roadsToCheck) {
		if (character->getPosition().y > road->getPosition().y) {
			continue;
		}
		if (character->getPosition().y + 150 < road->getPosition().y) {
			if (roadsToCheck.size() > 1) {
				continue;
			}
		}
		auto characterHighground = character->getGrounded() < road->getPosition().y;
		auto distanceBetweenObjects = road->getPosition().y - (character->getPosition().y + character->borders().height);
		if (distanceBetweenObjects < 0) {
			character->setGrounded(road->getPosition().y - character->borders().height);
		} else if (distanceBetweenObjects > 30 && characterHighground && !character->getJumping()) {
			character->setVelocity(character->getVelocity().x, 100);
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
	roads.push_back(std::move(road));
}