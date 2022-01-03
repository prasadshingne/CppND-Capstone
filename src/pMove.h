#ifndef PMOVE_H
#define PMOVE_H

#include <SDL2/SDL.h>
#include "pPlayer.h";

class pMove{
    private:
        bool _stopSim = false;
    
    public:
        void act(pPlayer &Player, SDL_Scancode key_up, SDL_Scancode key_down);
        bool getStopsim();
};

#endif