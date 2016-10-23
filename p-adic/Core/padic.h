#pragma once

#include <vector>

namespace padic_arithmetic
{
    class padic {
    public:
        using Type = unsigned char;
        static padic construct(Type p, int number);

        padic(Type p) : p_(p), base_(0) {}

        void negate();

    public:
        int base() const { return base_; }
        Type period() const { return period_; }
        const std::vector<Type>& coefs() const { return coefs_; }

    private:
        const Type p_;
        int base_;
        Type period_;
        std::vector<Type> coefs_;
    };
}
