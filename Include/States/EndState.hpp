#ifndef END_STATE_HPP
#define END_STATE_HPP

#include "State.hpp"
#include "../Include/InputHandler.hpp"
#include "../Include/EndMenu.hpp"

class EndState : public State {
public:
	EndState(sf::RenderWindow&, bool);
	
	bool processInput(sf::Event&);
	bool update(sf::Time);
	void onEntry(State*);
	State* onExit();
	void render();
	
private:
	sf::RenderWindow* window;
	InputHandler handler;
	
	bool gameStarted;
	
	EndMenu menu;
};

#endif