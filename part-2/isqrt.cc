// Grace Lee
// CPSC 120-01
// 2021-09-30
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 04-02
//
// Lab that calculates integer square roots
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
  cout << "Let's calculate the integer square root of a number.\n";
  cout << "Please enter a positive integer: ";
  int input_number = 0;
  cin >> input_number;
  int square_root = 0;
  int initial_estimate = input_number/2;
  if(initial_estimate == 0){
    square_root = input_number;
  }else{
    int next_estimate = (initial_estimate + input_number/initial_estimate)/2;

  while(next_estimate < initial_estimate){
    initial_estimate = next_estimate;
    next_estimate = (initial_estimate + input_number/initial_estimate)/2;
  }
  square_root = next_estimate;

}


  // TODO: Use Heron's method as described in the README to calculate the
  // integer square root of input_number and store it in square_root.
  // Use the information in the README.md to write the loop
  // using the pseudocode algorithm.

  cout << "The integer square root of " << input_number << " is " << square_root
       << ".\n";

  return 0;
}
