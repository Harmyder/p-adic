#pragma once

#include <iostream>
#include <vector>
#include "Core\padic.h"

namespace Utilities
{
    std::ostream& operator<< (std::ostream& stream, const padic_arithmetic::padic& p);

    template <typename T>
    std::ostream& operator<< (std::ostream& stream, const std::vector<T>& p) {
        string sep = "";
        cout << "{";
        for (int i = 0; i < (int)p.size(); ++i) {
            cout << sep << p[i];
            sep = ", ";
        }
        cout << "}";
        return stream;
    }
}
