
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
  cout << "Let's calculate the integer square root of a number.\n";
  cout << "Please enter a positive integer: ";
  int input_number = 0;
  cin >> input_number;
  int square_root = 0;

  // TODO: Use Heron's method as described in the README to calculate the 
  // integer square root of input_number and store it in square_root.
  // Use the information in the README.md to write the loop
  // using the pseudocode algorithm.

  cout << "The integer square root of " << input_number << " is " << square_root
       << ".\n";
  return 0;
}
