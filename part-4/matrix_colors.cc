
#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace Magick;

int main(int argc, char const* argv[]) {
  InitializeMagick(*argv);
  vector<string> args = vector<string>{argv, argv + argc};
  if (args.size() < 2) {
    cout << "Please provide an input file. Exiting.\n";
    return 1;
  }
  InitializeMagick(*argv);
  Image input_image;
  ColorRGB white{1, 1, 1};
  try {
    input_image.read(args.at(1));
  } catch (out_of_range const& exception) {
    cout << exception.what() << "\n";
    return 1;
  } catch (Exception const& exception) {
    cout << exception.what() << "\n";
    return 1;
  }
  cout << "Image " << args.at(1) << " is " << input_image.columns() << " by "
       << input_image.rows() << " pixels.\n";

  string matrix_image_filename = "matrix_" + args.at(1);
  Image matrix_image;
  matrix_image = Image(input_image.page(), white);
  matrix_image.type(TrueColorType);
  matrix_image.modifyImage();

  // TODO: Write the loop to visit every pixel here.
  // Use the information in the README.md to write the loop
  // using the pseudocode algorithm.

  cout << "Writing output to " << matrix_image_filename << ".\n";
  matrix_image.write(matrix_image_filename);
  return 0;
}
