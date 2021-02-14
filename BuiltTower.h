#ifndef BUILTTOWER_H_INCLUDED
#define BUILTTOWER_H_INCLUDED

#include "Tower.h"
#include <iostream>

class BuiltTower : public Tower
{
public:
    BuiltTower(int mouse_x = 0, int mouse_y = 0) : Tower(mouse_x, mouse_y)
    {
        type = BUILTTOWER;

        circle->r = 70;
        attack_frequency = 30;
        attack_velocity = 6;
        attack_harm_point = 15;
        std::cout << "???" << std::endl;
        img = al_load_bitmap("./Tower/BuiltTower.png");
        attack_img = al_load_bitmap("./Tower/BuiltTower_Beam.png");
    }

    int getWidth() override { return TowerWidth[BUILTTOWER]; }
    int getHeight() override { return TowerHeight[BUILTTOWER]; }
};

#endif // CANON_H_INCLUDED
