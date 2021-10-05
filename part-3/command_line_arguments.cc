// Grace Lee
// CPSC 120-01
// 2021-09-30
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 04-03
//
// About Command line arguments
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 2) {
    cout << "Please provide command line arguments.\n";
    cout << "For example, try this command:\n";
    cout << args.at(0) << " yellow blue orange purple red teal\n";
  }
  cout << "The argument count is " << args.size() << "\n";

  for (int index = 0; index < args.size(); index++) {
    try {
      std::cout << "args.at(" << index << ") is \"" << args.at(index) << "\"\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";

      return 1;
    }
  }

  return 0;
}
