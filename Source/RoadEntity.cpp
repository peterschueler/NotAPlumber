#include "../Include/Entities/RoadEntity.hpp"

#include <iostream>

RoadEntity::RoadEntity() : sprite(), texture(), length(192), height(64) {
	attachTexture("Assets/Textures/YellowBricks.png");
}

RoadEntity::RoadEntity(float x, float y) : sprite(), texture(), length(x), height(y) {
	attachTexture("Assets/Textures/YellowBricks.png");
}

void RoadEntity::update(sf::Time delta) {
}

void RoadEntity::setDirection(float x, float y) {
}

void RoadEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void RoadEntity::attachTexture(std::string path) {
	if (texture.loadFromFile(path)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,length,height));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}