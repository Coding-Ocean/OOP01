#include "Game.h"
#include "framework.h"
#include "graphic.h"
#include "input.h"
#include "window.h"

bool Game::Initialize()
{
    window(1024, 768);

    mBallH = 20;
    mBallW = 20;
    mBallPx = 700;
    mBallPy = 400;
    mBallVx = -300;
    mBallVy = -300;
    
    mPaddleH = 120;
    mPaddleW = 20;
    mPaddlePx = 100;
    mPaddlePy = height / 2 - mPaddleH / 2;
    
    initDeltaTime();
    return true;
}

void Game::RunLoop()
{
    while (notQuit)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
}

void Game::ProcessInput()
{
    mPaddleVy = 0;
    if (isPress(KEY_W))mPaddleVy = -300;
    if (isPress(KEY_S))mPaddleVy = 300;
}

void Game::UpdateGame()
{
    setDeltaTime();
    //mBall‚Ì“®‚«
    mBallPx += mBallVx * delta;
    mBallPy += mBallVy * delta;
    if (mBallPy < 0 && mBallVy < 0)
    {
        mBallVy *= -1;
    }
    if (mBallPy > height - mBallH  && mBallVy > 0)
    {
        mBallVy *= -1;
    }
    if (mBallPx > width - mBallW && mBallVx > 0)
    {
        mBallVx *= -1;
    }
    if (mBallPx < -200)
    {
        closeWindow();
    }
    //mPaddle‚Ì“®‚«
    if (mPaddleVy != 0)
    {
        mPaddlePy += mPaddleVy * delta;
        if (mPaddlePy < 0)mPaddlePy = 0;
        if (mPaddlePy > height - mPaddleH)mPaddlePy = height - mPaddleH;
    }
    //mPaddle‚ÆmBall‚Ì“–‚½‚è”»’è
    if (mPaddlePx + mPaddleW > mBallPx &&
        mPaddlePx < mBallPx + mBallW &&
        mPaddlePy < mBallPy + mBallH &&
        mPaddlePy + mPaddleH > mBallPy &&
        mBallVx < 0)
    {
        mBallVx *= -1;
    }
}

void Game::GenerateOutput()
{
    clear(60);
    rect(mPaddlePx, mPaddlePy, mPaddleW, mPaddleH);
    rect(mBallPx, mBallPy, mBallW, mBallH);
}
