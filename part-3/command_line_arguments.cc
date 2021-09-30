
#include <iostream>
#include <vector>

using namespace std;

// Our main function serves as our entry point into our program. The compiler
// looks for our main function and translates it to the first instruction that
// the computer will execute when our program is loaded. Having main be our
// entry point into or program is not part of the C++ langauge - it is a
// convention that is followed by C++ and many, many other languages. Many
// programmers will ask 'where's the main function' when they wish to figure out
// how a program starts.
//
// The operating system can speak to our program by passing it strings of
// information from the command line to our main function. This method of
// talking to our programs from the operating system dates back to the 1960s and
// it has not changed since then. That's why the parameters to our main function
// look so weird. The parameters are `int argc` and `char const* argv[]`.
//
// The first parameter is `int argc`. The variable argc is an `int` variable
// with the name `argc`. This variable represents the count of how many
// arguments that were given on the command line. That's what it is called _arg_
// _c_ because _arg_ means argument and _c_ means count.
//
// The secoond parameter is `char const* argv[]`. It is often just written as
// `char* argv[]`. It means that it is a collection of strings and the strings
// are stored in an old fashioned way. Each string in `argv` represents
// something that was submitted on the command line along with the program. For
// example, when you use the command `clang++ my_program.cc`, the operating
// system talks to the program `clang++` and tells it you want to compile the
// file my_program.cc by putting the name of the file into `argv`. The word
// `argv` means _argument_ _vector_. A vector is like a list of things so you
// can think of `argv` as a list of arguments.
//
// Since `argv` is such an old timey thing, we can modernize it to a C++ vector
// (which is like a list) using the statement `vector<string> args =
// vector<string>(argv, argv+argc);`. It's a little hard to explain exactly what
// this statement does. You can understand it as it translating an old timey
// `argv` into a modern C++ typed variable named `args` which lets us look at
// what was typed on the command line.
int main(int argc, char const* argv[]) {
  // This is a very important statement.
  // It converts our command line arguements into a C++ vector of string
  // arguments.
  vector<string> args = vector<string>(argv, argv + argc);
  // args.size() tells us how many items are inside of args.
  if (args.size() < 2) {
    cout << "Pleaes provide command line arguments.\n";
    cout << "For example, try this command:\n";
    cout << args.at(0) << " yellow blue orange purple red teal\n";
  }
  // Using args.size() figure out how many things are inside of args
  cout << "The argument count is " << args.size() << "\n";
  // Starting at the 0th item of args, loop through args until you reach the end
  // by counting from 0 up to args.size()
  for (int index = 0; index < args.size(); index++) {
    try {
      // args.at() will fetch whatever item is inside of args at that location.
      // Remember you have to provide a number to args.at() such as the loop
      // counter. If you give a number too large or too small then args will
      // throw an exception. An exception is like when a referee stops the game
      // in the middle of a play because something has gone wrong. When your
      // program makes a mistake, an exception is thrown (like your operating
      // system blowing a whistle) and you have to catch the exception.
      std::cout << "args.at(" << index << ") is \"" << args.at(index) << "\"\n";
    } catch (out_of_range const& problem) {
      // Catching the exception means that you exit your program gracefully. If
      // we don't catch the exception the program will crash. You should never
      // have a program that crashes.
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      // And when a problem occurs and you are exiting gracefully, you don't
      // return 0. You return 1. This tells the operating system and your
      // computer user that your program exited due to an error or problem.
      return 1;
    }
  }
  // And now you know why we say return 0 at the end. If we don't encounter a
  // problem, we return 0 signaling to our operating sytem that everything is
  // OK. If something goes wrong and we catch it, we return 1 to tell our
  // operating systme that we enountered and error.
  return 0;
}
