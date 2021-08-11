// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream> 
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Cell.h"
#include <crtdbg.h>

using namespace sf;

enum class gameStatus { PLAYING, PAUSE }; // is the cell dead or alive ? 

int main()
{
	gameStatus gameState = gameStatus::PAUSE;
	
	Vector2f resolution;
	//get the desktops sizes for x and y
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	VideoMode vm(resolution.x, resolution.y);

	RenderWindow window(vm, "Game Of Life", Style::Close | Style::Fullscreen );
	

	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	Vector2f mouseWorldPosition;
	Vector2i mouseScreenPosition;

	//background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Texture cellTextDead;
	Texture cellTextAlive;
	
	cellTextAlive.loadFromFile("graphics/cell_alive.png");
	cellTextDead.loadFromFile("graphics/cell_dead.png");

	Texture allText[2] = { cellTextAlive, cellTextDead };
	Texture* ptrText = allText;

	Clock clock; // control time

	//time,fps in text
	Text TimeText;
	

	//middle the text to its bounds
	FloatRect textRect = TimeText.getLocalBounds();
	TimeText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	
	Font font;
	font.loadFromFile("fonts/PerfectPixel.ttf");

	TimeText.setFont(font);

	TimeText.setString("Time = 0 seconds");
	TimeText.setCharacterSize(50);
	TimeText.setFillColor(Color::Black);
	TimeText.setPosition(0, 0);
	
	
	
	float countedTime; // games runtime
	
	int cell_spawn_x = resolution.x - 20;
	int cell_spawn_y = resolution.y - 20;
	
	const int amountOfCells = 4750;
	Cell* cells[amountOfCells];
	
	for (int i = 0; i < amountOfCells; i++) {

		if (cell_spawn_x == 0) {
			cell_spawn_x = 1900;
			cell_spawn_y = cell_spawn_y - 20;
		}

		cells[i] = new Cell(cell_spawn_x, cell_spawn_y, false, allText);
		cell_spawn_x -= 20;
	}

	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			
			window.close();
	
		} // if esc pressed kill the window

		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			if (gameState == gameStatus::PAUSE) {
				gameState = gameStatus::PLAYING;
				
				

				countedTime = 0.0f;
				clock.restart();
			}
			
		}

		if (gameState != gameStatus::PAUSE) {
			
			

			//updating time
			std::stringstream ss;
			Time dt = clock.restart(); // res the clock
			countedTime += dt.asSeconds();
			ss << "Time = " << countedTime;
			TimeText.setString(ss.str());

		}
		
		if (gameState == gameStatus::PAUSE) {
			mouseScreenPosition = Mouse::getPosition();
			
			
			//if (Mouse::isButtonPressed(Mouse::Left)) {
			//	FloatRect wow = cells[4724]->getPosition();
			//	std::cout << wow.top << " " << wow.left << std::endl;
			//	std::cout << wow.width << " " << wow.height << std::endl;
				/*for (int i = 0; i < amountOfCells; i++)
				{
					if (cells[i]->getPosition().contains(mouseScreenPosition.x, mouseScreenPosition.y)) {
						cells[i]->update(ptrText);
						break;
					}*/
			//		

			//	/*}*/
			//}

			

		}
		
		
		
		Event event; // event test
		while (window.pollEvent(event)) {
			
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				for (int i = 0; i < amountOfCells; i++) {
					cells[i]->update(mouseScreenPosition.x, mouseScreenPosition.y, ptrText);
					
				}
				
				break;
			default:
				break;
			}
		}

		window.clear(Color::White); // clear the window

		
		window.draw(TimeText);// draw the time
		
			
		for (int i = 0; i < amountOfCells; i++)
		{
			window.draw(cells[i]->getSprite());
		}
			
			
		
		window.display(); // update the window
	}
	if (gameState == gameStatus::PLAYING) {
		for (int i = 0; i < amountOfCells; i++) {
	
			delete cells[i];
		
		}
		
	}
	else {
		cells[0] = NULL;
	}
	
	return 0;
}
