#include "SDL.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* g_window = nullptr; 
SDL_Renderer* g_renderer = nullptr;

struct Player {
  SDL_Rect pos;
  int score;
  const int speed = 10;
};

struct Ball {
  SDL_Rect pos;
  float vx;
  float vy;
  float speed;
};


bool init() {
  if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    std::cout << "SDL could not start: " << SDL_GetError() << std::endl;
    return false;
  } 

  g_window = SDL_CreateWindow("pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if ( g_window == NULL ) {
    std::cout << "Could not create window: " << SDL_GetError();
    return false;
  }

  g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

  if ( g_renderer == NULL ) {
    std::cout << "Could not create renderer: " << SDL_GetError();
    return false;
  }

  return true;
}


void move(Player &p, SDL_Scancode key_up, SDL_Scancode key_down) {
  const Uint8* keystates = SDL_GetKeyboardState(NULL);

  if ( keystates[key_up] && p.pos.y != 0 ) {
    p.pos.y -= p.speed;

  } else if ( keystates[key_down] && p.pos.y != SCREEN_HEIGHT - p.pos.h ) {
    p.pos.y += p.speed;
  }
}

void draw_and_color(SDL_Rect &p1, SDL_Rect &p2, SDL_Rect &b) {
  SDL_RenderFillRect(g_renderer, &p1);
  SDL_RenderDrawRect(g_renderer, &p1);
  SDL_RenderFillRect(g_renderer, &p2);
  SDL_RenderDrawRect(g_renderer, &p2);
  SDL_RenderFillRect(g_renderer, &b);
  SDL_RenderDrawRect(g_renderer, &b);
}

void ball_movement(Ball &ball, Player p1, Player p2) {
  if ( ball.pos.y <= 0 || ball.pos.y >= SCREEN_HEIGHT - ball.pos.w ) {
    ball.vy *= -1;
  }

  if ( SDL_HasIntersection(&ball.pos, &p2.pos) || SDL_HasIntersection(&ball.pos, &p1.pos) ) {
    ball.vx *= -ball.speed;
  }
  

  ball.pos.x += ball.vx;
  ball.pos.y += ball.vy;
  
  SDL_Delay(20);
}

void begin(Player &p1, Player &p2, Ball &b) {
  //Player initial pos
  p1.pos.h = p2.pos.h = 60;
  p1.pos.w = p2.pos.w = 10;
  p1.pos.y = p2.pos.y = SCREEN_HEIGHT / 2 - p1.pos.h/2;
  
  p1.pos.x = 15;
  p2.pos.x = SCREEN_WIDTH-25;
  
  //Ball initial pos
  b.pos.x = SCREEN_WIDTH / 2;
  b.pos.y = SCREEN_HEIGHT / 2;
  b.pos.w = b.pos.h = 10;
  b.speed = 1.0f;
  
  //Random starting direction
  std::srand(time(NULL));
  if ( std::rand() % 2 ) {
    b.vx = -5;
  } else {
    b.vx = 5;
  }
  b.vy = -3;
  
  SDL_Delay(500);
}

int main() {
  if ( init() ) { 
    bool quit = false;
    SDL_Event e;
    
    Player p1;
    Player p2;
    Ball b;
    
    p1.score = p2.score = 0;

    begin(p1, p2, b);
    
    std::cout << "P1: " << p1.score << std::endl;
    std::cout << "P2: " << p2.score << std::endl;
    
    while ( !quit ) {
      while ( SDL_PollEvent(&e) ) {
        if ( e.type == SDL_QUIT ) {
          quit = true;
        }
      }

      move(p1, SDL_SCANCODE_W, SDL_SCANCODE_S);
      move(p2, SDL_SCANCODE_UP ,SDL_SCANCODE_DOWN);
      
      SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
      SDL_RenderClear(g_renderer); 
      SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);

      ball_movement(b, p1, p2);
      draw_and_color(p1.pos, p2.pos, b.pos);
      SDL_RenderPresent(g_renderer);
      
      if ( b.pos.x <= 0 ) {
        p2.score += 1;
        begin(p1, p2, b);
        std::cout << "P1: " << p1.score << std::endl;
        std::cout << "P2: " << p2.score << std::endl;

      } else if ( b.pos.x >= SCREEN_WIDTH - b.pos.w ) {
        p1.score += 1;
        begin(p1, p2, b);
        std::cout << "P1: " << p1.score << std::endl;
        std::cout << "P2: " << p2.score << std::endl;
      }
    }
  }

  SDL_Quit();
  return 0;
}