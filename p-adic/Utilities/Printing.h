#pragma once

#include <iostream>
#include <vector>

namespace padic_arithmetic
{
    class padic;
}

namespace Utilities
{
    std::ostream& operator<< (std::ostream& stream, const padic_arithmetic::padic& p);

    template <typename T>
    std::ostream& operator<< (std::ostream& stream, const std::vector<T>& p);
}
