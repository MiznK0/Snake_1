#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h" 
#include "pause.h"
#include "mainMenu.h"
#include "options.h"

mainMenu::mainMenu(Controller*a, sf::RenderWindow*b):menu(a,b)
{
	header.setString("SNAKE");
	HeaderToCenter();
	list[0].setString("PLAY");
	list[1].setString("OPTION");
	list[2].setString("EXIT");
	MaxNumSelec = 3;

	std::cout << "MainMenu is conctract" << std::endl;
}

screen* mainMenu::tik()
{
	menu::tik();

	if (ctrl->Enter()) {
		switch (NumSelec)
		{
		case(0):return new g_screen(ctrl, viewport);
			break;
		case(1):return new options(ctrl, viewport);
			break;
		case (2): closeWindow = true;
			break;
		default:
			std::cout << "Switch MainMenu is truble" << std::endl;
			break;
		}
	}
	return this;
}

