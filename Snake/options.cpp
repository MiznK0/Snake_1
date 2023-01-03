#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h" 
#include "pause.h"
#include "mainMenu.h"
#include "options.h"
#include "Opt_size.h"
#include "Op_speed.h"

options::options(Controller* a, sf::RenderWindow* b):menu(a,b)
{
	header.setString("OPTION");
	HeaderToCenter();
	list[0].setString("SIZE");
	list[1].setString("SPEED");
	list[2].setString("BACK");
	MaxNumSelec = 3;
}

screen* options::tik()
{
	menu::tik();
	if (ctrl->Esc()) return new mainMenu(ctrl, viewport);
	if (ctrl->Enter()) {
		switch (NumSelec)
		{
		case (0): return new Opt_size(ctrl, viewport);
			break;
		case (1): return new Op_speed(ctrl, viewport);
			break;
		case (2): return new mainMenu(ctrl, viewport);
			break;
		default:
			std::cout << "Switch options is trable" << std::endl;
			break;
		}
	}
	return this;
}
