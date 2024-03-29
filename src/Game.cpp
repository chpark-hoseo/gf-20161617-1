#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생설 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }


    //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
    SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");

    if (pTempSurface == nullptr)
    {

    }
    else
    {
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

        SDL_FreeSurface(pTempSurface);
    }
   
    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w,
    //    &m_sourceRectangle.h);

    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;

    //응용 1번
    //m_destinationRectangle.w = m_sourceRectangle.w = 50;
    //m_destinationRectangle.h = m_sourceRectangle.h = 50;
    //m_destinationRectangle.x = m_sourceRectangle.x = 0;
    //m_destinationRectangle.y = m_sourceRectangle.y = 0;
     
    //응용 2번
    //m_destinationRectangle.w = m_sourceRectangle.w = 50;
    //m_destinationRectangle.h = m_sourceRectangle.h = 50;
    //m_sourceRectangle.x = 0;
    //m_sourceRectangle.y = 0;
    //m_destinationRectangle.x = 50;
    //m_destinationRectangle.y = 50;

    //응용 3번
    //m_destinationRectangle.w = m_sourceRectangle.w = 50;
    //m_destinationRectangle.h = m_sourceRectangle.h = 50;
    //m_sourceRectangle.x = 50;
    //m_sourceRectangle.y = 50;
    //m_destinationRectangle.x = 50;
    //m_destinationRectangle.y = 50;

    //응용 4번
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;

    //m_destinationRectangle.w = m_sourceRectangle.w;
    //m_destinationRectangle.h = m_sourceRectangle.h;
    //m_destinationRectangle.x = m_sourceRectangle.x = 0;
    //m_destinationRectangle.y = m_sourceRectangle.y = 0;

    m_bRunning = true;
    return true;
}

void Game::MoveSide()
{
    if (m_destinationRectangle.x <= 0)
    {
        moveRight = true;
    }
    else if (m_destinationRectangle.x >= 520)
    {
        moveRight = false;
    }

    if (moveRight == true)
    {
        m_destinationRectangle.x += 1;
    }
    else
    {
        m_destinationRectangle.x -= 1;
    }
    SDL_Delay(10);
}

void Game::update()
{
    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}