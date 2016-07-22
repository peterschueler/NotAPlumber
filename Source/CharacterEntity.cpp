#include "../Include/Entities/CharacterEntity.hpp"

CharacterEntity::CharacterEntity() : hitpoints(100), type(monster) {
}

CharacterEntity::CharacterEntity(Type type, unsigned int hits) : hitpoints(hits), type(type) {
}

void CharacterEntity::update(sf::Time delta) {
}

void CharacterEntity::setDirection(float x, float y) {
	direction.x += x;
	direction.y += y;
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