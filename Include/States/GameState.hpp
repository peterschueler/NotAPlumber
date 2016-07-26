#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"
#include "../Include/Game.hpp"
#include "../Include/InputHandler.hpp"

class GameState : public State {
public:
	GameState(sf::RenderWindow&);
	
	bool processInput(sf::Event&);
	bool update(sf::Time);
	void onEntry(State*);
	State* onExit();
	void render();
	
	void setPause();
	bool getPause();
	
private:
	sf::RenderWindow* window;
	InputHandler handler;
	
	bool isPaused;
	
	Game game;
};

#endif