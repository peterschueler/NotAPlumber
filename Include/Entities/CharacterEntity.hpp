#ifndef CHARACTER_ENTITY_HPP
#define CHARACTER_ENTITY_HPP

#include "Entity.hpp"

class CharacterEntity : public Entity {
public:
	enum Type {
		player,
		monster
	};
	enum Modifier {
		invicible,
		superfast,
		levitating
	};
public:
	CharacterEntity();
	CharacterEntity(Type, unsigned int);
	virtual void update(sf::Time);
	
	// encompasses walking (+x) and jumping (+y)
	void setDirection(float, float);
	sf::Vector2f getDirection() const;
	
	void hit(unsigned int);
	unsigned int getHitPoints() const;
	
	void shoot() const;
	
	void setModifier(Modifier);
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
	
	Type type;
	
	unsigned int hitpoints;
	Modifier modified;
};

#endif