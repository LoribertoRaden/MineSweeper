#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.cpp"

enum TileState { unchecked, checked };
enum TileType { empty, mine };

class Tile
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int positionX;
	int positionY;
	int numOfMines;
	TileState state;
	TileType type;
public:
	Tile(int posX, int posY, TileType type);
	~Tile();
	sf::Sprite GetSprite() { return sprite; };
	TileType GetType() { return type; };
	void SetState(TileState S);
	void SetNumOfMines(int n) { numOfMines = n; };
	void Update();
	bool HitTest(int x, int y);
	void Calculate();
};

