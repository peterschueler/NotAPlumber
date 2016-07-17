#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Commands/Command.hpp"

class Game : public sf::NonCopyable {
public:
	explicit Game(sf::RenderWindow&);
	
	bool update(sf::Time time);
	void draw();
	
	void input(Command*);
	
private:
	sf::RenderWindow& window;
	sf::FloatRect bounds;
};

#endif