#ifndef PBALL_H
#define PBALL_H

#include "pMovers.h"

class pBall : public pMovers
{
    private:
        float _xVelocity, _yVelocity; // velocity of ball in x and y directions

    public:
        pBall();
        ~pBall();
        pBall(int x, int y, int width, int height, int red, int grn, int blu, 
        int a, int xVelocity, int yVelocity);
        
        float getXvelocity() const;
        float getYvelocity() const;

        void setVelocity(const float xVelocity, const float yVelocity);
        void printVelocity() const;
};

#endif

