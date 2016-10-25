#include "stdafx.h"

#include "Core\cont_frac.h"

#include <limits>

using namespace std;

namespace Core
{
    cont_frac::cont_frac(const int i)
    {
        coefs_.push_back(i);
    }

    cont_frac::cont_frac(double r, const unsigned char max_len)
    {
        if (r > numeric_limits<long>::max()) {
            throw overflow_error("There is no capacity to represent such big real number");
        }

        while (coefs_.size() < max_len) {
            const long l = (long)r;
            coefs_.push_back(l);

            r -= l;
            if (r < 1. / numeric_limits<long>::max()) break;
            r = 1 / r;

            double logr = floor(log2(r)) + 1;
            const double kEpsilon = numeric_limits<double>::epsilon() * pow(2., logr);
            double dist_int = round(r) - r;
            if (abs(dist_int) <= kEpsilon * 10) {
                r = round(r);
            }
        }
    }

    cont_frac::operator double() const
    {
        double m[2][2] = { {1,0},{0,1} };
        int i = 0;
        for (double t : coefs_) {
            double h = t * m[0][0] + m[0][1];
            double k = t * m[1][0] + m[1][1];
            m[0][1] = m[0][0];
            m[1][1] = m[1][0];
            m[0][0] = h;
            m[1][0] = k;
        }

        return (double)m[0][0] / m[1][0];
    }
}