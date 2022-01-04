#include <iostream>
#include "pConfig.h"
#include "pSim.h"
#include "pRenderer.h"

using namespace std;

int main(){
    pConfig config("sim_config.txt");
    pRenderer renderer(config.getWinWidth(),config.getWinHeight(),
                       config.getPlayerHeight(), config.getLineThickness());
    
    if(!renderer.wasInit()){
        cerr << "Renderer not initialized." << endl;
        return 1;
    }

    pMove mov;
    pSim sim(config.getWinWidth(), config.getWinHeight(), config.getPlayerHeight(),
             config.getLineThickness(), config.getSimRuntime(), 
             config.getBallXVel(), config.getBallYVel());
    
    sim.run(renderer, mov);

    cout << "Final score : Player1 = " << sim.getScorePlayer1() << 
            "Player 2 = " << sim.getScorePlayer2() << endl;
    
    return 0;
}