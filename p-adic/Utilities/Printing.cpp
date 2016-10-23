#include "stdafx.h"

#include "Utilities\Printing.h"

#include <iostream>
#include <vector>
#include <string>
#include "Core\padic.h"

using namespace std;
using namespace padic_arithmetic;

namespace Utilities
{
    ostream& operator<< (ostream& stream, const padic& p) {
        if (p.base() >= 0) stream << ".";
        for (int i = 0; i < abs(p.base()); ++i) cout << "0";
        if (p.base() < 0) stream << ".";
        for (int i = 0; i < (int)p.coefs().size(); ++i) {
            stream << (int)p.coefs()[i];
            if (i == p.period() - 1) cout << "(";
        }
        cout << ")";
        return stream;
    }

    template <typename T>
    ostream& operator<< (ostream& stream, const T& p) {
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
