#include "../Include/Commands/JumpCommand.hpp"

#include <iostream>

JumpCommand::JumpCommand(float vx, float vy) : x(vx), y(vy) {
}

void JumpCommand::execute(Entity& entity) {
	entity.setVelocity(entity.getVelocity().x, y);
	entity.applyGravity(true);
}