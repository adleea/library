#include "utility.h"
#ifndef __UTILITY_CPP
#define __UTILITY_CPP

std::string to_string(int x) {
  std::string result;
  bool sgn = (x >= 0);
  if (x == 0)
    return "0";
  while (x != 0) {
    result.push_back((x % 10) + '0');
    x /= 10;
  }
  if (sgn == false) {
    result.push_back('-');
  }
  std::reverse(result.begin(), result.end());
  return result;
}
#endif