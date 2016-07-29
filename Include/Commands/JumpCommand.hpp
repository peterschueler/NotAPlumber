#ifndef JUMP_COMMAND_HPP
#define JUMP_COMMAND_HPP

#include "Command.hpp"

class JumpCommand : public Command {
public:
	JumpCommand(float, float);
	virtual void execute(Entity&);
	
private:
	float x;
	float y;
};

#endif