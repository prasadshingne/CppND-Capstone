#ifndef PSIM_H
#define PSIM_H

#include <SDL2/SDL.h>
#include "pMovers.h"
#include "pPlayer.h"
#include "pBall.h"
#include "pRenderer.h"
#include "pMove.h"

using namespace std;

// define distance between the player and goal
const int distPlayerGoal = 10;

// the Sim Class
class pSim
{
    private:
        pPlayer _player1;
        pPlayer _player2;
        pBall _ball;

        size_t _winWidth, _winHeight, _lineThickness, _playerHeight;
        size_t _simRuntime;
        
        int _millisecPerFrame = 20;
        int _scorePlayer1 = 0;
        int _scorePlayer2 = 0;
        int _goal = false;

        void updateSim();
        void movePlayer1();
        void movePlayer2();
        void player1Scores();
        void player2Scores();

        bool player1Bounce();
        bool player2Bounce();
        bool sideWallBounce();
        bool otherWallBounce();

        bool isPlayer1Goal();
        bool isPlayer2Goal();

    public:
        pSim(size_t winWidth, size_t winHeight, size_t playerHeight, 
             size_t lineThickness, size_t simRuntime, 
             float ballXVel, float ballYVel);
        ~pSim();

        int getScorePlayer1();
        int getScorePlayer2();

        void run(pRenderer &renderer, pMove &Move_);
};
#endif