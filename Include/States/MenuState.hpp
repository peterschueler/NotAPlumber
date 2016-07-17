#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "../Include/InputHandler.hpp"

class MenuState : public State {
public:
	MenuState(sf::RenderWindow&);
	
	bool processInput(sf::Event&);
	bool update(sf::Time);
	void onEntry(State*);
	State* onExit();
	void render();
	
private:
	sf::RenderWindow* window;
	InputHandler handler;
	
	bool gameStated;
	
	Menu menu;
}

#endif