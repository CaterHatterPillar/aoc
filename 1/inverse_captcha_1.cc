#include "../test.h"

#include <string>

unsigned inverse_captcha(std::string s) {
  unsigned total = 0;

  std::string::const_iterator last = --s.end();
  for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
    if (*it == *last) {
      total += *it - '0';
    }
    last = it;
  }

  return total;
}

int main(int argc, char* argv[]) {
  EXPECT_EQUAL(inverse_captcha(std::string("1122")), 3);
  EXPECT_EQUAL(inverse_captcha(std::string("1111")), 4);
  EXPECT_EQUAL(inverse_captcha(std::string("1234")), 0);
  EXPECT_EQUAL(inverse_captcha(std::string("91212129")), 9);
}
