#pragma once

#include <vector>
#include "Core\fraction.h"

namespace Core
{
    class padic {
    public:
        using Type = unsigned char;
        static padic construct(Type p, int number);
        static padic construct(Type p, fraction<long> number, char size);

        void negate();

    public:
        int base() const { return base_; }
        Type period() const { return period_; }
        const std::vector<Type>& coefs() const { return coefs_; }

    private:
        padic(Type p) : p_(p), base_(0), period_(0) {}

    private:
        const Type p_;
        int base_;
        Type period_;
        std::vector<Type> coefs_;
    };
}
