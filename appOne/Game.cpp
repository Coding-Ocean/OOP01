#include "Game.h"
#include "framework.h"
#include "graphic.h"
#include "input.h"
#include "window.h"

bool Game::Initialize()
{
    window(1024, 768);
    PaddleH = 120;
    PaddleW = 20;
    PaddlePx = 100;
    PaddlePy = height / 2 - PaddleH / 2;
    BallH = 20;
    BallW = 20;
    BallPx = 700;
    BallPy = 400;
    BallVx = -300;
    BallVy = -300;
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
    PaddleVy = 0;
    if (isPress(KEY_W))PaddleVy = -300;
    if (isPress(KEY_S))PaddleVy = 300;
}

void Game::UpdateGame()
{
    setDeltaTime();
    //Paddle‚Ì“®‚«
    if (PaddleVy!=0)
    {
        PaddlePy += PaddleVy * delta;
        if (PaddlePy < 0)PaddlePy = 0;
        if (PaddlePy > height - PaddleH)PaddlePy = height - PaddleH;
    }
    //Ball‚Ì“®‚«
    BallPx += BallVx * delta;
    BallPy += BallVy * delta;
    if (BallPy < 0 && BallVy < 0)
    {
        BallVy *= -1;
    }
    if (BallPy > Height - BallH  && BallVy > 0)
    {
        BallVy *= -1;
    }
    if (BallPx > width - BallW && BallVx > 0)
    {
        BallVx *= -1;
    }
    if (BallPx < -200)
    {
        closeWindow();
    }
    //Paddle‚ÆBall‚Ì“–‚½‚è”»’è
    if (PaddlePx + PaddleW > BallPx &&
        PaddlePx < BallPx + BallW &&
        PaddlePy < BallPy + BallH &&
        PaddlePy + PaddleH > BallPy &&
        BallVx < 0)
    {
        BallVx *= -1;
    }
}

void Game::GenerateOutput()
{
    clear(60);
    rect(PaddlePx, PaddlePy, PaddleW, PaddleH);
    rect(BallPx, BallPy, BallW, BallH);
}
