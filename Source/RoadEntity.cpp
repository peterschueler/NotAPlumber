#include "../Include/Entities/RoadEntity.hpp"

#include <iostream>

RoadEntity::RoadEntity() : sprite(), texture(), length(96), height(32) {
	attachTexture("Assets/Textures/YellowBricks.png");
}

RoadEntity::RoadEntity(float x, float y) : sprite(), texture(), length(x), height(y) {
	attachTexture("Assets/Textures/YellowBricks_2.png");
}

void RoadEntity::update(sf::Time delta) {
}

void RoadEntity::setVelocity(float x, float y) {
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

sf::FloatRect RoadEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}