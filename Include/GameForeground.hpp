#ifndef GAME_FOREGROUND_HPP
#define GAME_FOREGROUND_HPP

#include <SFML/Graphics.hpp>

#include <vector>

class GameForeground {
public:
	GameForeground(sf::RenderWindow&);
	
	bool update(sf::Time);
	void draw();
	
private:
	void addRoadBlock(float, float);
	
private:
	sf::RenderWindow& window;
	sf::View viewPort;
	sf::FloatRect bounds;
	
	std::vector<sf::Sprite> roads;
	
	sf::Texture roadTexture;
};

#endif