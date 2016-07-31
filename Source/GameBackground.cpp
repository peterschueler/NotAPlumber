#include "../Include/GameBackground.hpp"

#include <iostream>

GameBackground::GameBackground(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, 8000, window.getDefaultView().getSize().y) {
	std::string skyPath = "Assets/Textures/Sky.png";
	std::string cloudPath = "Assets/Textures/Stars.png";
	std::string mountainPath = "Assets/Textures/Landscape.png";
	
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
	return true;
}

void GameBackground::draw() {
	window.setView(viewPort);
	window.draw(sky);
	window.draw(clouds);
	window.draw(mountains);
}

void GameBackground::move(float vx, float vy) {
	viewPort.move(vx, vy);
}