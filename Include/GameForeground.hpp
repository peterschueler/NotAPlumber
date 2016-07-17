#ifndef GAME_FOREGROUND_HPP
#define GAME_FOREGROUND_HPP

#include <SFML/Graphics.hpp>

#include "Game.hpp"

class GameForeground {
public:
	GameForeground();
	
	bool update(sf::Time);
	void draw();
	
private:
};

#endif