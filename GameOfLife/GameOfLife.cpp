// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"

using namespace sf;

int main()
{
	VideoMode vm(1200, 960);

	RenderWindow window(vm, "Game Of Life", Style::Fullscreen);
	
	Texture textureBackground;
	
	textureBackground.loadFromFile("graphics/background.png");

	Sprite spriteBackground;

	spriteBackground.setTexture(textureBackground);

	spriteBackground.setPosition(0, 0);

	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		} // if esc pressed kill the window

		window.clear(); // clear the window

		window.draw(spriteBackground); // background

		window.display(); // update the window
	}
	return 0;
}
