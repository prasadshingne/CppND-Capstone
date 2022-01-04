#include "pBall.h"

using namespace std;

pBall::pBall() {}
pBall::~pBall() {}

pBall::pBall(int x, int y, int width, int height, 
             int red, int grn, int blu, int a, 
             int xVelocity, int yVelocity) : 
     pMovers(x, y, width, height, red, grn, blu, a), 
     _xVelocity(xVelocity), _yVelocity(yVelocity) {}

float pBall::getXvelocity() const {
    return _xVelocity;
}

float pBall::getYvelocity() const {
    return _yVelocity;
}

void pBall::setVelocity(const float xVelocity, const float yVelocity){
    _xVelocity = xVelocity;
    _yVelocity = yVelocity;
}

void pBall::printVelocity() const {
    cout << "Ball Velocity :" << _xVelocity << ", " << _yVelocity << endl;
}