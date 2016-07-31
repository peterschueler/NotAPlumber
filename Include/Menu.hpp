#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu : public sf::NonCopyable {
public:
	explicit Menu(sf::RenderWindow&);
	
	void update(sf::Time);
	void draw();
	
private:
	sf::RenderWindow& window;
	sf::FloatRect bounds;
	
	sf::Text displayText;
	sf::Font font;
};

#endif