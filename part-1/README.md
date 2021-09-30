# Guessing Game

Let's write a guessing game where the player must guess a secret number between 1 and 100. Since we don't know how to generate random numbers and working with random numbers are unpredictable, we will always have the same secret number.

The goal of this exercise is to master the use of loops.

Your main function shall have an almost infinite loop. The only way to exit out of the almost infinite loop is if the player wins and then chooses to exit the game by refusing to play again.

There are two ways you can control an almost infinite loop.

The first is to create a boolean variable like `is_game_over` and set it to `false`. Then in your loop check to see if `not is_game_over` is true. If it is true, continue playing the game. If it turns out to be false, then the player doesn't want to continue.

The second approach is to write a `while` or `do-while` loop where the condition is always true. Let's say we want a `do-while` loop that is truly infinite.
```c++
do {
	cout << "This will go on forever!\n";
} while (true);
```

There is no way to escape this loop and the computer user must kill the program. (Remember, to kill a program press control key and the 'c' key at the same time.) There is a C++ keyword named [`break`](https://en.cppreference.com/w/cpp/language/break) which breaks you out of a loop.

```c++
do {
	break;
	cout << "This will go on forever!\n";
} while (true);
```

Placing a break in our infinite loop turns it into a loop that does not even run. This is because the moment the computer sees the break instruction, the computer jumps out of the loop.

The first approach is the best approach becaues the logic is clear and it tends to create more readable programs. However the logic can be a little sophisticated so it may be clearer for a beginner to use the second strategy.

Inside the loop, the player will be prompted to enter guesses. As the player guesses, keep track of their current guess and their last guess using variables. If their current guess gets them closer to the secret number than their last guess then they are getting warmer. If their current guess is further way from the secret number than the last guess then they are getting colder. Give these hints to the player as they make guesses to help the game along.

To calculate if the player's guesses are getting warmer or colder, consider the distance from the guess to the secret number. Mathematically, you can think of distance as the absolute value of the difference between the secret number and a given guess. When the distance decreases from the last guess to the current guess, then the player is getting warmer. Otherwise, the player is getting colder.

## Requirements

The entire game runs within a loop in the main function. The loop continues until the player wins and chooses to exit.

Declare two variables, `guess` and `last_guess` to keep track of the player's guesses. Initialize both to zero. After every guess, assign the value of guess to last_guess so that the game knows what the player is guessing currently and has guessed previously. This is needed to figure out if the player is getting warmer or colder.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

Whenever a guess is made that is incorrect, print out a message saying the guess was incorrect.

If the guess is incorrect, print a message hinting at which direction (greater or lesser than the current guess) the player should guess.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 guessing_game.cc \
| sed 's/\(guessing_game\)\.o[ :]*/\1.o guessing_game.d : /g' > guessing_game.d; \
[ -s guessing_game.d ] || rm -f guessing_game.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c guessing_game.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o guessing_game guessing_game.o 
$ ./guessing_game 
Hi - I'm a computer and I've thought of a number between 1 and 100.
Let's play a guessing game...
What's your guess?> 1
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 2
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 3
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 4
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 5
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 6
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 7
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 8
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 9
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 10
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 9
	Nope - that's not it.
	You're getting colder.
What's your guess?> 8
	Nope - that's not it.
	You're getting colder.
What's your guess?> 7
	Nope - that's not it.
	You're getting colder.
What's your guess?> 6
	Nope - that's not it.
	You're getting colder.
What's your guess?> 7
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 8
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 9
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 41
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 40
	Nope - that's not it.
	You're getting colder.
What's your guess?> 44
	Nope - that's not it.
	You're getting colder.
What's your guess?> 43
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 42
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> n
$ ./guessing_game 
Hi - I'm a computer and I've thought of a number between 1 and 100.
Let's play a guessing game...
What's your guess?> 42
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> y
Great!! I'd love to play again...
What's your guess?> 10
	Nope - that's not it.
	You're getting colder.
What's your guess?> 40
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 42
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> n
$
```

