#ifndef PROJECTILE_ENTITY_HPP
#define PROJECTILE_ENTITY_HPP

#include "Entity.hpp"

class ProjectileEntity : public Entity {
public:
	enum Type {
		small,
		medium,
		large
	};
public:
	ProjectileEntity();
	ProjectileEntity(Type);
	virtual void update(sf::Time);
	
	unsigned int getStrength() const;
	
	void setVelocity(float, float);
	sf::Vector2f setVelocity() const;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
	
	unsigned int stregth;
	
	Type type;
};

#endif