#include "../Include/Commands/JumpCommand.hpp"

#include <iostream>

JumpCommand::JumpCommand(float vx, float vy) : x(vx), y(vy) {
}

void JumpCommand::execute(Entity& entity) {
	entity.setVelocity(entity.setVelocity().x, y);
	std::cout << entity.setVelocity().x << std::endl;
	entity.applyGravity(true);
}