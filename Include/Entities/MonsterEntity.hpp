#ifndef MONSTER_ENTITY_HPP
#define MONSTER_ENTITY_HPP

#include "Entity.hpp"

class MonsterEntity : public Entity {
public:
	enum Type {
		monster_flyer,
		monster_crawler
	};
public:
	MonsterEntity();
	MonsterEntity(Type, unsigned int);
	virtual void update(sf::Time);
	
	void setVelocity(float, float);
	sf::Vector2f getVelocity() const;
	
	virtual sf::FloatRect borders() const;
	
protected:
	virtual void attachTexture(std::string);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	sf::Vector2f velocity;
	sf::Vector2f gravity;
	
	unsigned int hitpoints;
	Type type;
};

#endif