#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h"
#include "mainMenu.h"
#include "GameOver.h"

GameOver::GameOver(Controller*a, sf::RenderWindow*b):menu(a,b)
{
	header.setString("GAMEOVER");
	HeaderToCenter();
	list[0].setString("RESTART");
	list[1].setString("BACK");
	MaxNumSelec = 2;

}

screen* GameOver::tik()
{
	menu::tik();
	if (ctrl->Esc()) return new mainMenu(ctrl, viewport);
	if (ctrl->Enter()) {
		switch (NumSelec)
		{
		case(0): return new g_screen(ctrl, viewport);
			break;
		case(1): return new mainMenu(ctrl, viewport);
		default:
			std::cout << "Switch gameOver is trable" << std::endl;
			break;
		}
	}
	return this;
}
