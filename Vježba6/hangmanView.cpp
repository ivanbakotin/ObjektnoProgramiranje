#include "hangman.hpp"

using namespace std;

void HangmanView::getHangmanDrawing(HangmanModel model) {
    cout  << model.current_hangman << endl;
}

void HangmanView::displayCurrentProgress(HangmanModel model) {
    cout << "Current progress: " << model.guessmovie << endl;
}

void HangmanView::displayCorrect(HangmanModel model) {
    cout << "Correct movie name: " << model.movie << endl;
}

void HangmanView::displayUsedLetters(HangmanModel model) {
    cout << "Used letters: ";
    for (int i = 0; i < model.used_letters.size(); i++) {
        cout << model.used_letters[i] << " ";
    }
    cout << endl;
}
