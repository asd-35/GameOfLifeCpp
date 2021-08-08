#include "stdafx.h"
#include "TextureHolder.h"
#include "Cell.h"

using namespace std;

void Cell::spawn(int x, int y, bool stat) {
	cellStatus = stat;
	Texture cellText;
	cellText.loadFromFile("graphics/cell_dead.png");
	if (!stat) {
		cellSprite = Sprite(cellText);
	}
	else {
		cellSprite = Sprite(TextureHolder::GetTexture("graphics/cell_alive.png"));
	}
	cellPos.x = x;
	cellPos.y = y;

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