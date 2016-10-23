#pragma once

#include "CppUnitTest.h"

#include <sstream>
#include <vector>
#include <string>

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {

template <class T> std::wstring ToString(const std::vector<T> &t) {
  ostringstream ss;
  ss << t;
  std::string str = ss.str();
  return std::wstring(str.begin(), str.end());
}
}
}
}
