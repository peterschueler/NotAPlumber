#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class World : public sf::NonCopyable {
public:
	explicit World(sf::RenderWindow&);
	
	bool update(sf::Time time);
	void draw();
	
	void input(Command*);
	
private:
	sf::RenderWindow& window;
	sf::FloatRect bounds;
};

#endif