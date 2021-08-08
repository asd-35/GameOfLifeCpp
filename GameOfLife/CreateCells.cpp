#include "stdafx.h"
#include "GameOfLife.h"

Cell* CreateCells(Vector2f screenSize) {
	
	//fitting as many cells into screen 
	int cellAmount = screenSize.x * screenSize.y / 100;
	Cell* cells = new Cell[cellAmount];

	int x = screenSize.x - 10;
	int y = screenSize.y - 10;

	//creating cells
	for (int i = 0; i < cellAmount; i++)
	{
		if (x == 0) {
			x = screenSize.x - 10;
			y = y - 10;
		}
		else {
			cells[i].spawn(x, y, false);
			x = x - 10;
		}

	}
	return cells;
};