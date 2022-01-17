#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Player {
protected:
	int currentHand;
	int points;
	bool coin1;
	bool coin2;
	bool coin3;

public:
	Player();
	virtual void chooseCoins() = 0;
	virtual void guessNumber(int hand) = 0;
	int getPoints();
	int getHand();
	void setHand(int coin);
	void resetHand();
};

class HumanPlayer : public Player {
public:
	void chooseCoins();
	void guessNumber(int hand);
};

class ComputerPlayer : public Player {
public:
	void chooseCoins();
	void guessNumber(int hand);
};
