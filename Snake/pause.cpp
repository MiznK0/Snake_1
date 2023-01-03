#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h" 
#include "pause.h"
#include "mainMenu.h"
#include "options.h"



pause::pause(Controller* a, sf::RenderWindow* b, screen* g):menu(a,b)
{
	game = new g_screen(*reinterpret_cast<g_screen*>(g));
	header.setString("PAUSE");
	HeaderToCenter();
	list[0].setString("CONTINUE");
	list[1].setString("BACK");
	MaxNumSelec = 2;
	
	std::cout << "Pause is conctract" << std::endl;
}

pause::pause()
{
}

pause::~pause()
{
	std::cout << "Destroy PauseScreen" << std::endl;
}

screen* pause::tik()
{
	menu::tik();
	if (ctrl->Esc())return game;
	if (ctrl->Enter()) {
		switch (NumSelec)
		{
		case (0): return game;
			break;
		case(1): delete game; return new mainMenu(ctrl, viewport);
			break;
		default:
			std::cout << "switch Pause is trable" << std::endl;
			break;
		}
	}
	return this;
}
