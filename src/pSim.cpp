#include <iostream>
#include <vector>

#include "pSim.h"

pSim::pSim(size_t winWidth, size_t winHeight, size_t playerHeight, 
    size_t lineThickness, size_t simRuntime, 
    float ballXVel, float ballYVel) : 
    _winWidth(winWidth), _winHeight(winHeight), 
    _playerHeight(playerHeight), _lineThickness(lineThickness),
    _simRuntime(simRuntime){
        size_t Ycenter = static_cast<int> (winHeight/2);
        size_t playerY = static_cast<int> (Ycenter-playerHeight/2);

        // Player 1 on the left (blue)
        _player1 = pPlayer(lineThickness+distPlayerGoal, playerY,
        lineThickness,playerHeight,0,0,255,255,0);

        // Player 2 on the right (red)
        _player2 = pPlayer(winWidth-2*lineThickness-distPlayerGoal, playerY,
        lineThickness,playerHeight,170,0,170,255,0);

        // Ball initialized in the center with gray color with initial velocity
        _ball = pBall(static_cast<int>(winWidth/2 - lineThickness/2),
                      static_cast<int>(Ycenter-lineThickness/2),
                      lineThickness, lineThickness, 170, 170, 170, 255, 
                      ballXVel, ballYVel);

        cout << "Game initialized." << endl;

}

pSim::~pSim(){
    cout << "Game destroyed." << endl;
}        

void pSim::run(pRenderer &renderer, pMove &Move_){
    bool simStop = false;
    Uint32 ticksCount = SDL_GetTicks();
    Uint32 gameEnd = ticksCount + _simRuntime * 1000;

    cout << "Game started." << endl;

    Uint32 frameStart, frameDur;
    int remainder = _simRuntime;

    renderer.UpdateWindowTitle(0, 0, remainder);
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), gameEnd) && !simStop){
        frameStart = SDL_GetTicks();
        _goal = false;

        Move_.act(_player1, SDL_SCANCODE_W, SDL_SCANCODE_S);
        Move_.act(_player2, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

        simStop = Move_.getStopsim();

        if(simStop){
            cout << "Game stopped by players." << endl;
        }

        updateSim();
        renderer.Render(_player1, _player2, _ball);
        frameDur = SDL_GetTicks() - frameStart;
        if(frameDur < _millisecPerFrame){
            SDL_Delay(_millisecPerFrame - frameDur);
        }
        // delay if a player scores
        if(_goal){
            SDL_Delay(500);
        }
        remainder = static_cast<int>((gameEnd-frameStart)/1000);
        renderer.UpdateWindowTitle(_scorePlayer1, _scorePlayer2, remainder);
    }

    SDL_Delay(2000);
    cout << "Game ended." << endl;
}

void pSim::updateSim(){
    // update player 1 position
    movePlayer1();
    // update player 2 position
    movePlayer2();
    // update ball position
    _ball.setCoordinates(_ball.getX() + _ball.getXvelocity() * _millisecPerFrame/1000,
                         _ball.getY() + _ball.getYvelocity() * _millisecPerFrame/1000);
    
    int xVelocity = _ball.getXvelocity();
    int yVelocity = _ball.getYvelocity();

    // check if player 1 or player 2 hit the ball
    // reverse and slightly increase x velocity
    if(player1Bounce() || player2Bounce()){
        xVelocity = -1.05f * _ball.getXvelocity();
    } else if(isPlayer1Goal() || isPlayer2Goal()){
        // decrease ball position and velocity
        _ball.setCoordinates(static_cast<int>(_winWidth/2 - _ball.getWidth()/2), 
                             static_cast<int>(_winWidth/2 - _ball.getHeight()/2));
        xVelocity = -0.9f * _ball.getXvelocity();
        yVelocity = -0.9f * _ball.getYvelocity();
    } else if(sideWallBounce()){
        xVelocity = -1.02 * _ball.getXvelocity();
        yVelocity = 1.02 * _ball.getYvelocity();
    } else if(otherWallBounce()){
        xVelocity = 1.02 * _ball.getXvelocity();
        yVelocity = -1.02 * _ball.getYvelocity();
    }

    // limit ball velocity so there is time for the players to react
    if(abs(_ball.getXvelocity()) > _winWidth){
        xVelocity = 0.9 * _ball.getXvelocity();
    }
    if(abs(_ball.getYvelocity()) > _winHeight){
        yVelocity = 0.9 * _ball.getYvelocity();
    }
    _ball.setVelocity(xVelocity, yVelocity);
}

// move player 1 from W/S
void pSim::movePlayer1(){
    if(_player1.getDirection() != 0){
        // calculate player's new position
        int player1Y = _player1.getY() + 
        _player1.getDirection() * static_cast<int>(_lineThickness/4)*2;

        // ensure player 1 stays on screen
        if(player1Y >= _lineThickness && 
        player1Y <= _winHeight -_lineThickness - _player1.getHeight()){
            _player1.setCoordinates(_player1.getX(), player1Y);
        }
        _player1.resetDirection();
    }
}

// move player 2 from UP/DOWN
void pSim::movePlayer2(){
    if(_player2.getDirection() != 0){
        // calculate player's new position
        int player2Y = _player2.getY() + 
        _player2.getDirection() * static_cast<int>(_lineThickness/4)*2;

        // ensure player 2 stays on screen
        if(player2Y >= _lineThickness && 
        player2Y <= _winHeight -_lineThickness - _player2.getHeight()){
            _player2.setCoordinates(_player2.getX(), player2Y);
        }
        _player2.resetDirection();
    }
}

bool pSim::player1Bounce(){
    if( (_ball.getX() - _player1.getX() - _player1.getWidth() <=0) &&
        (_ball.getY() + _ball.getHeight() >= _player1.getY()) &&
        (_ball.getY() <= _player1.getY() + _player1.getHeight()) &&
        (_ball.getXvelocity() < 0)){
        
        return true;

    }

    return false;
}

bool pSim::player2Bounce(){
    if( (_player2.getX() -_ball.getX() - _ball.getWidth() <= 0) &&
        (_ball.getY() + _ball.getHeight() >= _player2.getY()) &&
        (_ball.getY() <= _player2.getY() + _player2.getHeight()) &&
        (_ball.getXvelocity() > 0)){
        
        return true;

    }

    return false;
}

// calculate if player 1 scored a goal and update score
bool pSim::isPlayer1Goal(){
    if(_ball.getX() + _ball.getWidth() >= _winWidth - _lineThickness && 
      (_ball.getY() >=200) && (_ball.getY() + _ball.getHeight() <= 540) && 
      _ball.getXvelocity() > 0 )
  {
    player1Scores();
    _goal = true;
    return true;
  }
  return false;
}

// calculate if player 2 scored a goal and update score
bool pSim::isPlayer2Goal(){
    if(_ball.getX() <= _lineThickness && (_ball.getY() >=200) && 
      (_ball.getY() + _ball.getHeight() <= 540) && _ball.getXvelocity() < 0)
  {
    player2Scores();
    _goal = true;
    return true;
  }
  return false;
}

bool pSim::sideWallBounce()
{
  if((_ball.getX() <= _lineThickness && _ball.getXvelocity() < 0) ||
    (_ball.getX() + _ball.getWidth() >= _winWidth - _lineThickness && 
    _ball.getXvelocity() > 0)){
    return true;
  }
  return false;
}

bool pSim::otherWallBounce()
{
  if((_ball.getY() <= _lineThickness && _ball.getYvelocity() < 0) ||
    ((_ball.getY() + _ball.getHeight() >= _winHeight - _lineThickness) &&
    _ball.getYvelocity() > 0))
  {
    return true;
  }
  return false;
}

void pSim::player1Scores(){
    _scorePlayer1++;
}

void pSim::player2Scores(){
    _scorePlayer2++;
}

int pSim::getScorePlayer1(){
    return _scorePlayer1;
}

int pSim::getScorePlayer2(){
    return _scorePlayer2;
}