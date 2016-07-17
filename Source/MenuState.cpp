#include "../Include/States/MenuState.hpp"
#include "../Include/States/GameState.hpp"

MenuState::MenuState(sf::RenderWindow& win) : window(&win), handler(), gameStarted(false), menu(win) {
}

bool MenuState::processInput(sf::Event& event) {
	while (window->pollevent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
				window->close();
			}
		}
	}
	return true;
}

bool MenuState::update(sf::Time delta) {
	menu.update(delta);
	return true;
}

void MenuState::onEntry(State* previousState) {
	delete previousState;
}

State* MenuState::onExit() {
	return new GameState(*window);
}

void MenuState::render() {
	window->clear();
	menu.draw();
	window->display();
}