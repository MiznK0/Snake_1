#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h" 
#include "pause.h"
#include "mainMenu.h"
#include "options.h"
#include "Op_speed.h"


Op_speed::Op_speed(Controller* a, sf::RenderWindow* b) :menu(a, b) {
	header.setString("SPEED");
	HeaderToCenter();
	list[0].setString("SLOW");
	list[1].setString("MIDDLE");
	list[2].setString("FAST");
	list[3].setString("BACK");
	MaxNumSelec = 4;
}


screen* Op_speed::tik()
{
	menu::tik();
	if (ctrl->Esc()) return new options(ctrl, viewport);
	if (ctrl->Enter()) {
		switch (NumSelec)
		{
		case(0): sp = speed::SLOW; return new options(ctrl, viewport);
			break;
		case(1): sp = speed::MEDIUM; return new options(ctrl, viewport);
			break;
		case(2): sp = speed::FAST; return new options(ctrl, viewport);
			break;
		case(3): return new options(ctrl, viewport);
			break;

		default:
			std::cout << "Switch op_speed is trable" << std::endl;
			break;
		}
	}
	return this;
}
