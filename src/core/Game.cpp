#include "Game.h"
#include <stdio.h> //printf
Game::Game(){
	
}

Game::~Game(){

}
//load textures and audio
void Game::Initialize(const sf::RenderWindow& window){
	m_Texture.loadFromFile("asset/circle.jpg");
	m_Texture.setSmooth(true); //turn on filtering

	m_Sprite.setTexture(m_Texture);

	m_Bounds  = glm::vec2(window.getSize().x,window.getSize().y);

	m_Position = m_Bounds * 0.5f; // start in the middle
	m_Velocity = glm::vec2(-1000.0f,-1000.0f);

	m_Sprite.setScale(100.0f / m_Texture.getSize().x, 100.0f / m_Texture.getSize().y);
}
//update game state
void Game::Update(const sf::Clock& gameTime){
	
	if(m_Position.x <= 0 || (m_Position.x + m_Texture.getSize().x * m_Sprite.getScale().x) > m_Bounds.x)
		m_Velocity.x *= -1.0f;
	if(m_Position.y <= 0 || (m_Position.y + m_Texture.getSize().y * m_Sprite.getScale().y) > m_Bounds.y)
		m_Velocity.y *= -1.0f;
	m_Position += m_Velocity * gameTime.getElapsedTime().asSeconds();
	m_Sprite.setPosition(m_Position.x,m_Position.y);

}
//render game state
void Game::Draw(sf::RenderWindow& window){
	m_Sprite.setTexture(m_Texture);
	window.draw(m_Sprite);
}