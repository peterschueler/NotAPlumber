#include "../Include/Entities/FlagpoleEntity.hpp"

#include <iostream>

FlagpoleEntity::FlagpoleEntity() : sprite(), texture() {
	attachTexture("Assets/Textures/Flagpole_Off.png");
}

void FlagpoleEntity::update(sf::Time delta) {
}

void FlagpoleEntity::setVelocity(float x, float y) {
}

void FlagpoleEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void FlagpoleEntity::attachTexture(std::string path) {
	if (texture.loadFromFile(path)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,32,128));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}

void FlagpoleEntity::setOn(bool _on) {
	isOn = _on;
	attachTexture("Assets/Textures/Flagpole_On.png");
}

bool FlagpoleEntity::getOn() const {
	return isOn;
}

sf::FloatRect FlagpoleEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}