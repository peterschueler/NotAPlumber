#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Entities/Entity.hpp"

class Command {
public:
	virtual void execute(Entity&) = 0;
};

#endif