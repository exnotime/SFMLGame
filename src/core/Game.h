#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
class Game
{
public:
	Game();
	~Game();
	void Initialize(const sf::RenderWindow& window);
	void Update(const sf::Clock& gameTime);
	void Draw(sf::RenderWindow& window);
private:
	//these are all just example variables
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	glm::vec2 m_Velocity;
	glm::vec2 m_Position;
	glm::vec2 m_Bounds;
};