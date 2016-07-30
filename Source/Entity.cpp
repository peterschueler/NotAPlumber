#include "../Include/Entities/Entity.hpp"

#include <iostream>

Entity::Entity() {
// 	attachTexture("Assets/Textures/Default.png");
}

void Entity::update(sf::Time delta) {
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity::attachTexture(std::string path) {
	if (texture.loadFromFile(path)) {
		sprite.setTexture(texture);
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}

sf::FloatRect Entity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}

sf::Vector2f Entity::getVelocity() const {
	return sf::Vector2f();
}

void Entity::applyGravity(bool now) {
	gravityOn = now;
}

void Entity::animate() {
}