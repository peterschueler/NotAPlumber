#include "../Include/Menu.hpp"

#include <iostream>
#include <string>

Menu::Menu(sf::RenderWindow& win) : window(win), bounds(0.f, 0.f, window.getDefaultView().getSize().x, window.getDefaultView().getSize().y) {
	if (!font.loadFromFile("Assets/Fonts/Pixel_01.ttf")) {
		std::cerr << "Sorry, couldn't load your font." << std::endl;
	}
	displayText.setFont(font);
	displayText.setString("Welcome to Not A Plumber!\n\n\nA videogame by @peterschueler\n\n\n\n\n\n\t\tPress S to Start\n\n\t\tPress Esc for Pause\n\n\t\tPress Q to Quit");
	displayText.setCharacterSize(20);
	displayText.setPosition(bounds.left + 100, bounds.top + 100);
}

void Menu::update(sf::Time delta) {
}

void Menu::draw() {
	window.draw(displayText);
}