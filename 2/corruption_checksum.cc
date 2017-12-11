#include "../test.h"

#include <algorithm>
#include <string>

bool invalid_negative(int l, int r) {
  if (l < 0) {
    return false;
  } else if (r < 0) {
    return true;
  }
  return l < r;
}

unsigned corruption_checksum(int **s, size_t num_rows, size_t num_cols) {
  unsigned sum = 0;
  for (int row = 0; row < num_rows; ++row) {
    sum += (*std::max_element(s[row], s[row] + num_cols)
            - *std::min_element(s[row], s[row] + num_cols, invalid_negative));
  }

  return sum;
}

int main(int argc, char* argv[]) {
  int **s = new int*[3];
  for (int i = 0; i < 3; ++i) {
    s[i] = new int[4];
  }

  s[0][0] = 5;
  s[0][1] = 1;
  s[0][2] = 9;
  s[0][3] = 5;

  s[1][0] = 7;
  s[1][1] = 5;
  s[1][2] = 3;
  s[1][3] = -1;

  s[2][0] = 2;
  s[2][1] = 4;
  s[2][2] = 6;
  s[2][3] = 8;

  EXPECT_EQUAL(corruption_checksum(s, 3, 4), 18);
}
