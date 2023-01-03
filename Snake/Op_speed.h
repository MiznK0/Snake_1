#pragma once

class Op_speed :
    public menu
{
    public:

    Op_speed(Controller*, sf::RenderWindow*);
    virtual screen* tik() override;
};

