#include "../Include/GameForeground.hpp"

GameForeground::GameForeground(sf::RenderWindow& window) : window(window), viewPort(window.getDefaultView()), bounds(0.f, 0.f, window.getDefaultView().getSize().x, window.getDefaultView().getSize().y) {
	for (unsigned int x = 0; x < (192*3); x += 192) {
		addRoadBlock(x, 400);
	}
	addRoadBlock(600, 350);
	addRoadBlock(792, 350);
}

bool GameForeground::update(sf::Time time) {
	return true;
}

void GameForeground::draw() {
	for (auto road : roads) {
		window.draw(road);
	}
}

void GameForeground::addRoadBlock(float x, float y) {
	sf::Sprite road;
	std::string roadPath = "Assets/Textures/YellowBricks.png";
	sf::IntRect textureRect(0, 0, 192, 64);
	if (roadTexture.loadFromFile(roadPath)) {
		roadTexture.setRepeated(true);
		road.setTexture(roadTexture);
		road.setTextureRect(textureRect);
	}
	road.setPosition(x, y);
	roads.push_back(std::move(road));
}