#include "../Include/Entities/CharacterEntity.hpp"

#include <iostream>

CharacterEntity::CharacterEntity() : sprite(), texture(), hitpoints(100) {
	attachTexture("Assets/Textures/Glitchy.png");
}

CharacterEntity::CharacterEntity(unsigned int hits) : sprite(), texture(), velocity(sf::Vector2f(0.f, 0.f)), gravity(sf::Vector2f(0.f, 300.f)), gravityOn(false), bottom(200.f), isJumping(false), walkingDirection(still), hitpoints(hits), modification(none), currentStep(first_x), spacebarPressed(false) {
	attachTexture("Assets/Textures/Glitchy.png");
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
	} else {
		spacebarPressed = false;
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
	if (!spacebarPressed) {
		velocity.y = y;
	}
	animate();
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
		sprite.setTextureRect(sf::IntRect(0,0,64,64));
	} else {
		std::cout << "Couldn't attach texture to sprite! Add error handling for this." << std::endl;
	}
}

sf::FloatRect CharacterEntity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}

void CharacterEntity::applyGravity(bool now) {
	if (!spacebarPressed) {
		gravityOn = now;
		spacebarPressed = true;
	}
}

void CharacterEntity::animate() {
	if (walkingDirection == right) {
		if (currentStep == first_y || currentStep == second_y || currentStep == third_y) {
			currentStep = first_x;
		}
		if (currentStep == first_x) {
			sf::IntRect rect(0,0,64,64);
			sprite.setTextureRect(rect);
			currentStep = second_x;
		} else if (currentStep == second_x) {
			sf::IntRect rect(64,0,64,64);
			sprite.setTextureRect(rect);
			currentStep = third_x;
		} else if (currentStep == third_x) {
			sf::IntRect rect(128,0,64,64);
			sprite.setTextureRect(rect);
			currentStep = first_x;
		}
	} else if (walkingDirection == left) {
		if (currentStep == first_x || currentStep == second_x || currentStep == third_x) {
			currentStep = first_y;
		}
		if (currentStep == first_y) {
			sf::IntRect rect(0,64,64,64);
			sprite.setTextureRect(rect);
			currentStep = second_y;
		} else if (currentStep == second_y) {
			sf::IntRect rect(64,64,64,64);
			sprite.setTextureRect(rect);
			currentStep = third_y;
		} else if (currentStep == third_y) {
			sf::IntRect rect(128,64,64,64);
			sprite.setTextureRect(rect);
			currentStep = first_y;
		}
	}
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