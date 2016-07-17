#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
public:
	Entity();
	virtual void update(sf::Time);
	
	virtual sf::FloatRect borders() const;
	
protected:
	virtual void draw(sf::RenderTarget&, sf::RenderStaets) const;
	virtual void attachTexture();
	
private:
	sf::Sprite sprite;
};

#endif