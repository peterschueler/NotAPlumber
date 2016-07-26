#include "../Include/Entities/ProjectileEntity.hpp"

ProjectileEntity::ProjectileEntity() : type(small) {
}

ProjectileEntity::ProjectileEntity(Type type) : type(type) {
}

void ProjectileEntity::update(sf::Time delta) {
}

unsigned int ProjectileEntity::getStrength() const {
	return stregth;
}

void ProjectileEntity::setDirection(float x, float y) {
	direction.x += x;
	direction.y += y;
}

sf::Vector2f ProjectileEntity::getDirection() const {
	return direction;
}