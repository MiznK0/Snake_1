#pragma once
#include "level.h"

class Snake
{
public:
	
	Snake();
	Snake(level* );
	sf::Vector2u FindPointer(direction);
	void move();
	void grow_move();
	std::vector<sf::Vector2u> GetBody();
	level* map;
	
	

private:

	int length;
	sf::Vector2u pointer;
	std::vector<sf::Vector2u> body;
	void FrontUpdate(direction);
	direction Front = direction::UP;
	direction Back = direction::DOWN;
};

