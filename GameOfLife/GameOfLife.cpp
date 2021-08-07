// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream> 
#include "SFML\Graphics.hpp"


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

	RenderWindow window(vm, "Game Of Life", Style::Default);
	
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	Vector2f mouseWorldPosition;
	Vector2i mouseScreenPosition;

	//background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	
	

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
	TimeText.setFillColor(Color::White);
	TimeText.setPosition(0, 0);
	
	
	
	
	float countedTime; // games runtime
	
	
	

	


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
			
			mouseScreenPosition = Mouse::getPosition();
			mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

			//updating time
			std::stringstream ss;
			Time dt = clock.restart(); // res the clock
			countedTime += dt.asSeconds();
			ss << "Time = " << countedTime;
			TimeText.setString(ss.str());

		}
		else {

		}
		
		
		
		Event event; // event test
		while (window.pollEvent(event)) {
			
		}

		window.clear(); // clear the window

		window.draw(spriteBackground); // background draw
		window.draw(TimeText);// draw the time
		window.display(); // update the window
	}
	return 0;
}
