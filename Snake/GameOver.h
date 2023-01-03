#pragma once

class GameOver :
    public menu
{
public:
    GameOver(Controller*, sf::RenderWindow*);
    virtual screen* tik() override;
};

