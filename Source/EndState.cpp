#include "../Include/States/EndState.hpp"
#include "../Include/States/GameState.hpp"

EndState::EndState(sf::RenderWindow& win, bool won) : window(&win), handler(), menu(win, won) {
}

bool EndState::processInput(sf::Event& event) {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
				window->close();
			} else if (event.key.code == sf::Keyboard::S) {
				return false;
			} 
		}
	}
	return true;
}

bool EndState::update(sf::Time delta) {
	menu.update(delta);
	return true;
}

void EndState::onEntry(State* previousState) {
	delete previousState;
}

State* EndState::onExit() {
	return new GameState(*window);
}

void EndState::render() {
	window->clear();
	menu.draw();
	window->display();
}