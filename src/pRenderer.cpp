#include "pRenderer.h"

using namespace std;

pRenderer::pRenderer(const std::size_t winWidth, const std::size_t winHeight,
                     const std::size_t playerHeight, const std::size_t lineThickness) :
                    _winWidth(static_cast<int>(winWidth)),
                    _winHeight(static_cast<int>(winHeight)),
                    _playerHeight(static_cast<int>(playerHeight)),
                    _lineThickness(static_cast<int>(lineThickness)),
                    _sdlInit(true)
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0){
        cerr << "Unable to initialize SDL: " << SDL_GetError() << endl;
        _sdlInit = false;
    }

    _sdlWindow = SDL_CreateWindow("Udacity CppND Final Project : Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, 0);
    if (!_sdlWindow){
        cerr << "Unable to create window: " << SDL_GetError() << endl;
        _sdlInit = false;
    }

    _sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!_sdlRenderer){
        cerr << "Unable to create renderer: " << SDL_GetError() << endl;
        _sdlInit = false;
    }
}

pRenderer::~pRenderer(){
  SDL_DestroyWindow(_sdlWindow);
  SDL_Quit();
}

void pRenderer::Render(const pPlayer player1, const pPlayer player2, const pBall ball){
    // set background color to black
    SDL_SetRenderDrawColor(_sdlRenderer, 0, 0 ,0, 255);

    // clear back buffer
    SDL_RenderClear(_sdlRenderer);

    // Draw grey walls
    SDL_SetRenderDrawColor(_sdlRenderer, 170, 170, 170, 255);

    // Draw top wall
    SDL_Rect wall{0, 0, _winWidth, _lineThickness};
    SDL_RenderFillRect(_sdlRenderer, &wall);

    // Draw bottom wall
    wall.y = _winHeight - _lineThickness;
    SDL_RenderFillRect(_sdlRenderer, &wall);

    // Draw left goal
    wall.y = 0;
    wall.w = _lineThickness;
    wall.h = 200;
    SDL_RenderFillRect(_sdlRenderer, &wall);

    wall.y = 540;
    SDL_RenderFillRect(_sdlRenderer, &wall);

    // Draw right goal
    wall.x = _winWidth - _lineThickness;
    wall.y = 0;
    SDL_RenderFillRect(_sdlRenderer, &wall);

    wall.y = 540;
    SDL_RenderFillRect(_sdlRenderer, &wall);

    // Draw ball
    SDL_SetRenderDrawColor(_sdlRenderer, ball.getRed(), ball.getGrn(), ball.getBlu(), ball.getA());
    SDL_Rect b{
        static_cast<int>(ball.getX()),
        static_cast<int>(ball.getY()),
        ball.getWidth(),
        ball.getHeight()
    };
    SDL_RenderFillRect(_sdlRenderer, &b);

    // Draw player 1 rectangle
    SDL_SetRenderDrawColor(_sdlRenderer, player1.getRed(), player1.getGrn(), player1.getBlu(), player1.getA());
    SDL_Rect player1rect{
        static_cast<int>(player1.getX()),
        static_cast<int>(player1.getY()),
        player1.getWidth(),
        static_cast<int>(player1.getHeight())
    };
    SDL_RenderFillRect(_sdlRenderer, &player1rect);

    // Draw player 2 rectangle
    SDL_SetRenderDrawColor(_sdlRenderer, player2.getRed(), player2.getGrn(), player2.getBlu(), player2.getA());
    SDL_Rect player2rect{
        static_cast<int>(player2.getX()),
        static_cast<int>(player2.getY()),
        player2.getWidth(),
        static_cast<int>(player2.getHeight())
    };
    SDL_RenderFillRect(_sdlRenderer, &player2rect);

    // Swap front and back buffers
    SDL_RenderPresent(_sdlRenderer);
}

void pRenderer::UpdateWindowTitle(const int player1score, const int player2score, const int remainder){
    string title{"Player 1: " + to_string(player1score) + " Player 2: " + 
    to_string(player2score) + " Remaining : " + to_string(remainder)};
    SDL_SetWindowTitle(_sdlWindow, title.c_str());
}

bool pRenderer::wasInit(){
    return _sdlInit;
}