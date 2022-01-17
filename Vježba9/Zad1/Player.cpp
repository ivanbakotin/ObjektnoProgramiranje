#include "Player.hpp"

Player::Player() {
	this->currentHand = 0;
	this->points = 0;
	this->coin1 = false;
	this->coin2 = false;
	this->coin3 = false;
}

int Player::getPoints() {
	return this->points;
}

int Player::getHand() {
	return this->currentHand;
}

void Player::setHand(int coin) {
	if (coin == 1) {
		coin1 = true;
	}
	if (coin == 2) {
		coin2 = true;
	}
	if (coin == 5) {
		coin3 = true;
	}
	this->currentHand += coin;
}

void Player::resetHand() {
	int currentHand = 0;
	bool coin1 = false;
	bool coin2 = false;
	bool coin3 = false;
}

void HumanPlayer::guessNumber(int hand) {
	cout << "Guess a number: ";
	int x;
	cin >> x;
	if (x == hand) {
		cout << "Correct guess" << endl;
		this->points++;
	}
	else {
		cout << "Inorrect guess" << endl;
	}
}

void ComputerPlayer::guessNumber(int hand) {
	 if ((rand() % 9) == hand) {
		 cout << "Correct guess" << endl;
		 this->points++;
	 }
	 else {
		 cout << "Incorrect guess" << endl;
	 }
}

void HumanPlayer::chooseCoins() {
	resetHand();

	int count;
	int guess;
	int i = 0;

	cout << "Choose how many coins you want (0, 1, 2, or 3)?" << endl;

	while (true) {
		cin >> count;

		if (count == 0 || count == 1 || count == 2 || count == 3) {
			break;
		} else {
			cout << "wrong input" << endl;
		}
	}

	while (i < count) {
		cout << "choose coin: (1,2,5) " << endl;
		cin >> guess;

		if (guess == 1) {
			setHand(1);
			i++;
		}
		else if (guess == 2) {
			setHand(2);
			i++;
		}
		else if (guess == 5) {
			setHand(5);
			i++;
		}
	}
}

void ComputerPlayer::chooseCoins() {
	resetHand();

	int count = rand() % 3;
	int guess;

	for (int i = 0; i < count; i++) {
		guess = rand() % 3;
		if (guess == 0) {
			setHand(1);
		} else if (guess == 1) {
			setHand(2);
		} else {
			setHand(5);
		}
	}
}
