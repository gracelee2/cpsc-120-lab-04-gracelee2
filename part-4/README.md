# Matrix Colors

# This is an optional exercise.

[Inigo Quilez](https://iquilezles.org/) tweeted [the "Matrix Color" formula](https://twitter.com/iquilezles/status/1440847977560494084).

The formula given in the tweet is ![(r, g, b) \mapsto (r^\frac{3}{2}, g^\frac{4}{5}, b^\frac{3}{2})](https://render.githubusercontent.com/render/math?math=%28r%2C%20g%2C%20b%29%20%5Cmapsto%20%28r%5E%5Cfrac%7B3%7D%7B2%7D%2C%20g%5E%5Cfrac%7B4%7D%7B5%7D%2C%20b%5E%5Cfrac%7B3%7D%7B2%7D%29).

Let's review a few things before looking at how we can use this formula.

A [pixel](https://en.wikipedia.org/wiki/Pixel) is the smallest addressable unit in our digital images and each pixel stores three values. The values are how much red, green and blue are in that pixel. The red, green, and blue represent the color of the pixel.

Color, in our digital images, is composed of just red, green, and blue. The value for the color is defined as a floating point number that is between 0 and 1. The table below defines some common colors so you can see how a color is defined.

| Color | Red | Green | Blue |
| ----- | --- | ----- | ---- |
| White | 1.0 | 1.0   | 1.0  |
| Black | 0.0 | 0.0   | 0.0  |
| Red   | 1.0 | 0.0   | 0.0  |
| Yellow| 1.0 | 1.0   | 0.0  |
| Orange| 1.0 | 0.5   | 0.0  |
| Purple| 1.0 | 0.0   | 1.0  |

If you have an image, then the pixel in the upper left hand corner of the image shall be our origin with an address of (0, 0). Pixels to right of our origin will have an increasing x value and pixels below our origin will have increasing y values.

Back to the formula. The formula ![(r, g, b) \mapsto (r^\frac{3}{2}, g^\frac{4}{5}, b^\frac{3}{2})](https://render.githubusercontent.com/render/math?math=%28r%2C%20g%2C%20b%29%20%5Cmapsto%20%28r%5E%5Cfrac%7B3%7D%7B2%7D%2C%20g%5E%5Cfrac%7B4%7D%7B5%7D%2C%20b%5E%5Cfrac%7B3%7D%7B2%7D%29) means that if you take a pixel with a red value of _r_, a green value of _g_, and a blue value of _b_, then take _r_ to the 3/2 power (1.5), take _g_ to the 4/5 power (0.8), and take g to the 3/2 power (1.5).

This is easy enough to do because there is a function in the the C++ Numerics library named [`pow()`](https://en.cppreference.com/w/cpp/numeric/math/pow) which will take a floating point number and raise it to a floating point power. For example, to take 0.4 to the 0.8 power (![0.4^{0.8}](https://render.githubusercontent.com/render/math?math=0.4%5E%7B0.8%7D)) then using the function `pow()` it would be `float val = pow(0.4, 0.8)`.

Our goal is to visit every pixel in the image, read in the original color value, transform the color mathematically, then save the color to a new image.

The starter code handles creating a new image for you. The part left to you is looping through the input image and transforming the color.

The algorithm can be described in [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) as the following. Consider that the row represents the y direction and the column represents the x direction of the image.

1. For each row

    1. For each column

        1. Declare a variable named _color_

        1. Read the value from pixel and store it into _color_ `color = input_image.pixelColor(column, row);`

        1. Declare a variable named _new_red_

        1. Using _color_, calculate the new red color `new_red = pow(color.red(), (3.0 / 2.0));`

        1. Declare a variable named _new_green_

        1. Using _color_, calculate the new green color `new_green = pow(color.green(), (4.0 / 5.0));`

        1. Declare a variable named _new_blue_

        1. Using _color_, calculate the new blue color `new_blue = pow(color.blue(), (3.0 / 2.0));`

        1. Declare a new color variabled named _new_color_ and initialize it with the colors that were just calculated `ColorRGB new_color{new_red, new_green, new_blue};`

        1. Save the new color into the new image `matrix_image.pixelColor(column, row, new_color);`


## Requirements

Write a program that takes an image (JPG or PNG) as a command line argument, transforms the colors of the image pixel by pixel using the Matrix Color formula, and save the new image as a new file.

Use the ImageMagick library to create the image as demonstrated in the starter code.

You must use loops to programmatically read, create, and save the colors in the images. There must be at least one loop in your program. You may use any combination of for loops, while loops, and do-while loops.

Use the algorithm specified above to create the image.

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
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 matrix_colors.cc \
| sed 's/\(matrix_colors\)\.o[ :]*/\1.o matrix_colors.d : /g' > matrix_colors.d; \
[ -s matrix_colors.d ] || rm -f matrix_colors.d
clang++ -g -O3 -Wall -pipe -std=c++14  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c matrix_colors.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -lGraphicsMagick++ -o matrix_colors matrix_colors.o 
$ cp images/keanu_reeves.jpg .
$ ./matrix_colors keanu_reeves.jpg 
Image keanu_reeves.jpg is 1388 by 1777 pixels.
Writing output to matrix_keanu_reeves.jpg.
$ gio open matrix_keanu_reeves.jpg
```

The command `gio open matrix_keanu_reeves.jpg` will open the image in your image viewer. The image must be identical to the one shown below.

![Original airport.jpg](images/airport.jpg)

![Matrix Color matrix_airport.jpg](images/matrix_airport.jpg)

![Original keanu_reeves.jpg](images/keanu_reeves.jpg)

![Matrix Color matrix_keanu_reeves.jpg](images/matrix_keanu_reeves.jpg)

![Original long_beach.png](images/long_beach.png)

![Matrix Color matrix_long_beach.png](images/matrix_long_beach.png)

## Image Credits
The sample images located in the `image` directory are by the author except for:

 * keanu_reeves.png, licensed CC By 2.0 from [Wikipedia](https://en.wikipedia.org/wiki/Keanu_Reeves#/media/File:Reuni%C3%A3o_com_o_ator_norte-americano_Keanu_Reeves_(46806576944)_(cropped).jpg) originally from [Flickr](https://www.flickr.com/photos/governosp/46806576944/)


