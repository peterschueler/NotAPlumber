#ifndef CHARACTER_ENTITY_HPP
#define CHARACTER_ENTITY_HPP

#include "Entity.hpp"

class CharacterEntity : public Entity {
public:
	enum Modifier {
		invicible,
		superfast,
		levitating,
		none
	};
	enum Direction {
		left,
		right,
		still
	};
public:
	CharacterEntity();
	CharacterEntity(unsigned int);
	virtual void update(sf::Time);
	
	// encompasses walking (+x) and jumping (+y)
	void setVelocity(float, float);
	sf::Vector2f getVelocity() const;
	
	virtual sf::FloatRect borders() const;
	
	virtual void applyGravity(bool);
	virtual void animate();
	
	float getGrounded() const;
	void setGrounded(float);
	
	bool getJumping() const;
	
	void hit(unsigned int);
	unsigned int getHitPoints() const;
	
	void shoot() const;
	
	void setModifier(Modifier);
	
protected:	
	virtual void attachTexture(std::string);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	enum AnimationStep {
		first_x,
		second_x,
		third_x,
		first_y,
		second_y,
		third_y
	};
	AnimationStep currentStep;
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	sf::Vector2f velocity;
	sf::Vector2f gravity;
	bool gravityOn;
	float bottom;
	
	bool isJumping;
	bool spacebarPressed;

	Direction walkingDirection;
	
	unsigned int hitpoints;
	Modifier modification;
};

#endif