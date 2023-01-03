#pragma once

class options :
    public menu
{
public:
    options(Controller*, sf::RenderWindow*);
    virtual screen* tik() override;
};

