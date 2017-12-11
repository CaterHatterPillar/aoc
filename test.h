#pragma once

#include <iostream>
#include <stdlib.h>

#define STR(l) #l
#define XSTR(l) STR(l)

#define LOCATION __FILE__ ":" XSTR(__LINE__) ": "  // Looks good in Emacs

#define MSG(msg) std::cerr << LOCATION << msg << std::endl
#define MSG_UNLESS(cond, msg)                           \
  do {                                                  \
    if (!(cond)) {                                      \
      MSG(msg);                                         \
    }                                                   \
  } while (0)

#define FAIL(msg)                               \
  do {                                          \
    MSG(msg);                                   \
    exit(EXIT_FAILURE);                         \
  } while (0)

#define FAIL_UNLESS(cond, msg)                          \
  do {                                                  \
    MSG_UNLESS(cond, msg);                              \
    if (!(cond)) {                                      \
      exit(EXIT_FAILURE);                               \
    }                                                   \
  } while (0)

#define EXPECT_TRUE(cond) MSG_UNLESS(cond, "expected true")
#define EXPECT_FALSE(cond) MSG_UNLESS(!cond, "expected false")
#define EXPECT_EQUAL(l, r) MSG_UNLESS(l == r, "expected " << l << " == " << r)

#define REQUIRE_TRUE(cond) FAIL_UNLESS(cond, "expected true")
#define REQUIRE_FALSE(cond) FAIL_UNLESS(!cond, "expected false")
#define REQUIRE_EQUAL(l, r) FAIL_UNLESS(l == r, "expected " << l << " == " << r)

#define EXPECT_EXCEPTION(statement, exception)                  \
  try {                                                         \
    statement;                                                  \
    FAIL("expected exception " #exception " not thrown");       \
  } catch(const exception& e) {}
