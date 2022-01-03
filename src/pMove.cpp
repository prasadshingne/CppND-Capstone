#include "pMove.h"

void pMove::act(pPlayer &Player, SDL_Scancode key_up, SDL_Scancode key_down){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
            _stopSim = true;
            break;
        }
    }

    // check if ESC key is pressed
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_ESCAPE]){
        _stopSim = true;
    }

    // Move player up or down based on key_up and key_down
    if(keystate[key_up]){
        Player.updateDirection(-1);
    }
    if(keystate[key_down]){
        Player.updateDirection(1);
    }

}

bool pMove::getStopsim(){
    return _stopSim;
}