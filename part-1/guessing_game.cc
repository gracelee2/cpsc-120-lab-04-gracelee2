
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

  // TODO: Write an loop that will continue until the player decides to quit
  // TODO: Inside the loop, prompt the user for their guess
  // for example     cout << "What's your guess?> ";
  // TODO: Store the input from the keyboard into the variable guess
  // TODO: Check to see if guess has the same value as kSecretNumber
  //    If so, then the player has won and they can play again
  //    Prompt the user if they would like to continue playing. If the
  //    answer is "n" then exit the game. Otherwise, start a new game.
  // TODO: Else, the player didn't win so they need to know if they are
  //    getting warmer or colder.
  //    Check to see if kSecretNumber - guess is less than kSecretNumber -
  //    last_guess If it is, print you're getting warmer. Otherwise, print
  //    you're getting colder.
  // TODO: At the end of every iteration of the loop, save the current guess
  // into the variable last_guess.

  return 0;
}