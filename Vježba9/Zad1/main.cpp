#include "Game.hpp"
#include "Player.hpp"

#include "vector"

int main() {
	Game game;
	vector<Player*> players;

	players.push_back(new HumanPlayer);

	bool win = false;
	int counter;
	cout << "How many computer enemies do you want?: ";
	cin >> counter;

	for (int i = 0; i < counter; i++) {
		players.push_back(new ComputerPlayer);
	}

	while (game.isRunning()) {
		for (int i = 0; i < players.size(); i++) {

			players[i]->chooseCoins();
			int hand = players[i]->getHand();

			for (int j = 0; j < players.size(); j++) {
				if (i != j) {
					players[j]->guessNumber(hand);
				}
			}
		}

		for (int i = 0; i < players.size(); i++) {
			if (game.checkWin(players[i]->getPoints())) {
				cout << "Player: " << i << "has won!" << endl;
				win = true;
			}
		}

		if (win) {
			game.setRunning(false);
		}
	}
}
