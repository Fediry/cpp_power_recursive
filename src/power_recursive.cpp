// write a recursive function that computes x^n
// power(n)
// n is a non-negative whole number that the user enters as input
// x is a floating point number that the user enters as input
// example: given x=2.3 and n=4, 2.3^4; function should return 27.9841
// print results
//

#include "spdlog/spdlog.h"
#include <iostream>

using namespace std;

namespace power_recursion {

inline bool is_period(char const ch) { return tolower(ch) == '.'; }

bool is_number(char const ch) { return tolower(ch) >= '0' && ch <= '9'; }

bool is_number(string const str) {
  if (str.size() == 0) {
    return false;
  }
  // track if there is a period in the string (for floats)
  bool period_found = false;
  for (size_t i = 0; i < str.size(); i++) {
    char const ch = str[i];
    spdlog::debug("ch={}, is_number(ch)={}, is_period(ch)={}", ch,
                  is_number(ch), is_period(ch));
    if (i == 0 && is_number(ch) == false) {
      return false;
    }
    if (!period_found && (is_period(ch) && i < str.size() - 1)) {
      period_found = true;
      continue;
    }
    if (is_number(ch) == false) {
      return false;
    }
  }
  return true;
}

float power(float x, int n) {
  if (n == 0) {
    return 1;
  }

  x *= power(x, n - 1);
  return x;
}

void start() {
  string user_input;
  cout << "*** Power Recursive ***" << endl;

  while (user_input != q) {
    cout << "Enter a value for x('q' to quit): ";
    cin >> user_input;
    spdlog::debug("user_input={}", user_input);
  }
}
} // namespace power_recursion

int main() {
  spdlog::set_level(spdlog::level::debug);
  start();

  return 0;
}
