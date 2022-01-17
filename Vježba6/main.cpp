#include "hangman.hpp"

using namespace std;

int main() {
    HangmanModel model;
    HangmanView view;
    HangmanController control;
    
    control.setRandomMovie(model);

    while(control.checkGameOver(model)) {

        control.updateHangmanDrawing(model);
        view.getHangmanDrawing(model);
        view.displayCurrentProgress(model);
        view.displayUsedLetters(model);
        control.inputLetter(model);
        control.updateMovieStrings(model);
    }

    control.updateHangmanDrawing(model);
    view.getHangmanDrawing(model);
    view.displayUsedLetters(model);
    view.displayCurrentProgress(model);
    view.displayCorrect(model);
}
