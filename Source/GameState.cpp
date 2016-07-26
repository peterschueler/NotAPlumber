#include "../Include/States/GameState.hpp"
#include "../Include/States/MenuState.hpp"

GameState::GameState(sf::RenderWindow& win) : window(&win), game(win), handler(), isPaused(false) {
}

bool GameState::processInput(sf::Event& event) {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				setPause();
			} else if (event.key.code == sf::Keyboard::Q) {
				window->close();
			}
		}
		game.input(handler.handleInput(event));
	}
	return true;
}

bool GameState::update(sf::Time delta) {
	if (isPaused == false) {
		if (game.update(delta) == false) {
			return false;
		}
		return true;
	}
	return true;
}

void GameState::onEntry(State* previousState) {
// 	delete previousState;
}

State* GameState::onExit() {
	return new MenuState(*window);
}

void GameState::render() {
	window->clear();
	game.draw();
	window->display();
}

void GameState::setPause() {
	isPaused = !isPaused;
}

bool GameState::getPause() {
	return isPaused;
}