#ifndef MODIFIER_ENTITY_HPP
#define MODIFIER_ENTITY_HPP

#include "CharacterEntity.hpp"

class ModifierEntity : public Entity {
public:
	ModifierEntity();
	ModifierEntity(CharacterEntity::Type);
	virtual void update(sf::Time);
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif