#pragma once

#include <vector>

namespace Core
{
    class cont_frac
    {
    public:
        explicit cont_frac(const int i);
        cont_frac(double r, const unsigned char max_len);

        double to_double() const;
        std::pair<long, long> to_fraction(const long max_denom) const;

        const std::vector<long>& coefs() const { return coefs_; }

    private:
        std::vector<long> coefs_;
    };
}
