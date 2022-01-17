#include <iostream>

using namespace std;

class Game {
private:
	int pointsGoal;
	bool running;

public:
	Game();

	bool isRunning();
	void setRunning(bool value);
	bool checkWin(int points);
};
