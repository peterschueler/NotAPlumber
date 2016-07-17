#include "../Include/Entities/Entity.hpp"

Entity::Entity() {
	attachTexture();
}

void Entity::update(sf::Time delta) {
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform += getTransform();
	
	target.draw(sprite, states);
}

void Entity::attachTexture() {
}

sf::FloatRect Entity::borders() const {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}