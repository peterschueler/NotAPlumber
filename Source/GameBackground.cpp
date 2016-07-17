#include "../Include/GameBackground.hpp"

GameBackground::GameBackground(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 4000, window.getDefaultView().getSize().y) {
	std::string skyPath = "Assets/Textures/BlueSky.png";
	std::string cloudPath = "Assets/Textures/WhiteClouds.png";
	std::string mountainPath = "Assets/Textures/GreenMountains.png";
	
	sf::IntRect rect = sf::IntRect(bounds);
	if (skyTexture.loadFromFile(skyPath)) {
		skyTexture.setRepeated(true);
		sky.setTexture(skyTexture);
		sky.setTextureRect(rect);
	}
	if (cloudsTexture.loadFromFile(cloudPath)) {
		cloudsTexture.setRepeated(true);
		clouds.setTexture(cloudsTexture);
		clouds.setTextureRect(rect);
	}
	if (mountainsTexture.loadFromFile(mountainPath)) {
		mountainsTexture.setRepeated(true);
		mountains.setTexture(mountainsTexture);
		mountains.setTextureRect(rect);
	}
}

bool GameBackground::update(sf::Time delta) {
	viewPort.move(30.f * delta.asSeconds(), 0.f);
	clouds.move(35.f * delta.asSeconds(), 0.f);
	return true;
}

void GameBackground::draw() {
	window.setView(viewPort);
	window.draw(sky);
	window.draw(clouds);
	window.draw(mountains);
}