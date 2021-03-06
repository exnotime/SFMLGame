#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
int main() {
	sf::RenderWindow& window = sf::RenderWindow(sf::VideoMode(1280, 720), "Game");
	sf::Event event;
	Game game1;
	game1.Initialize(window);

	sf::Clock gametimer;
	
	while (window.isOpen()){
		while (window.pollEvent(event)){ 
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}

		game1.Update(gametimer);

		window.clear();
		game1.Draw(window);
		window.display();

		gametimer.restart();
	}
	return 0;
}