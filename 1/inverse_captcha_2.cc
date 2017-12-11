#include "../test.h"

#include <string>

unsigned inverse_captcha(std::string s) {
  unsigned total = 0;

  char last = s.back();
  for (size_t idx = 0; idx < s.size(); ++idx) {
    if (s[idx] == s[(idx + s.size() / 2) % s.size()]) {
      total += s[idx] - '0';
    }
  }

  return total;
}


int main(int argc, char* argv[]) {
  EXPECT_EQUAL(inverse_captcha(std::string("1212")), 6);
  EXPECT_EQUAL(inverse_captcha(std::string("1221")), 0);
  EXPECT_EQUAL(inverse_captcha(std::string("123425")), 4);
  EXPECT_EQUAL(inverse_captcha(std::string("123123")), 12);
  EXPECT_EQUAL(inverse_captcha(std::string("12131415")), 4);
}
