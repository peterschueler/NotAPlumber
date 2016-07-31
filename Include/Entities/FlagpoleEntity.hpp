#ifndef FLAGPOLE_ENTITY_HPP
#define FLAGPOLE_ENTITY_HPP

#include "Entity.hpp"

class FlagpoleEntity : public Entity {
public:
	FlagpoleEntity();
	virtual void update(sf::Time);
	
	virtual void setVelocity(float, float);
	
	bool getOn() const;
	void setOn(bool);
	
	virtual sf::FloatRect borders() const;
	
protected:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void attachTexture(std::string);	

private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	bool isOn;
};

#endif