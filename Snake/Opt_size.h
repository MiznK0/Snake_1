#pragma once

class Opt_size :
    public menu
{
public:
    Opt_size(Controller*, sf::RenderWindow*);
    virtual screen* tik() override;
};
