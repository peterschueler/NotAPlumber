#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

#include <string>

class Entity : public sf::Drawable, public sf::Transformable {
public:
	Entity();
	virtual void update(sf::Time);
	
	virtual sf::FloatRect borders() const;
	
protected:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void attachTexture(std::string);
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif