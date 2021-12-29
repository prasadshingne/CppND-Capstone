#ifndef PMOVERS_H
#define PMOVERS_H

#include <iostream>


class pMovers{
    public:
     pMovers();
     ~pMovers();

     pMovers(int x, int y, int width, int height, int red, int grn, int blu, int a);

     int getX() const;
     int getY() const;
     int getWidth()const;
     int getHeight() const;
     int getRed() const;
     int getGrn() const;
     int getBlu() const;
     int getA() const;

     void setCoordinates(const int x, const int y);
     void setSize(const int width, const int height);
     void setColor(const int red, const int grn, const int blu, const int a);
     
     void printCoordinates() const;
     void printSize() const;
     void printColor() const;

    protected:
     int _x, _y; // coordinates
     int _width, _height; // size
     int _red, _grn, _blu, _a; // color 

};

#endif