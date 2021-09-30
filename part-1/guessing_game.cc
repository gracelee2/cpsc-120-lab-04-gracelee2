// Grace Lee
// CPSC 120-01
// 2021-09-30
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 04-01
//
// This program guesses a number by using loops
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  const int kSecretNumber = 42;
  int guess = 0;
  int last_guess = 0;
  string answer;

  cout << "Hi - I'm a computer and I've thought of a number between "
          "1 and 100.\n";
  cout << "Let's play a guessing game...\n";
  bool is_game_over = false;

  while (is_game_over == false) {
    cout << "What's your guess?> ";
    cin >> guess;
    int difference_guess = kSecretNumber - guess;
    int difference_last_guess = kSecretNumber - last_guess;
    last_guess = guess;
    if (guess == kSecretNumber) {
      cout << "\tHooray! You guessed the secret number!!\n";
      cout << "Do you want to play again? (y or n)>";
      cin >> answer;
      if (answer == "n") {
        is_game_over = true;
      } else if (answer == "y") {
        is_game_over = false;
      }

    } else if (difference_guess < difference_last_guess) {
      cout << "\tYou're getting warmer.\n";
    } else {
      cout << "\tYou're getting colder.\n";
    }
  }

  return 0;
}
