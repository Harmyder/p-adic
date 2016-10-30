#pragma once

#include <vector>

#include "Core\fraction.h"

namespace Core
{
    class cont_frac
    {
    public:
        explicit cont_frac(const int i);
        cont_frac(double r, const unsigned char max_len);

        double to_double() const;
        fraction<long> to_fraction(const long max_denom) const;

        const std::vector<long>& coefs() const { return coefs_; }

    private:
        std::vector<long> coefs_;
    };
}
