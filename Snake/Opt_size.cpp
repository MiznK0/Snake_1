#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h" 
#include "pause.h"
#include "mainMenu.h"
#include "options.h"
#include "Opt_size.h"


Opt_size::Opt_size(Controller* a, sf::RenderWindow* b) : menu(a, b)
{
	header.setString("SIZE");
	HeaderToCenter();
	list[0].setString("SMALL");
	list[1].setString("MIDDLE");
	list[2].setString("LARGE");
	list[3].setString("BACK");
	MaxNumSelec = 4;
}

	screen* Opt_size::tik()
{
		menu::tik();
		if (ctrl->Esc()) return new mainMenu(ctrl, viewport);
		if (ctrl->Enter()) {
			switch (NumSelec)
			{
			case (0):x = 20; y = 15; return new options(ctrl, viewport);
				break;
			case(1):x = 25; y = 20; return new options(ctrl, viewport);
				break;
			case(2):x = 30; y = 25; return new options(ctrl, viewport);
				break;
			case(3): return new options(ctrl, viewport);
				break;
			default:
				std::cout << "Switch op_size is trable" << std::endl;
				break;
			}
		}
		return this;
}
