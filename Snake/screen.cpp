#include "Header.h"
#include "Controller.h"
#include "screen.h"

screen::screen(Controller* a, sf::RenderWindow* b)
{
	ctrl = a; viewport = b;
}

screen::screen()
{
	std::cout << "Error: Void screen!" << std::endl;
}

screen::~screen(){
	
}

screen* screen::tik()
{
	return nullptr;
}
