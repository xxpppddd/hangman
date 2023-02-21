#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

string  chooseWord() {
    return "culture";
}

void renderGame(string guessedWord, int badGuessCount) {
    cout<< guessedWord<<"\n";
    cout << "Number of wrong guesses: " << badGuessCount<<"\n";
}

char readAGuess() {
    char guess;
    cin >> guess;
    return guess;
}

bool contains(string word, char guess) {
    return (word.find_first_of(guess) != string::npos);
}

string update (string guessedWord, string secretWord, char guess) {
     for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}

int main() {
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    const int MAX_BAD_GUESSES = 7;
    do {
            renderGame (guessedWord, badGuessCount);
            char guess = readAGuess();
            if (contains(secretWord, guess)) {
                guessedWord = update(guessedWord, secretWord, guess);
            }
            else badGuessCount++;
    } while (badGuessCount < MAX_BAD_GUESSES and secretWord != guessedWord);

    renderGame(guessedWord, badGuessCount);
    if (badGuessCount < 7) {
        cout<< "Congratulations! You win!!\n";
    }
    else {
        cout << "You lost. The correct word is '" << secretWord <<"'.\n";
    }
}



