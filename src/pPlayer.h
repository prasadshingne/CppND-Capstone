#ifndef PPLAYER_H
#define PPLAYER_H

#include "pMovers.h"

class pPlayer : public pMovers {
    public:
     pPlayer();
     ~pPlayer();
     pPlayer(int x, int y, int width, int height, int red, int grn, int blu, int a, int d);

     int getDirection() const;
     void resetDirection();
     void updateDirection(const int d);

    private:
     int _dir; // direction - up or down 
};


#endif