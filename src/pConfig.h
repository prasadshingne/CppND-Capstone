#ifndef PCONFIG_H
#define PCONFIG_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class pConfig{
    private:
        size_t _winWidth;
        size_t _winHeight;
        size_t _lineThickness;
        size_t _playerHeight;
        size_t _simRuntime;
        float _ballXVel;
        float _ballYVel;
    public:
        pConfig(const string path);

        size_t getWinWidth() const;
        size_t getWinHeight() const;
        size_t getLineThickness() const;
        size_t getPlayerHeight() const;
        size_t getSimRuntime() const;
        float getBallXVel() const;
        float getBallYVel() const;
};

#endif