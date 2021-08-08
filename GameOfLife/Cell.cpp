#include "stdafx.h"
#include "TextureHolder.h"
#include "Cell.h"

using namespace std;

void Cell::spawn(int x, int y, bool stat) {
	cellStatus = stat;
	Texture cellText;
	cellText.loadFromFile("graphics/cell_alive.png");
	if (!stat) {
		//cellText.loadFromFile("graphics/cell_dead.png");
		
		cellSprite.setTexture(cellText);
	}
	else {
		cellText.loadFromFile("graphics/cell_alive.png");
		cellSprite = Sprite(cellText);
	}
	cellPos.x = x;
	cellPos.y = y;

	cellSprite.setOrigin(10, 10);
	cellSprite.setPosition(x,y);
	
}

bool Cell::isAlive() {
	return cellStatus;
}

FloatRect Cell::getPosition(){
	return cellSprite.getGlobalBounds();
}

Sprite Cell::getSprite() {
	return cellSprite;
}