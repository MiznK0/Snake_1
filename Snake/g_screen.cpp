#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "menu.h"
#include "pause.h"
#include "GameOver.h"
#include "g_screen.h"


g_screen::g_screen(Controller* a, sf::RenderWindow* b) : screen(a, b),
map(level(x, y)), snake(Snake(&map))

{
	unit_size = floatToInt((viewport->getSize().x - (ofset * 2)) / x);
	frame.setSize(sf::Vector2f(unit_size * x, unit_size * y));
	frame.setPosition(ofset, ofset);
	frame.setFillColor(color);
	frame.setOutlineThickness(5); frame.setOutlineColor(sf::Color::White);
	block.setSize(sf::Vector2f(unit_size * 0.9, unit_size * 0.9));
	ctrl->setLastDirct(ctrl->ñheck());
	
	switch (sp)
	{
	case speed::SLOW:
		limit = 8;
		break;
	case speed::MEDIUM:
		limit = 6;
		break;
	case speed::FAST:
		limit = 4;
		break;
	default: limit = 6;
		break;
	}
	std::cout << "Game is consctract" << std::endl;
}

g_screen::g_screen(const g_screen& source):screen(source.ctrl, source.viewport)
{
	unit_size = source.unit_size;
	block = source.block;
	frame = source.frame;
	pointer = source.pointer;
	limit = source.limit;
	score = source.score;
	map = source.map;
	snake = source.snake;
	snake.map = &map;
}

g_screen::g_screen():screen()
{
}

screen* g_screen::tik()
{
	if (ctrl->Esc()) return new pause (ctrl, viewport, this);
	if (TikGate()) {
		pointer = snake.FindPointer(ctrl->lastDirct());
		if (map.IsCollision(pointer)) return new GameOver(ctrl, viewport);
		else if (map.IsAplle(pointer)) {
			snake.grow_move();
			map.GenAplle();
		}
		else snake.move();
		AddVeiwport(); return this;
	}
	else AddVeiwport(); return this;
}

g_screen::~g_screen()
{
	std::cout << "Destroy GameScreen" << std::endl;
}


void g_screen::AddVeiwport()
{
	std::vector<sf::Vector2u> loc = snake.GetBody();
	loc.push_back(map.GetLocApple());
	viewport->draw(frame);
	block.setPosition(sf::Vector2f((loc[0].x * unit_size) + ofset, (loc[0].y * unit_size) + ofset));
	block.setFillColor(sf::Color(200,200,200));
	viewport->draw(block);
	block.setFillColor(sf::Color::White);
	int i;
	for (i = 1; i < loc.size(); i++) {
		block.setPosition(sf::Vector2f((loc[i].x * unit_size)+ofset, (loc[i].y * unit_size)+ofset));
		viewport->draw(block);
	}
}

bool g_screen::TikGate() {

	
	if (score > limit)
	{
		score = 0; return true;
	}
	else { score++; return false; }
}