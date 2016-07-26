#include "../Include/Entities/CharacterEntity.hpp"

#include <iostream>

CharacterEntity::CharacterEntity() : sprite(), texture(), hitpoints(100), type(monster) {
	attachTexture("Assets/Textures/Character.png");
}

CharacterEntity::CharacterEntity(Type type, unsigned int hits) : sprite(), texture(), hitpoints(hits), type(type) {
	attachTexture("Assets/Textures/Character.png");
}

void CharacterEntity::update(sf::Time delta) {
	move(direction * delta.asSeconds());
}

void CharacterEntity::setDirection(float x, float y) {
	direction.x = x;
	direction.y = y;
}

sf::Vector2f CharacterEntity::getDirection() const {
	return direction;
}

void CharacterEntity::hit(unsigned int points) {
	if ((hitpoints - points) > 0) {
		hitpoints -= points;
	} else {
		hitpoints = 0;
	}
}

unsigned int CharacterEntity::getHitPoints() const {
	return hitpoints;
}

void CharacterEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void CharacterEntity::attachTexture(std::string path) {
	if (texture.loadFromFile(path)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,64,64));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}