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

	float mBallH;
	float mBallW;
	float mBallPx;
	float mBallPy;
	float mBallVx;
	float mBallVy;

	float mPaddleH;
	float mPaddleW;
	float mPaddlePx;
	float mPaddlePy;
	float mPaddleVy;
};

