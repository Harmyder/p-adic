#include "stdafx.h"

#include "padic.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace padic_arithmetic
{
    padic padic::construct(int p, int number) {
        const bool negative = number < 0;
        if (negative) number = -number;

        int size = ceil(floor(log(number) / log(p)) + 1);
        padic res(p);

        int divider = pow(p, size - 1);
        decltype(res.coefs_) coefs;
        for (int i = 0; i < size; ++i) {
            coefs.push_back(number / divider);
            number %= divider;
            divider /= p;
        }
        reverse(begin(coefs), end(coefs));
        int i = 0;
        while (coefs[i] == 0) i++;
        res.base_ = i;
        for (; i < size; ++i) {
            res.coefs_.push_back(coefs[i]);
        }
        res.period_ = res.coefs_.size();

        if (negative) {
            res.negate();
        }

        return move(res);
    }

    void padic::negate() {
        coefs_[0] = p_ - coefs_[0];
        for (int i = 1; i < (int)coefs_.size(); ++i) {
            coefs_[i] = p_ - coefs_[i] - 1;
        }
    }

    ostream& operator<< (ostream& stream, const padic& p) {
        if (p.base_ >= 0) stream << ".";
        for (int i = 0; i < abs(p.base_); ++i) cout << "0";
        if (p.base_ < 0) stream << ".";
        for (int i = 0; i < p.coefs_.size(); ++i) {
            stream << (int)p.coefs_[i];
            if (i == p.period_ - 1) cout << "(";
        }
        cout << ")";
        return stream;
    }
}
