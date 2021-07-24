// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"

using namespace sf;

int main()
{
	VideoMode vm(1920, 1080);

	RenderWindow window(vm, "Game Of Life", Style::Resize);

	return 0;
}

