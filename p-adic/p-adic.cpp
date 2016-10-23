#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

namespace padic_arithmetic
{
    class padic {
    public:
        static padic construct(int p, int number) {
            const bool negative = number < 0;
            if (negative) number = -number;

            int size = ceil(log(number) / log(p));
            padic res;
            res.coefs_.resize(size);
            res.p_ = p;

            int divider = 1;
            for (int i = 0; i < size; ++i) {
                res.coefs_[i] = number % (divider * p) / divider;
                divider *= p;
            }

            res.as_ = res.cs_ = 0;
            res.bs_ = size;

            if (negative) {
                res.negate();
            }

            return move(res);
        }

        friend ostream& operator<< (std::ostream& stream, const padic& p);

        void negate() {
            coefs_[0] = p_ - coefs_[0];
            for (int i = 1; i < (int)coefs_.size(); ++i) {
                coefs_[i] = p_ - coefs_[i] - 1;
            }
        }

    private:
        unsigned char p_;
        int as_;
        int bs_;
        int cs_;
        vector<char> coefs_;
    };

    ostream& operator<< (ostream& stream, const padic& p) {
        int i = 0;
        string sep = "";
        for (; i < p.as_; ++i) {
            stream << sep << (int)p.coefs_[i];
            sep = " ";
        }
        stream << ".";
        sep = "";
        for (; i < p.as_ + p.bs_; ++i) {
            stream << sep << (int)p.coefs_[i];
            sep = " ";
        }
        stream << "(";
        sep = "";
        for (; i < p.as_ + p.bs_ + p.cs_; ++i) {
            stream << sep << (int)p.coefs_[i];
            sep = " ";
        }
        stream << ")";
        return stream;
    }
}

using namespace padic_arithmetic;

int main()
{
    padic p = padic::construct(5, 199);
    cout << p << endl;
    padic p1 = padic::construct(5, -199);
    cout << p1 << endl;
    return 0;
}

