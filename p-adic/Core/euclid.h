#pragma once

namespace Core
{
    template <typename T>
    T gcd(T a, T b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        if (b > a) {
            std::swap(a, b);
        }
        T r;
        while (b > 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    template <typename T>
    T ex_gcd(const T& a, const T& b, T& x, T& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }

        T x1, y1;
        T gcd = ex_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }

    template <typename T>
    T inv_mod(T a, T p) {
        T x, y;
        ex_gcd(a, p, x, y);
        return x < 0 ? p + x : x;
    }
}