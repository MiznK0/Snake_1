#include "Header.h"
#include "Controller.h"
#include "screen.h"
#include "menu.h"
#include "mainMenu.h"

sf::RenderWindow window(sf::VideoMode(900, 900), "Snake!", sf::Style::None);
screen* ptr_screen;
Controller controller;
void UpdateState(screen*);


int ofset = 50; int x = 20; int y = 15;
sf::Font font; speed sp = speed::MEDIUM;
sf::Color color = sf::Color(120, 100, 80);

int main()
{
	if (!font.loadFromFile("Arial.ttf")) 
		std::cout << "Font load fail" << std::endl;
	else std::cout << "Font load sucsess" << std::endl;
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60);
	ptr_screen = dynamic_cast<menu*>(new mainMenu(&controller, &window));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))//��������� ������ ��� ����
	//����� ����� �������� ������, �������� � ��������� �� ��(��� � �������)))))
	//� �������, ��� ����� ����� ��� ������� �������� �� ���� ����������, ��� ��������
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (ptr_screen->closeWindow) window.close();//���� �������� ������� �� ����
		window.clear(sf::Color(10, 10, 10, 255));
		controller.�heck();
		UpdateState(ptr_screen->tik());//������ ����� ���������
		window.display();
	}
	return 0;
}

void UpdateState(screen* input) {

	if (ptr_screen != input) {//����� ������ ��������� ������ ������ �� ����� ���������?
		delete ptr_screen;//��������� ������
		ptr_screen = input;//��������� ���������
	}
	else;//����� ������ ��������� ���������� ������ �� ���� ��? 
	//��������� ������ �� ���� ����������!
}

int floatToInt(float source) {
	int x = floor(source);
	if ((source - x) >= 0.5) return x++;
	else return x;
}