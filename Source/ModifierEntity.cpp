#include "../Include/Entities/ModifierEntity.hpp"

ModifierEntity::ModifierEntity() {
}

ModifierEntity::ModifierEntity(CharacterEntity::Modifier modifier) : modifier(modifier) {
}

void ModifierEntity::update(sf::Time) {
}

CharacterEntity::Modifier ModifierEntity::getModifierType() const {
	return modifier;
}

void ModifierEntity::setDirection(float x, float y) {
}

sf::Vector2f ModifierEntity::getDirection() const {
	return sf::Vector2f();
}