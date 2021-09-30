
# Integer Square Root

Let's say you want to calculate the square root of 62,425,801. You would probably reach for your calculator or use the magical powers of an Internet search engine to discover that the square root of 62,425,801 is 7,901.

How does your calculator figure out the answer? Did you ever learn in math class how to calcuate a square root? When did people learn how to calculate square roots?

Consider for a moment that there exists a [Babylonian clay tablet](https://en.wikipedia.org/wiki/YBC_7289) which has an accurate approximation to the square root of 2, 1.414213…. This tablet is believed to be have been made by a student and it dates back to 1800-1600 [BCE](https://en.wikipedia.org/wiki/Common_Era). [Heron's method](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method) is perhaps the first known algorithm for approximating a square root. The algorithm is named after the first century Greek mathematician [Hero of Alexandria](https://en.wikipedia.org/wiki/Hero_of_Alexandria) and it was first described in the year 60 [CE](https://en.wikipedia.org/wiki/Common_Era).

Calculating the square root for a number like 2 is not that complicated yet we are still learning about programming. Let us simplify our task to calculating [integer square roots](https://en.wikipedia.org/wiki/Integer_square_root) for positive integers.

An integer square root of the positive iteger n is the positive integer m which is the greatest integer less than or equal to the true square root of n.

![\textrm{isqrt}(n) = \lfloor \sqrt{n} \rfloor](https://render.githubusercontent.com/render/math?math=%5Ctextrm%7Bisqrt%7D%28n%29%20%3D%20%5Clfloor%20%5Csqrt%7Bn%7D%20%5Crfloor)

In the following table, the integer square root is calculated for the positive integers 1 through 10.

| n  | isqrt(n) |
| -- | -------- |
| 1  | 1  |
| 2  | 1  |
| 3  | 1  |
| 4  | 2  |
| 5  | 2  |
| 6  | 2  |
| 7  | 2  |
| 8  | 2  |
| 9  | 3  |
| 10 | 3  |

To calculate the integer square root, let's use Heron's method. Mathematically, the idea is to solve the equation ![x^2 - n = 0](https://render.githubusercontent.com/render/math?math=x%5E2%20-%20n%20%3D%200) using an iterative formula ![x_{k+1} = \frac{1}{2}\left(x_k + \frac{n}{x_k}\right), k \geq 0, x_0 > 0](https://render.githubusercontent.com/render/math?math=x_%7Bk%2B1%7D%20%3D%20%5Cfrac%7B1%7D%7B2%7D%5Cleft%28x_k%20%2B%20%5Cfrac%7Bn%7D%7Bx_k%7D%5Cright%29%2C%20k%20%5Cgeq%200%2C%20x_0%20%3E%200%0A). The sequence ![\{ x_k \}](https://render.githubusercontent.com/render/math?math=%5C%7B%20x_k%20%5C%7D) converges to ![\sqrt{n}](https://render.githubusercontent.com/render/math?math=%5Csqrt%7Bn%7D) as k approaches infinity.

In other words, if we used a loop, then we could repeatedly calculate ![\frac{1}{2}\left(x_k + \frac{n}{x_k}\right)](https://render.githubusercontent.com/render/math?math=%5Cfrac%7B1%7D%7B2%7D%5Cleft%28x_k%20%2B%20%5Cfrac%7Bn%7D%7Bx_k%7D%5Cright%29) and we would eventually find the integer square root.

Since translating this mathematical expression into C++ code is very difficult, let me explain the algorithm we will use [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) or a plain language description of the algorithm.

1. Get an _input_number_ which is a positive integer

1. Declare a variable _square_root_ which will store our answer

1. Declare a variable _initial_estimate_

1. Assign _input_number_ ÷ 2 to _initial_estimate_

1. If _initial_estimate_ is 0

    1. Assign _input_number_ to _square_root_

    1. Else

        1. Declare a variable _next_estimate_

        1. Assign (_initial_estimate_ + _input_number_ ÷ _initial_estimate_) ÷ 2 to _next_estimate_

        1. while _next_estimate_ is less than _initial_estimate_

            1. Assign _next_estimate_ to _initial_estimate_

            1. Assign (_initial_estimate_ + _input_number_ ÷ _initial_estimate_) ÷ 2 to _next_estimate_

        1. Assign _initial_estimate_ to _square_root_

  1. Return _square_root_ 


Remember, we are calculating the integer square root so everything we do will use only the `int` type. (Do not use `float` or `double`.)

The algorithm described above will work with numbers as small as 0 all the way to 2,147,483,647.


## Requirements

Write a program that prompts for a positive integer and then calculate the integer square root of the input value using Heron's method.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

Do not use any library functions to calculate the integer square root. Your calculations must be your own and must follow the algorithm provided in this README.md.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

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

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 isqrt.cc \
| sed 's/\(isqrt\)\.o[ :]*/\1.o isqrt.d : /g' > isqrt.d; \
[ -s isqrt.d ] || rm -f isqrt.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c isqrt.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o isqrt isqrt.o 
$ ./isqrt 
Let's calculate the integer square root of a number.
Please enter a positive integer: 2
The integer square root of 2 is 1.
$ ./isqrt 
Let's calculate the integer square root of a number.
Please enter a positive integer: 345362
The integer square root of 345362 is 587.
$ ./isqrt 
Let's calculate the integer square root of a number.
Please enter a positive integer: 892345
The integer square root of 892345 is 944.
```

