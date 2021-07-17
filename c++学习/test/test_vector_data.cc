#include <cmath>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  const int N = 1, H = 13, W = 13, C = 3;
  // Compute physical strides for each dimension
  const int stride_N = H * W * C;
  const int stride_H = W * C;
  const int stride_W = C;
  const int stride_C = 1;
  // An auxiliary function that maps logical index to the physical offset
  auto offset = [=](int n, int h, int w, int c) {
    return n * stride_N + h * stride_H + w * stride_W + c * stride_C;
  };
  // The image size
  const int image_size = N * H * W * C;
  // Allocate a buffer for the image
  std::vector<float> image(image_size);
  // Initialize the image with some values
  for (int n = 0; n < N; ++n)
    for (int h = 0; h < H; ++h)
      for (int w = 0; w < W; ++w)
        for (int c = 0; c < C; ++c) {
          int off = offset(n, h, w, c);  // Get the physical offset of a pixel
          image[off] = -std::cos(off / 10.f);
        }
  cout << image.data() << " " << *image.data() << endl;
  return 0;
}