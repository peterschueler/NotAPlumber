#include "../Include/Entities/CharacterEntity.hpp"

#include <iostream>

CharacterEntity::CharacterEntity() : sprite(), texture(), hitpoints(100), type(monster) {
	attachTexture("Assets/Textures/Character.png");
}

CharacterEntity::CharacterEntity(Type type, unsigned int hits) : sprite(), texture(), hitpoints(hits), type(type) {
	attachTexture("Assets/Textures/Character.png");
	acceleration = sf::Vector2f(0.f, 3.81);
	isGrounded = false;
}

void CharacterEntity::update(sf::Time delta) {
	std::cout << position.y << std::endl;
	velocity += acceleration * delta.asSeconds();
	position += velocity * delta.asSeconds();
	if (position.y > 1) {
		position.y--;
	} else {
		move(position);
	}
}

void CharacterEntity::setDirection(float x, float y) {
	velocity.x = x;
	velocity.y = y;
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

void CharacterEntity::setGrounded() {
	isGrounded = !isGrounded;
}