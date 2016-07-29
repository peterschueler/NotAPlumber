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

void ProjectileEntity::setVelocity(float x, float y) {
	direction.x += x;
	direction.y += y;
}

sf::Vector2f ProjectileEntity::setVelocity() const {
	return direction;
}