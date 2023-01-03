#pragma once

class pause :
    public menu
{
public:
    pause(Controller*, sf::RenderWindow*, screen*);
    pause();
    ~pause();
    screen* game;
    virtual screen* tik();
};

