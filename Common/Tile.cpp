#include "Tile.h"
#include <iostream>

Tile::Tile(int X, int Y, TileType ty)
{
	numOfMines = 0;
	state = unchecked;
	type = ty;
	positionX = X;
	positionY = Y;

	if (!texture.loadFromFile(SPRITE_SHEET, sf::IntRect(UNCHECKED_POS[0], UNCHECKED_POS[1], TILE_SIZE, TILE_SIZE))) //TILE_SIZE
	{
		std::cout << "error" << std::endl;
	}

	sprite.setTexture(texture);
	sprite.move(positionX, positionY);
}

Tile::~Tile()
{

}

void Tile::SetState(TileState S)
{
	state = S;
	Update();
}

void Tile::Update()
{
	int tileposx = 0;
	int tileposy = 0;

	if (type == mine)
	{
		tileposx = MINE_POS[0];
		tileposy = MINE_POS[1];
	}
	else
	{
		switch (numOfMines)
		{
		case 0:
			tileposx = EMPTY_POS[0];
			tileposy = EMPTY_POS[1];
			break;
		case 1:
			tileposx = ONE_POS[0];
			tileposy = ONE_POS[1];
			break;
		case 2:
			tileposx = TWO_POS[0];
			tileposy = TWO_POS[1];
			break;
		case 3:
			tileposx = THREE_POS[0];
			tileposy = THREE_POS[1];
			break;
		case 4:
			tileposx = FOUR_POS[0];
			tileposy = FOUR_POS[1];
			break;
		case 5:
			tileposx = FIVE_POS[0];
			tileposy = FIVE_POS[1];
			break;
		case 6:
			tileposx = SIX_POS[0];
			tileposy = SIX_POS[1];
			break;
		case 7:
			tileposx = SEVEN_POS[0];
			tileposy = SEVEN_POS[1];
			break;
		case 8:
			tileposx = EIGHT_POS[0];
			tileposy = EIGHT_POS[1];
			break;
		}
	}

	if (!texture.loadFromFile(SPRITE_SHEET, sf::IntRect(tileposx, tileposy, TILE_SIZE, TILE_SIZE)))
	{
		std::cout << "error" << std::endl;
	}
	sprite.setTexture(texture);
}

bool Tile::HitTest(int x, int y)
{
	if ((x >= sprite.getPosition().x) && (x < sprite.getPosition().x + TILE_SIZE) && (y >= sprite.getPosition().y) && (y < sprite.getPosition().y + TILE_SIZE))
		return true;
	else
		return false;
}

void Tile::Calculate()
{

}