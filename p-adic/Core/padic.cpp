#include "stdafx.h"

#include "Core\padic.h"
#include "Core\cont_frac.h"
#include "Core\euclid.h"

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

namespace Core
{
    padic padic::construct(Type p, int number) {
        const bool negative = number < 0;
        if (negative) number = -number;

        int size = int(floor(log(number) / log(p)) + 1);
        padic res(p);

        int divider = (int)pow(p, size - 1);
        decltype(res.coefs_) coefs;
        for (int i = 0; i < size; ++i) {
            coefs.push_back(number / divider);
            number %= divider;
            divider /= p;
        }
        reverse(begin(coefs), end(coefs));
        int i = 0;
        while (i < (int)coefs.size() && coefs[i] == 0) i++;
        res.base_ = i;
        for (; i < size; ++i) {
            res.coefs_.push_back(coefs[i]);
        }
        res.period_ = (Type)res.coefs_.size();

        if (negative) {
            res.negate();
        }

        return move(res);
    }

    padic padic::construct(Type p, fraction<long> frac, char size) {
        long c = frac.n;
        long d = frac.d;

        padic res(p);
        while (c % p == 0) {
            ++res.base_;
            c /= p;
        }
        while (d % p == 0) {
            --res.base_;
            d /= p;
        }
        for (int i = 0; i < size; ++i) {
            if (c % p == 0) {
                res.coefs_.push_back(0);
                c /= p;
                continue;
            }
            auto d_inv = (unsigned char)inv_mod<long>(d, p);
            char signed_rem = c * d_inv % p;
            res.coefs_.push_back(signed_rem < 0 ? p + signed_rem : signed_rem);
            c -= d * res.coefs_.back();
            c /= p;
            assert(1 == gcd(c, d));
        }

        return res;
    }

    void padic::negate() {
        coefs_[0] = p_ - coefs_[0];
        for (int i = 1; i < (int)coefs_.size(); ++i) {
            coefs_[i] = p_ - coefs_[i] - 1;
        }
    }
}
