#ifndef END_MENU_HPP
#define END_MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class EndMenu : public sf::NonCopyable {
public:
	explicit EndMenu(sf::RenderWindow&, bool);
	
	void update(sf::Time);
	void draw();
	
private:
	sf::RenderWindow& window;
	sf::FloatRect bounds;
	
	sf::Text displayText;
	sf::Font font;
};

#endif