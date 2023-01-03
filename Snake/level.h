#pragma once

class level
{
public:

	level();
	level(unsigned int, unsigned int);
	level(sf::Vector2u);
	void GenAplle();
	void SetCollision(sf::Vector2u);
	void ClearCollision(sf::Vector2u);
	sf::Vector2u GetSize();
	sf::Vector2u GetLocApple();
	sf::Vector2u GetCenter();
	bool IsAplle(sf::Vector2u);
	bool IsCollision(sf::Vector2u);

private:

	bool collision[100][100];
	sf::Vector2u size;
	sf::Vector2u LocApple;
	std::mt19937 rd;
};

