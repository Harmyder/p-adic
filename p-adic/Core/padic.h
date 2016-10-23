#pragma once

#include <vector>

namespace padic_arithmetic
{
    class padic {
    public:
        static padic construct(int p, int number);

        padic(unsigned char p) : p_(p), base_(0) {}

        void negate();

    public:
        unsigned char base() const { return base_; }
        unsigned char period() const { return period_; }
        const std::vector<unsigned char>& coefs() const { return coefs_; }

    private:
        const unsigned char p_;
        unsigned char base_;
        unsigned char period_;
        std::vector<unsigned char> coefs_;
    };
}
