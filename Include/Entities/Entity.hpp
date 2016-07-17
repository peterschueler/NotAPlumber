#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
public:
	Entity();
	virtual void update(sf::Time);
	
	virtual sf::FloatRect borders() const;
	
	void setDirection(float, float);
	sf::Vector2f getDirection() const;
	
protected:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void attachTexture();
	
private:
	sf::Sprite sprite;
	sf::Vector2f direction;
};

#endif