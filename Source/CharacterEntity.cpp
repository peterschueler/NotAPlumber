#include "../Include/Entities/CharacterEntity.hpp"

#include <iostream>

CharacterEntity::CharacterEntity() : sprite(), texture(), hitpoints(100), type(monster) {
	attachTexture("Assets/Textures/Character.png");
}

CharacterEntity::CharacterEntity(Type type, unsigned int hits) : sprite(), texture(), velocity(sf::Vector2f(0.f, 0.f)), gravity(sf::Vector2f(0.f, 300.f)), gravityOn(false), bottom(200.f), isJumping(false), type(type), walkingDirection(still), hitpoints(hits), modification(none) {
	attachTexture("Assets/Textures/Character.png");
}

void CharacterEntity::update(sf::Time delta) {
	if (gravityOn && !isJumping) {
		velocity.y = -gravity.y;
		isJumping = true;
		gravityOn = false;
	}
	if (isJumping) {
		velocity.y += (gravity.y * delta.asSeconds());
		if (walkingDirection == right) {
			velocity.x += (gravity.y * delta.asSeconds());
		} else if (walkingDirection == left) {
			velocity.x -= (gravity.y * delta.asSeconds());
		}
		
	}
	move(velocity * delta.asSeconds());
}

void CharacterEntity::setVelocity(float x, float y) {
	if (x == 100) {
		walkingDirection = right;
	} else if (x == -100) {
		walkingDirection = left;
	}
	velocity.x = x;
	velocity.y = y;
}

sf::Vector2f CharacterEntity::getVelocity() const {
	return velocity;
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
		sprite.setTextureRect(sf::IntRect(64,64,64,64));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}

sf::FloatRect CharacterEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}

void CharacterEntity::applyGravity(bool now) {
	gravityOn = now;
}

float CharacterEntity::getGrounded() const {
	return bottom;
}

void CharacterEntity::setGrounded(float ground) {
	setPosition(sf::Vector2f(getPosition().x, ground));
	isJumping = false;
	walkingDirection = still;
	bottom = ground;
}

bool CharacterEntity::getJumping() const {
	return isJumping;
}