#ifndef PRENDERER_H
#define PRENDERER_H

#include <SDL2/SDL.h>
#include "pMovers.h"
#include "pPlayer.h"
#include "pBall.h"

class pRenderer {
    public:
        pRenderer(const std::size_t winWidth, const std::size_t winHeight,
                 const std::size_t playerHeight, const std::size_t lineThickness);
        ~pRenderer();

    void Render(const pPlayer player1, const pPlayer player2, const pBall ball);
    void UpdateWindowTitle(const int player1score, const int player2score, const int remainder);
    bool wasInit();

    private:
        SDL_Window *_sdlWindow;
        SDL_Renderer *_sdlRenderer;

        const int _winWidth;
        const int _winHeight;
        const std::size_t _playerHeight;
        const std::size_t _lineThickness;
        bool _sdlInit;        
};

#endif