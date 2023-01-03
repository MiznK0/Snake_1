#include "Header.h"
#include "level.h"

level::level():collision{ false }
{
	size = sf::Vector2u(9, 9);
}

level::level(unsigned int x, unsigned int y):collision{false}
{
	x--; y--;
	if (x > 9 && x <= 99)
		 size.x = x;
	else size.x = 9;
	if (y >= 9 && y <= 99)
		size.y = y;
	else size.y = 9;
	GenAplle();
}

level::level(sf::Vector2u input)
{
	input.x--; input.y--;
	if (input.x >= 9 && input.x <= 99)
		size.x = input.x;
	else size.x = 9;
	if (input.y >= 9 && input.y <= 99)
		size.y = input.y;
	else size.y = 9;
}

void level::GenAplle()
{
	unsigned x{size.x+1}, y{size.y+1};
	unsigned a{ 0 }, b{ 1000 };
	std::uniform_int_distribution<unsigned> x_range(0,size.x);
	std::uniform_int_distribution<unsigned> y_range(0,size.y);
	while (IsCollision(LocApple = sf::Vector2u(x, y))) {
		rd.seed(time(0) + a); a++;
		x = x_range(rd);
		rd.seed(time(0) + b); b++;
		y = y_range(rd);
	}
	std::cout << "Apple " << LocApple.x << "||" << LocApple.y << std::endl;
}

void level::SetCollision(sf::Vector2u col)
{
	collision[col.x][col.y] = true;
}

void level::ClearCollision(sf::Vector2u col)
{
	collision[col.x][col.y] = false;
}

sf::Vector2u level::GetSize()
{
	return size;
}

sf::Vector2u level::GetLocApple()
{
	return LocApple;
}

sf::Vector2u level::GetCenter()
{
	return sf::Vector2u(size.x/2,size.y/2);
}

bool level::IsAplle(sf::Vector2u target)
{
	if (target == LocApple)
		return true;
	else return false;
}

bool level::IsCollision(sf::Vector2u target)
{
	if (target.x <= size.x && target.y <= size.y)
		return collision[target.x][target.y];
	else return true;
}


