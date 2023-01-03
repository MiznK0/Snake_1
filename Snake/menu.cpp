#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "g_screen.h"
#include "menu.h"


menu::menu(Controller* a, sf::RenderWindow* b) : screen(a, b),
header("Header",font,b->getSize().x*0.11),
headerBox(sf::Vector2f(b->getSize().x, b->getSize().x*0.14))
{
	int Wind_x = viewport->getSize().x;
	int Wind_y = viewport->getSize().y;
	HeaderToCenter();
	headerBox.setPosition(0, Wind_y * 0.17);
	headerBox.setFillColor(color);
	int i;
	for (i = 0; i < 4; i++) {
		list[i].setCharacterSize(Wind_y * 0.1);
		list[i].setPosition(sf::Vector2f(Wind_x * 0.3, Wind_y * (0.4 + (i * 0.1))));
	}

	selector.setSize(sf::Vector2f(Wind_x * 0.7, Wind_y * 0.11));
	selector.setPosition(list[0].getPosition());
	selector.setFillColor(color);
	std::cout << "MenuScreen consctract" << std::endl;
}

menu::menu()
{
	
}

screen* menu::tik()
{
	viewport->draw(headerBox);
	viewport->draw(header);
	if (ctrl->Up() && NumSelec > 0) NumSelec--;
	if (ctrl->Down() && NumSelec < (MaxNumSelec-1)) NumSelec++; 
	selector.setPosition(list[NumSelec].getPosition());
	viewport->draw(selector);
	int i;
	for (i = 0; i < MaxNumSelec; i++) viewport->draw(list[i]);

	return this;
}

menu::~menu()
{
	std::cout << "Destroy MenuScreen" << std::endl;
}

void menu::HeaderToCenter()
{
	header.setPosition(((viewport->getSize().x -
		header.getString().getSize() * header.getCharacterSize()) / 2),
		viewport->getSize().x * 0.15);
}
