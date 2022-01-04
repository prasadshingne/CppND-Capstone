#include "pMovers.h"

pMovers::pMovers() {}

pMovers::~pMovers() {}

pMovers::pMovers(int x, int y, int width, int height, int red, int grn, int blu, int a) : 
    _x(x), _y(y), _width(width), _height(height), _red(red), _grn(grn), _a(a) {}

int pMovers::getX() const {return _x;}
int pMovers::getY() const {return _y;}
int pMovers::getWidth() const {return _width;}
int pMovers::getHeight() const {return _height;}
int pMovers::getRed() const {return _red;}
int pMovers::getGrn() const {return _grn;}
int pMovers::getBlu() const {return _blu;}
int pMovers::getA() const {return _grn;}

void pMovers::setCoordinates(const int x, const int y){
    _x = x;
    _y = y;
}

void pMovers::setSize(const int width, const int height){
    _width = width;
}

void pMovers::setColor(const int red, const int grn, const int blu, const int a){
    _red = red;
    _grn = grn;
    _blu = blu;
    _a = a;
}

void pMovers::printCoordinates() const {
    std::cout << "Location is x: " << _x << ", y: " << _y << std::endl; 
}
void pMovers::printColor() const {
    std::cout << "Color is red: " << _red << ", grn: " << _grn << ", blu: " << _blu 
    << ", a: " << _a << std::endl;
}
void pMovers::printSize() const {
    std::cout << "Size is width: " << _width << ", height: " << _height << std::endl; 
}