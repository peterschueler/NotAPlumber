#include "../Include/Entities/MonsterEntity.hpp"

#include <iostream>

MonsterEntity::MonsterEntity() : sprite(), texture(), hitpoints(100), type(monster_flyer) {
	attachTexture("Assets/Textures/monsters.png");
	sprite.setTextureRect(sf::IntRect(0,0,64,64));
}

MonsterEntity::MonsterEntity(Type type, unsigned int hitpoints) : sprite(), texture(), hitpoints(hitpoints), type(type) {
	if (type == monster_flyer) {
		attachTexture("Assets/Textures/monsters.png");
		sprite.setTextureRect(sf::IntRect(0,0,64,64));
		setVelocity(-100,0);
	} else if (type == monster_crawler) {
		attachTexture("Assets/Textures/monsters.png");
		sprite.setTextureRect(sf::IntRect(0,64,64,64));
	}
}

void MonsterEntity::update(sf::Time delta) {
	if (type == monster_flyer) {
		move(velocity * delta.asSeconds());
	} else if (type == monster_crawler) {
	}
}

void MonsterEntity::setVelocity(float x, float y) {
	velocity.x = x;
	velocity.y = y;
}

sf::Vector2f MonsterEntity::getVelocity() const {
	return velocity;
}

void MonsterEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void MonsterEntity::attachTexture(std::string path) {
	if (texture.loadFromFile(path)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,64,64));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}

sf::FloatRect MonsterEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}