#ifndef MODIFIER_ENTITY_HPP
#define MODIFIER_ENTITY_HPP

#include "CharacterEntity.hpp"

class ModifierEntity : public Entity {
public:
	ModifierEntity();
	ModifierEntity(CharacterEntity::Modifier);
	virtual void update(sf::Time);
	
	CharacterEntity::Modifier getModifierType() const;
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	CharacterEntity::Modifier modifier;
};

#endif