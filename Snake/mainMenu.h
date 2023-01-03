#pragma once

class mainMenu :
    public menu
{
public:
    mainMenu(Controller*, sf::RenderWindow*);
    virtual screen* tik() override;
};

