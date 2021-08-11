#include "stdafx.h"
#include "Cell.h"

using namespace std;


Cell::Cell(float x,float y,bool stat,Texture* text) {
	
	cellPos.x = x;
	cellPos.y = y;
	
	if (stat == false) {
		cellStatus = stat;
		cellSprite.setTexture(*(text + 1));
		cellSprite.setOrigin(10, 10);
		cellSprite.setPosition(cellPos);
	}

	if (stat == true) {
		cellStatus = stat;
		cellSprite.setTexture(*text);
		cellSprite.setOrigin(10, 10);
		cellSprite.setPosition(cellPos);
	}
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

void Cell::update(float x, float y, Texture* text) {
	if (this->getPosition().contains(x, y)) {
		if (!this->cellStatus) {
			this->cellStatus = true;
			this->cellSprite.setTexture(*text);
		}
		else if (this->cellStatus){
			this->cellStatus = false;
			this->cellSprite.setTexture(*(text + 1));
		}
	}
}

