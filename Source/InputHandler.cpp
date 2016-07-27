#include "../Include/InputHandler.hpp"
#include "../Include/Commands/MoveCommand.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
			return new MoveCommand(-30.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Right) {
			return new MoveCommand(30.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Space) {
			return new MoveCommand(0.f, -100.f);
		}
	}
	return new MoveCommand(0.f,0.f);
}