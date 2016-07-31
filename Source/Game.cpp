#include "../Include/Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

Game::Game(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 8000, window.getDefaultView().getSize().y), background(window) {
	CharacterEntity* entity = new CharacterEntity(100);
	
	character = std::move(entity);
	character->setPosition(80, 272);
	character->setGrounded(450);
	
	addRoadBlocks(0,450,12);
	addRoadBlocks(400,300,5);
	addRoadBlocks(700,220,5);
	addRoadBlocks(1200,350,7);
	addRoadBlocks(1900, 200,7);
	addRoadBlocks(2200, 350,6);
	addRoadBlocks(2900,250,4);
	addRoadBlocks(3200, 500, 12);
	addRoadBlocks(3700, 300, 4);
	addRoadBlocks(3400, 400, 2);
	addRoadBlocks(4000, 420, 6);
	addRoadBlocks(4800, 420, 5);
	addRoadBlocks(5000, 100, 12);
	addRoadBlocks(5100, 300, 8);
	addRoadBlocks(6000, 400, 2);
	addRoadBlocks(6300, 370, 2);
	addRoadBlocks(6500, 250, 2);
	addRoadBlocks(6700, 180, 2);
	addRoadBlocks(6900, 500, 4);
	
	FlagpoleEntity* flag = new FlagpoleEntity();
	flagpole = std::move(flag);
	flagpole->setScale(2.f,2.f);
	flagpole->setPosition(7200,500-256);
	
	initMonsters(1);
}

bool CompareRoads(RoadEntity* a, RoadEntity* b) {
	return a->getPosition().y < b->getPosition().y;
}

bool Game::update(sf::Time delta) {
	character->update(delta);
	background.move(character->getVelocity().x * delta.asSeconds(), 0);
	checkCollision(character);
	for (auto monster : monsters) {
		if (monster->getType() == MonsterEntity::Type::monster_crawler) {
			checkCollision(monster);
		}
	}
	if (flagpole->borders().intersects(character->borders())) {
		flagpole->setOn(true);
	}
	for (auto monster : monsters) {
		monster->update(delta);
		if (monster->borders().intersects(character->borders())) {
			return false;
		}
	}
	if (character->getPosition().x == 2500) {
		setupMonster(4000, 100, MonsterEntity::Type::monster_crawler);
		setupMonster(4800, 150, MonsterEntity::Type::monster_crawler);
		setupMonster(5200, 150, MonsterEntity::Type::monster_crawler);
	}
	else if (character->getPosition().x == 3000) {
		setupMonster(5300, 100, MonsterEntity::Type::monster_crawler);
		setupMonster(5500, 100, MonsterEntity::Type::monster_crawler);
	}
	return true;
}

void Game::draw() {
	background.draw();
	for (auto road : roads) {
		window.draw(*road);
	}
	window.draw(*flagpole);
	window.draw(*character);
	
	for (auto monster : monsters) {
		window.draw(*monster);
	}
}

void Game::input(Command* command) {
	command->execute(*character);
}

void Game::addRoadBlock(float x, float y) {
	RoadEntity* road = new RoadEntity();
	road->setPosition(x, y);
	roads.push_back(std::move(road));
}

void Game::addRoadBlocks(float _x, float _y, unsigned int _number) {
	for (unsigned int x = 0; x < (96*_number); x+= 96) {
		addRoadBlock(_x + x, _y);
	}
}

void Game::checkCollision(Entity* entity) {
	auto characterWidth = entity->getPosition().x + entity->borders().width;
	
	std::vector<RoadEntity*> roadsToCheck;
	for (auto road : roads) {
		auto roadWidth = road->getPosition().x + road->borders().width;
		auto characterOverFloor = characterWidth >= road->getPosition().x && characterWidth <= roadWidth;
		if (characterOverFloor) {
			roadsToCheck.push_back(road);
		}
	}
	
	if (roadsToCheck.size() == 0) {
		entity->setVelocity(entity->getVelocity().x, 100);
	}
	
	for (auto road : roadsToCheck) {
		if (entity->getPosition().y > road->getPosition().y) {
			continue;
		}
		if (entity->getPosition().y + 150 < road->getPosition().y) {
			if (roadsToCheck.size() > 1) {
				continue;
			}
		}
		auto characterHighground = entity->getGrounded() < road->getPosition().y;
		auto distanceBetweenObjects = road->getPosition().y - (entity->getPosition().y + entity->borders().height);
		if (distanceBetweenObjects < 0) {
			entity->setGrounded(road->getPosition().y - entity->borders().height);
		} else if (distanceBetweenObjects > 30 && characterHighground && !entity->getJumping()) {
			entity->setVelocity(entity->getVelocity().x, 100);
		}
	}
}

void Game::initMonsters(unsigned int level) {
	switch (level) {
		case 1:
			setupMonster(400, 300, MonsterEntity::Type::monster_flyer);
			setupMonster(900, 250, MonsterEntity::Type::monster_flyer);
			setupMonster(2500, 200, MonsterEntity::Type::monster_flyer);
			setupMonster(2900, 275, MonsterEntity::Type::monster_flyer);
			setupMonster(4000, 250, MonsterEntity::Type::monster_flyer);
			setupMonster(7000, 400, MonsterEntity::Type::monster_flyer);
			
			setupMonster(800, 150, MonsterEntity::Type::monster_crawler);
			setupMonster(1500, 150, MonsterEntity::Type::monster_crawler);
			setupMonster(2450, 100, MonsterEntity::Type::monster_crawler);
			break;
		case 2:
			break;
		case 3:
			break;
		}
}

void Game::setupMonster(float x, float y, MonsterEntity::Type type) {
	auto monster = new MonsterEntity(type, 100);
	monster->setPosition(x, y);
	monsters.push_back(std::move(monster));
}