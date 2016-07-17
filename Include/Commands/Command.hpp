#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
	virtual void execute(Entity&) = 0;
};

#endif