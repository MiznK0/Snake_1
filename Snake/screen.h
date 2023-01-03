#pragma once

class screen{
public:
	screen(Controller*, sf::RenderWindow*);
	screen();
	Controller* ctrl{ 0 };
	sf::RenderWindow* viewport{ 0 };
	virtual screen* tik();
	virtual ~screen();
	bool closeWindow{ false };
};

