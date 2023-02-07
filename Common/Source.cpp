#include <ctime>
#include "Tile.h"

std::array<Tile*, HOR_TILE_COUNT* VERT_TILE_COUNT> tileArray{};

void Generate()
{
	int x = 0;
	int y = -TILE_SIZE;
	for (int i = 0; i < HOR_TILE_COUNT * VERT_TILE_COUNT; i++)
	{
		if (!(i % HOR_TILE_COUNT))
		{
			x = 0;
			y += TILE_SIZE;
		}

		Tile* pTile = new Tile(x, y, rand() % 100 < MINE_CHANCE ? mine : empty);
		tileArray[i] = pTile;

		x += TILE_SIZE;
	}
}

void Calculate()
{
	for (int i = 0; i < HOR_TILE_COUNT * VERT_TILE_COUNT; i++)
	{
		int mines = 0;
		if ((i - 1 >= 0) && (i % HOR_TILE_COUNT)) // left tiles accessible
		{
			if (tileArray[i - 1]->GetType() == mine) //left
				mines++;
			if ((i - HOR_TILE_COUNT - 1 >= 0) && (tileArray[i - HOR_TILE_COUNT - 1]->GetType() == mine)) //top-left
				mines++;
			if ((i + HOR_TILE_COUNT - 1 < HOR_TILE_COUNT * VERT_TILE_COUNT) && (tileArray[i + HOR_TILE_COUNT - 1]->GetType() == mine)) //bot-left
				mines++;
		}
		if ((i + 1 < HOR_TILE_COUNT * VERT_TILE_COUNT) && (i % HOR_TILE_COUNT < HOR_TILE_COUNT - 1)) // right tiles accessible
		{
			if (tileArray[i + 1]->GetType() == mine) //right
				mines++;
			if ((i - HOR_TILE_COUNT + 1 >= 0) && (tileArray[i - HOR_TILE_COUNT + 1]->GetType() == mine)) //top-right
				mines++;
			if ((i + HOR_TILE_COUNT + 1 < HOR_TILE_COUNT * VERT_TILE_COUNT) && (tileArray[i + HOR_TILE_COUNT + 1]->GetType() == mine)) //bot-right
				mines++;
		}
		if ((i - HOR_TILE_COUNT >= 0) && (tileArray[i - HOR_TILE_COUNT]->GetType() == mine)) //top-mid
			mines++;
		if ((i + HOR_TILE_COUNT < HOR_TILE_COUNT * VERT_TILE_COUNT) && (tileArray[i + HOR_TILE_COUNT]->GetType() == mine)) //bot-mid
			mines++;

		tileArray[i]->SetNumOfMines(mines);
	}
}

void Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < HOR_TILE_COUNT * VERT_TILE_COUNT; i++)
	{
		//tileArray[i]->Update();
		window->draw(tileArray[i]->GetSprite());
	}
}

void DoClick(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	for (auto i : tileArray)
	{
		if (i->HitTest(mousePos.x, mousePos.y))
		{
			i->SetState(checked);
			return;
		}
	}

}

int main()
{
	std::srand(std::time(nullptr));
	sf::RenderWindow window(sf::VideoMode(HOR_TILE_COUNT * TILE_SIZE, VERT_TILE_COUNT * TILE_SIZE), "Minesweeper");
	Generate();
	Calculate();
	while (window.isOpen())
	{
		window.clear();
		Draw(&window);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				for (auto i : tileArray)
				{
					delete i;
				}
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				DoClick(&window);
			}
		}
	}

	return 0;
}