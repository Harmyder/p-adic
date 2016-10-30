#include "stdafx.h"

#include "Core\fraction.h"
#include "Core\farey.h"

namespace Core
{
    fraction<long> to_human_readable(fraction<long> f, fraction<long> epsilon) {
        int int_part = f.int_part();
        const auto frac = f.frac_part();

        fraction<long> between(0, 0);
        fraction<long> left(0, 1), right(1, 1);
        while (right - left > epsilon) {
            between = farey<long>::in_between(left, right);
            if (between < frac) left = between;
            else right = between;
        }
        auto res = left.d < right.d ? left : right;
        return res + fraction<long>(int_part * res.d, res.d);
    }
}
