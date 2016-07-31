#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Commands/Command.hpp"
#include "GameBackground.hpp"
#include "Entities/CharacterEntity.hpp"
#include "Entities/MonsterEntity.hpp"
#include "Entities/RoadEntity.hpp"
#include "Entities/FlagpoleEntity.hpp"

class Game : public sf::NonCopyable {
public:
	explicit Game(sf::RenderWindow&);
	
	bool update(sf::Time time);
	void draw();
	
	void input(Command*);
	
	bool getWon() const;
	
private:
		void addRoadBlock(float, float);
		// takes the x and y values of the first one and number of followers
		void addRoadBlocks(float, float, unsigned int);
		void checkCollision(Entity*);
		
		void initMonsters(unsigned int);
		void setupMonster(float, float, MonsterEntity::Type);
		
private:
	sf::RenderWindow& window;
	sf::View viewPort;
	sf::FloatRect bounds;
	
	std::vector<RoadEntity*> roads;
	sf::Texture roadTexture;
	
	GameBackground background;
	
	std::vector<MonsterEntity*> monsters;
	
	CharacterEntity* character;
	float timer;
	
	FlagpoleEntity* flagpole;
	
	bool hasWon;
	
	sf::Music theme;
};

#endif