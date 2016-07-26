#ifndef GAME_BACKGROUND_HPP
#define GAME_BACKGROUND_HPP

#include <SFML/Graphics.hpp>

#include "Commands/Command.hpp"

class GameBackground {
public:
	GameBackground(sf::RenderWindow&);
	
	bool update(sf::Time);
	
	void draw();
	
	void move(float, float);
	
private:
	sf::RenderWindow& window;
	sf::View viewPort;
	sf::FloatRect bounds;
	
	sf::Sprite sky;
	sf::Sprite clouds;
	sf::Sprite mountains;
	
	sf::Texture skyTexture;
	sf::Texture cloudsTexture;
	sf::Texture mountainsTexture;
};

#endif