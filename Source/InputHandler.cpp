#include "../Include/InputHandler.hpp"
#include "../Include/Commands/MoveCommand.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	return new MoveCommand(0,0);
}