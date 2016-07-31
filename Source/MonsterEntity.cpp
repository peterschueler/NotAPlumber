#include "../Include/Entities/MonsterEntity.hpp"

#include <iostream>

MonsterEntity::MonsterEntity() : sprite(), texture(), hitpoints(100), type(monster_flyer), timer(0), alpha(true), gravity(sf::Vector2f(0.f,300.f)) {
	attachTexture("Assets/Textures/monsters.png");
	sprite.setTextureRect(sf::IntRect(0,0,64,64));
}

MonsterEntity::MonsterEntity(Type type, unsigned int hitpoints) : sprite(), texture(), hitpoints(hitpoints), type(type), timer(0), alpha(true) {
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
	timer += delta.asSeconds();
	if (timer > .5) {
		swapAppearance();
		timer = 0;
	}
	if (type == monster_flyer) {
		move(velocity * delta.asSeconds());
	} else if (type == monster_crawler) {
		velocity.y += (gravity.y * delta.asSeconds());
		velocity.x -= (gravity.y * delta.asSeconds());
		move(velocity * delta.asSeconds());
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

void MonsterEntity::swapAppearance() {
	if (alpha) {
		if (type == monster_flyer) {
			sprite.setTextureRect(sf::IntRect(64,0,64,64));
		} else if (type == monster_crawler) {
			sprite.setTextureRect(sf::IntRect(64,64,64,64));
		}
		alpha = false;
	} else {
		if (type == monster_flyer) {
			sprite.setTextureRect(sf::IntRect(0,0,64,64));
		} else if (type == monster_crawler) {
			sprite.setTextureRect(sf::IntRect(0,64,64,64));
		}
		alpha = true;
	}
}

sf::FloatRect MonsterEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}

MonsterEntity::Type MonsterEntity::getType() const {
	return type;
}

float MonsterEntity::getGrounded() const {
	return bottom;
}

void MonsterEntity::setGrounded(float ground) {
	setPosition(sf::Vector2f(getPosition().x, ground));
	setVelocity(-100, 0);
	bottom = ground;
}