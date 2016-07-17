#include "../Include/InputHandler.hpp"
#include "../Include/Commands/Command.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	return new Command();
}