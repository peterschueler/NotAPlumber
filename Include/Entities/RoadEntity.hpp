#ifndef ROAD_ENTITY_HPP
#define ROAD_ENTITY_HPP

#include "Entity.hpp"

class RoadEntity : public Entity {
public:
	RoadEntity();
	RoadEntity(float, float);
	virtual void update(sf::Time);
	
	virtual void setVelocity(float, float);
	
	virtual sf::FloatRect borders() const;
	
protected:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void attachTexture(std::string);
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	float length;
	float height;
};

#endif