#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <math.h>

enum class direction { UP, RIGHT, DOWN, LEFT, NOTHING };
enum class speed { SLOW, MEDIUM, FAST };

//extern int unit_size;
extern int x;
extern int y;
extern sf::Font font;
extern int ofset;
extern speed sp;
extern sf::Color color;

int floatToInt(float);