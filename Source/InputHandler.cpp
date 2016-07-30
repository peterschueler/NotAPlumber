#include "../Include/InputHandler.hpp"
#include "../Include/Commands/MoveCommand.hpp"
#include "../Include/Commands/JumpCommand.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
			return new MoveCommand(-100.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Right) {
			return new MoveCommand(100.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Up) {
			return new JumpCommand(0.f, -400.f);
		}
	}
	return new MoveCommand(0.f,0.f);
}