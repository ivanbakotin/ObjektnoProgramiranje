#include <iostream>
#include <vector>
#include "string"
#include <sstream>
#include <time.h>

using namespace std;

void inputVectorSentences(vector<string> &vector, int n) {

    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Input sentence into the vector: ";
        string s;
        getline(cin, s);
        vector.push_back(s);
    }
}

void printVector(vector<string> &vector, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sentence: ";
        cout << vector[i] << endl;
    }
}

int getRandomSentence(int n) {

    srand ( time(NULL) );

    return rand()%(n-1);
}

bool isVowel(char s) {

    string vowels = "aeiouAEIOU";

    for (int i = 0; i < 11; i++) {
        if (s == vowels[i]) {
            return true;
        }
    }

    return false;
}

string consonantsOnTheEnd(string str) {

    int i = 0;

    while(!isVowel(str[i])) {
        i++;
    }

    return str.substr(i) + str.substr(0, i) + "ay";
}

void translateSentenceToPigLatin(string *sentence) {

    stringstream s(*sentence);
    string word;
    string pig;

    while (s >> word) {

        if (ispunct(word[0])) {
            pig += word;
        } else {
            if (isVowel(word[0])) {
                pig += word + "hay ";
            } 
            else {
                pig += consonantsOnTheEnd(word) + " ";
            }
        }
    }

    *sentence = pig;
}

int main() {

    vector<string> sentences;

    int sentences_number;

    cout << "Input number of sentences: ";

    cin >> sentences_number;

    inputVectorSentences(sentences, sentences_number);

    printVector(sentences, sentences_number);

    int index = getRandomSentence(sentences_number);

    translateSentenceToPigLatin(&sentences[index]);

    printVector(sentences, sentences_number);
}
