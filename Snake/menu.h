#pragma once

class menu :
    public screen
{public:
    menu(Controller* a, sf::RenderWindow* b);
    menu();
    virtual screen* tik() override;
    virtual ~menu();
    void HeaderToCenter();
    sf::Text header;
    sf::RectangleShape headerBox;
    sf::Text t1{ "",font };
    sf::Text list[4]{t1,t1,t1,t1};
    sf::RectangleShape selector;
    int MaxNumSelec{ 4};
    int NumSelec{ 0 };
    
private:
   
};

