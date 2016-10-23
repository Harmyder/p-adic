#pragma once

#include <vector>

namespace padic_arithmetic
{
    class padic {
    public:
        static padic construct(int p, int number);

        padic(unsigned char p) : p_(p), base_(0) {}

        friend std::ostream& operator<< (std::ostream& stream, const padic& p);

        void negate();

    private:
        const unsigned char p_;
        unsigned char base_;
        unsigned char period_;
        std::vector<char> coefs_;
    };
}
