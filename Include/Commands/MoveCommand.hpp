#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include "Command.hpp"

class MoveCommand : public Command {
public:
	MoveCommand(float, float);
	virtual void execute(Entity&);
	
private:
	float x;
	float y;
};

#endif