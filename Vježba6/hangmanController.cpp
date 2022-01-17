#include "hangman.hpp"
#include <cctype>
#include <cstring>
#include <fstream>
#include <time.h>

using namespace std;

void HangmanController::setRandomMovie(HangmanModel &model) {

    srand(time(NULL));

    fstream newfile;

    vector<string> movies;

    newfile.open("movie.txt",ios::in);

    if (newfile.is_open()) { 

        string tp;

        while (getline(newfile, tp)) {
            movies.push_back(tp);
        }

       newfile.close(); 
    }

    model.movie = movies[rand() % movies.size()]; 

    for (int i = 0; i < model.movie.size(); i++) {
        if (isspace(model.movie[i])) {
            model.guessmovie.push_back(' ');
        } else {
            model.guessmovie.push_back('_');
        }
    }
}

void HangmanController::updateLives(HangmanModel &model, bool mistake) {
    if (mistake) model.lives--;
}

void HangmanController::updateMovieStrings(HangmanModel &model) {

    char letter = model.used_letters.back();
    bool mistake = true;

    for (int i = 0; i < model.movie.size(); i++) {
        if (model.movie[i] == letter) {
            model.guessmovie[i] = letter;
            mistake = false;
        }
    }

    updateLives(model, mistake);
}

bool HangmanController::checkIfUsed(HangmanModel &model, char s) {
    for (int i = 0; i < model.used_letters.size(); i++) {
        if (model.used_letters[i] == s) {
            return true;
        } 
    }

    return false;
}

void HangmanController::inputLetter(HangmanModel &model) {

    char s;

    do {
        cout << "Enter one non-used letter: "<< endl;
        cin >> s;

    } while((!isalpha(s)) || (checkIfUsed(model, s)));

    model.used_letters.push_back(s);
}

void HangmanController::updateHangmanDrawing(HangmanModel &model) {

    int lives = model.lives;

    string right_leg = (lives - 1) >= 0 ? " " : "\\";
    string left_leg = (lives - 2) >= 0 ? " " : "/";
    string torso_down = (lives - 3) >= 0 ? " " : "|";
    string right_hand = (lives - 4) >= 0 ? " " : "\\";
    string left_hand = (lives - 5) >= 0 ? " " : "/";
    string torso_up = (lives - 6) >= 0 ? " " : "|";
    string head = (lives - 7) >= 0 ? " " : "0";

    string s1 = "    ________       \n"
                "    | /  |         \n"
                "    |/   "+ head +"\n"
                "    |   "+left_hand+torso_up+right_hand+"\n"
                "    |    "+torso_down+"\n"
                "    |   "+left_leg+" "+right_leg+"\n"
                "    |              \n"
                "    |              \n"
                " ___|___           \n";

    model.current_hangman = s1;
}

bool HangmanController::checkGameOver(HangmanModel &model) {

    if (!model.lives) {
        cout << "YOU LOST" << endl;
        return false;
    }

    for (int i = 0; i < model.movie.size(); i++) {
        if (model.movie[i] != model.guessmovie[i]) {
            return true;
        }
    }

   cout << "YOU WON" << endl;
   return false;
}
