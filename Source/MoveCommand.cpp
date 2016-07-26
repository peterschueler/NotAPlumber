#include "../Include/Commands/MoveCommand.hpp"

#include <iostream>

MoveCommand::MoveCommand(float vx, float vy) : x(vx), y(vy) {
}

void MoveCommand::execute(Entity& entity) {
	entity.setDirection(x, y);
}