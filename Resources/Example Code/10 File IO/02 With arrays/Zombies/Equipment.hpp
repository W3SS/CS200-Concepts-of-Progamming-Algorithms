#ifndef _EQUIPMENT
#define _EQUIPMENT

struct Equipment
{
    int ammo;
    int food;
    int entertainment;

    void Init()
    {
        ammo = food = entertainment = 0;
    }
};

#endif
