#pragma once
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//Paddle
	float PaddleH;
	float PaddleW;
	float PaddlePx;
	float PaddlePy;
	float PaddleVy;
	float BallH;
	float BallW;
	float BallPx;
	float BallPy;
	float BallVx;
	float BallVy;

};

