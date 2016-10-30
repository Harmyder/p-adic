#pragma once

#include "CppUnitTest.h"

#include "Core\fraction.h"

#include <sstream>
#include <vector>
#include <string>

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {

template <class T> std::wstring ToString(const std::vector<T> &t) {
  ostringstream ss;
  ss << "{";
  std::string sep = "";
  for (auto a : t) {
      ss << sep;
      ss << a;
      sep = " ";
  }
  ss << "}";
  std::string str = ss.str();
  return std::wstring(str.begin(), str.end());
}

template <class T> std::wstring ToString(const Core::fraction<T> &f) {
    ostringstream ss;
    ss << f.n << "/" << f.d;
    std::string str = ss.str();
    return std::wstring(str.begin(), str.end());
}
}
}
}
