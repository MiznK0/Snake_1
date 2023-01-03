#include "Header.h"
#include "Controller.h"

Controller::Controller() :
	last_dirct(direction::NOTHING),
	EscReleased(true)
{

}

direction Controller::lastDirct()
{
	return last_dirct;
}

void Controller::setLastDirct(direction source)
{
	last_dirct = source;
}

direction Controller::ñheck()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || 
		(sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) 
		return last_dirct = direction::LEFT;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) 
		return last_dirct = direction::RIGHT;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) 
		return last_dirct = direction::UP;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) 
		return last_dirct = direction::DOWN;
	else return direction::NOTHING;
}

bool Controller::Esc()
{
	switch (EscReleased)
	{
	case(true):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	{
		EscReleased = false;
		return true;
	}
		else return false;

	case(false):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			return false;
		else
		{
			EscReleased = true;
			return false;
		}
	default:
		std::cout << "Controller Esc switch trable" << std::endl;
		return false;
		break;
	}
}

bool Controller::Enter()
{
	switch (EnterReleased)
	{
	case(true):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
		{
			EnterReleased = false;
			return true;
		}
		else return false;

	case(false):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
			return false;
		else
		{
			EnterReleased = true;
			return false;
		}
	default:
		std::cout << "Contreller Esc switch trable" << std::endl;
		return false;
		break;
	}
}

bool Controller::Up()
{
	switch (UpReleased)
	{
	case(true):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		{
			UpReleased = false;
			return true;
		}
		else return false;

	case(false):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			return false;
		else
		{
			UpReleased = true;
			return false;
		}
	default:
		std::cout << "Contreller Up switch trable" << std::endl;
		return false;
		break;
	}
}

bool Controller::Down()
{

	switch (DownReleased)
	{
	case(true):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		{
			DownReleased = false;
			return true;
		}
		else return false;

	case(false):
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			return false;
		else
		{
			DownReleased = true;
			return false;
		}
	default:
		std::cout << "Contreller Down switch trable" << std::endl;
		return false;
		break;
	}
}


