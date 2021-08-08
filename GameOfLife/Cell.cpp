#include "stdafx.h"
#include "Cell.h"

using namespace std;


Cell::Cell(float x,float y,bool stat,Texture &text) {
	
	cellPos.x = x;
	cellPos.y = y;
	cellStatus = stat;
	cellSprite.setTexture(text);
	cellSprite.setOrigin(10, 10);
	cellSprite.setPosition(cellPos);
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


