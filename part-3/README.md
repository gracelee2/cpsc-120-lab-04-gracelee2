
# Command Line Arguments

## This is not an exercise. This is a demonstration program for you to study and learn from.

When we started programming remember that we used the command `clang++ hello_world.cc` to compile your program? What does this command mean to you?

One can look at that command and say that you want the C++ compiler named `clang++` to use the code saved in a file named `hello_world.cc` and compile it into a program that you can run on the computer. Notice that when you used the compiler that it never used any prompting similar to our programs.

Remember that prompting is when you print something to the terminal using `cout <<` and then read in values from the keyboard using `cin >>` and store it in a variable. Does this approach seem a little cumbersome?

The way that `clang++` knows about the input file `hello_world.cc` is because the operating system passes the command line arguments to the program. (Did you learn about command line arguments while you were reading the book [The Linux Command Line](http://linuxcommand.org/tlcl.php)?)

Whenever we have written a `main()` function it has been written like this the example below.

```
int main (int argc, char const *argv[]) {
  // code
  return 0;
}
```

The typed, named parameters to main are `int argc` and `char const *argv[]`. The first one, `int argc`, is named `argc` and is of type `int`. It represents the total number of command line arguments including the name of the program. The second one, `char const *argv[]`, is named `argv` and is of type `char const *[]` (we're going to pretend that we know what that means for a moment.) The variable `argv` represents a list of all the command line arguments represented as lists of characters (not strings). This is an old timey way of processing command line arguments however it means that it is backward compatible with the C programming language. ("_Backwards compatible_ means repeating the mistakes of the past today.")

Since `argv` is such an old timey thing, we can modernize it to a [C++ vector](https://en.cppreference.com/w/cpp/container/vector) (which is like a list) using the statement `vector<string> args = vector<string>(argv, argv+argc);`. It's a little hard to explain exactly what this statement does. You can understand it as it translating an old timey `argv` into a modern C++ typed variable named `args` which lets us look at what was typed on the command line.

Let's write a small program that demonstrates how to convert `argc` and `argv` into an `args` variable. Then let's use the `args` variable to view and process command line arguments. Since `args` contains all the command line arguments we can loop through each argument. Keep in mind that C++ starts counting from zero; the first argument is `args.at(0)`, the second argument is `args.at(1)`, the third argument is `args.at(2)`, etc. The variable `args` can tell us how many arguments there are with `args.size()`. We can use `args.size()` as a maximum count for whatever loop we use.

## Requirements

Study the program and learn how to use the variables `args` to process command line arguments.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++20 -D LINUX -D AMD64 command_line_arguments.cc \
| sed 's/\(command_line_arguments\)\.o[ :]*/\1.o command_line_arguments.d : /g' > command_line_arguments.d; \
[ -s command_line_arguments.d ] || rm -f command_line_arguments.d
clang++ -g -O3 -Wall -pipe -std=c++20 -D LINUX -D AMD64 -c command_line_arguments.cc
clang++ -g -O3 -Wall -pipe -std=c++20 -o command_line_arguments command_line_arguments.o 
$ ./command_line_arguments
For example, try this command:
./command_line_arguments yellow blue orange purple red teal
The argument count is 1
args.at(0) is "./command_line_arguments"
$ ./command_line_arguments yellow blue orange purple red teal
The argument count is 7
args.at(0) is "./command_line_arguments"
args.at(1) is "yellow"
args.at(2) is "blue"
args.at(3) is "orange"
args.at(4) is "purple"
args.at(5) is "red"
args.at(6) is "teal"
$ ./command_line_arguments 1 4 8 23 342.2342 45
The argument count is 7
args.at(0) is "./command_line_arguments"
args.at(1) is "1"
args.at(2) is "4"
args.at(3) is "8"
args.at(4) is "23"
args.at(5) is "342.2342"
args.at(6) is "45"
$ ./command_line_arguments orange 3 lemon 9 melon 2
The argument count is 7
args.at(0) is "./command_line_arguments"
args.at(1) is "orange"
args.at(2) is "3"
args.at(3) is "lemon"
args.at(4) is "9"
args.at(5) is "melon"
args.at(6) is "2"
```

