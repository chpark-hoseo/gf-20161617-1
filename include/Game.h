#ifndef __GAME_H__
#define __GAME_H__

#include "main.h"

class Game {
public:
    Game() {}
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

    void MoveSide();

private:
    bool moveRight = true;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    SDL_Texture* m_pTexture;

    // 원본 사각형
    SDL_Rect m_sourceRectangle;

    // 대상 사각형
    SDL_Rect m_destinationRectangle;
};

#endif
