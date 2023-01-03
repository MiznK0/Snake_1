#include "Header.h"
#include "Snake.h"

Snake::Snake()
{
}

Snake::Snake(level* Map)
{
	body.reserve(40);
	length = 4;
	Front = direction::UP;
	Back = direction::DOWN;
	map = Map;
	sf::Vector2u StartLoc = {Map->GetCenter()};
	body.push_back(sf::Vector2u(StartLoc.x, StartLoc.y + (length-1)));
	int i;
	for (i = 0; i < (length-1); i++) {
		FindPointer(Front);
		grow_move();
	}
}

sf::Vector2u Snake::FindPointer(direction Direct)
{
	if (Direct != Back)//������ �� ����� ���� ��������� �����, � ����
	{
		FrontUpdate(Direct);//��������������� ���������� � ����������� ������ ��������
		switch (Front) {
		case direction::UP:
			pointer = sf::Vector2u(body[0].x, body[0].y - 1); break;
		case direction::RIGHT:
			pointer = sf::Vector2u(body[0].x + 1, body[0].y); break;
		case direction::DOWN:
			pointer = sf::Vector2u(body[0].x, body[0].y + 1); break;
		case direction::LEFT:
			pointer = sf::Vector2u(body[0].x - 1, body[0].y); break;
		case  direction::NOTHING:
			pointer = body[0];//���� �� �����, � ��� ��������, �� ������ ����-�� ���������
			std::cout << "Error: Front is NOTHING!" << std::endl; break;
		default: std::cout << "Switch direction trable" << std::endl;
			pointer = body[0]; break;
		}
		return pointer;
	}
	else return FindPointer(Front);//���������� �������� � ��� �� �����������
}


void Snake::move()
{ 
	body.insert(body.begin(), pointer);
	map->SetCollision(pointer);
	map->ClearCollision(body.back());
	body.pop_back();
}

void Snake::grow_move()
{
	body.insert(body.begin(), pointer);
	map->SetCollision(pointer);
}

std::vector<sf::Vector2u> Snake::GetBody()
{
	return body;
}

void Snake::FrontUpdate(direction Direct)
{
	if (Direct != Front) //����� �� ������ �����������?
	{
		switch (Direct)
		{
		case direction::LEFT: Front = Direct; Back = direction::RIGHT;
			break;
		case direction::RIGHT: Front = Direct; Back = direction::LEFT;
			break;
		case direction::UP: Front = Direct; Back = direction::DOWN;
			break;
		case direction::DOWN: Front = Direct; Back = direction::UP;
			break;
		case direction::NOTHING:;// ������ ���������, �� ������ �����������
			break;
		default:
			std::cout << "Swith front update trable" << std::endl;
			break;
		}
	}
	else;// ������ ���������, �� ������ �����������
}

