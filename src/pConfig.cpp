#include "pConfig.h"

pConfig::pConfig(const string path){
    string winWidth = "window width=";
    string winHeight = "window height=";
    string lineThickness = "line thickness=";
    string playerHeight = "player height=";
    string simRuntime = "simulation runtime=";
    string ballXVel = "ball X velocity=";
    string ballYVel = "ball Y velocity=";

    ifstream stream(path);
    if(!stream){
        throw runtime_error("Configuration file not found.");
    }

    string line;
    while(getline(stream, line))
    {
        if(line.compare(0, winWidth.size(), winWidth)==0){
            _winWidth = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, winHeight.size(), winHeight)==0){
            _winHeight = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, lineThickness.size(),lineThickness) == 0){
            _lineThickness = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, playerHeight.size(),playerHeight) == 0){
            _playerHeight = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, simRuntime.size(),simRuntime) == 0){
            _simRuntime = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, ballXVel.size(),ballXVel) == 0){
            _ballXVel = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
        if(line.compare(0, ballYVel.size(),ballYVel) == 0){
            _ballYVel = static_cast<size_t>(stoi(line.substr(line.find("=")+1)));
            continue;
        }
    }
}

size_t pConfig::getWinWidth() const{
    return _winWidth;
}
size_t pConfig::getWinHeight() const{
    return _winHeight;
}
size_t pConfig::getLineThickness() const{
    return _lineThickness;
}
size_t pConfig::getPlayerHeight() const{
    return _playerHeight;
}
size_t pConfig::getSimRuntime() const{
    return _simRuntime;
}
float pConfig::getBallXVel() const{
    return _ballXVel;
}
float pConfig::getBallYVel() const{
    return _ballYVel;
}