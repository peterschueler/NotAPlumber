#include "../Include/EndMenu.hpp"

#include <iostream>
#include <string>

EndMenu::EndMenu(sf::RenderWindow& win, bool hasWon) : window(win), bounds(0.f, 0.f, 800, 576) {
	if (!font.loadFromFile("Assets/Fonts/Pixel_01.ttf")) {
		std::cerr << "Sorry, couldn't load your font." << std::endl;
	}
	if (hasWon) {
		std::cout << "called menu" << std::endl;
		displayText.setFont(font);
		displayText.setString("\tYou have entered a place of unbounded joy\n\n\tYou will be rewarded...\n\n\teventually. I promise.\n\n\tDon't believe me? Well, suit yourself then.\n\n\n\n\n\n\tPress S to Reset");
		displayText.setCharacterSize(20);
		displayText.setPosition(bounds.left + 100, bounds.top + 100);
	} else {
		displayText.setFont(font);
		displayText.setString("\tYou lost! This is simply\n\n\tunacceptable.\n\n\tYou will have to try again.\n\n\tGo on, it is not that hard.\n\n\n\n\n\n\tPress S to Reset");
		displayText.setCharacterSize(20);
		displayText.setPosition(bounds.left + 100, bounds.top + 100);
	}
}

void EndMenu::update(sf::Time delta) {
}

void EndMenu::draw() {
	window.draw(displayText);
}