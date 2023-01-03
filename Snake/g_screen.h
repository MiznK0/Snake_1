#pragma once
#include "level.h"
#include "Snake.h"

class g_screen :
    public screen
{
public:

    g_screen(Controller* a, sf::RenderWindow* b);
    g_screen(const g_screen&);
    g_screen();
    virtual screen* tik()  override;
    ~g_screen();
    level map;
   
private:
 
    void AddVeiwport();
    bool TikGate();
    int unit_size;
    sf::Vector2u pointer;
    unsigned int limit;
    unsigned int score{ 0 };
    Snake snake; 
    sf::RectangleShape block;
    sf::RectangleShape frame;
};

