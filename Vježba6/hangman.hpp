#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HangmanModel {
    public:
        string movie; // LORD OF THE RINGS
        string guessmovie; // ____ __ ___ _____
        string current_hangman;
        vector<char> used_letters;
        int lives = 7;
};

class HangmanView {
    public:
        void getHangmanDrawing(HangmanModel model);
        void displayCurrentProgress(HangmanModel model);
        void displayUsedLetters(HangmanModel model);
        void displayCorrect(HangmanModel model);
};

class HangmanController {
    public:
        void setRandomMovie(HangmanModel &model);
        void updateLives(HangmanModel &model, bool mistake);
        void inputLetter(HangmanModel &model);
        bool checkIfUsed(HangmanModel &model, char s);
        void updateMovieStrings(HangmanModel &model);
        void updateHangmanDrawing(HangmanModel &model);
        bool checkGameOver(HangmanModel &model);
};
