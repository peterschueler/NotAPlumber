#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

#include <string>

class Entity : public sf::Drawable, public sf::Transformable {
public:
	Entity();
	virtual void update(sf::Time);
	
	virtual sf::FloatRect borders() const;
	
	virtual void setVelocity(float, float) = 0;
	virtual sf::Vector2f getVelocity() const;
	
	virtual void applyGravity(bool);
	
protected:
	// if one is overridden, the other one must be overridden as well!
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void attachTexture(std::string);
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool isGrounded;
	
	sf::Vector2f gravity;
	bool gravityOn;
};

#endif