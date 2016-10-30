#pragma once

#include "Core\euclid.h"

namespace Core
{
    template<typename T>
    class fraction
    {
        static_assert(std::is_integral<T>::value, "T must be integral");

    public:
        using _Me = fraction<T>;

        fraction(T n, T d) : n(n), d(d) {}
        explicit fraction(std::pair<T, T> p) : n(p.first), d(p.second) {}

        T n;
        T d;

        std::pair<T, T> to_pair() const { return make_pair(n, d); }

        bool operator<(const _Me& other) const { return nom_minus(*this, other) < 0; }

        bool operator>(const _Me& other) const { return nom_minus(*this, other) > 0; }

        bool operator==(const _Me& other) const { return nom_minus(*this, other) == 0; }

        _Me& operator=(const _Me& other) {
            n = other.n;
            d = other.d;
            return *this;
        }

        _Me operator-(const _Me& other) const { return reduce(_Me(nom_minus(*this, other), d * other.d)); }

        _Me operator+(const _Me& other) const { return reduce(_Me(nom_plus(*this, other), d * other.d)); }

        _Me operator*(const _Me& other) const { return reduce(_Me(n * other.n, d * other.d)); }

        _Me operator/(const _Me& other) const { return reduce(_Me(n * other.d, d * other.n)); }

        T int_part() const { return n / d; }

        _Me frac_part() const { return _Me(n % d, d); }

    private:
        static T nom_minus(const _Me a, const _Me& b) { return nom_plus_minus(a, b, std::minus<T>()); }

        static T nom_plus(const _Me a, const _Me& b) { return nom_plus_minus(a, b, std::plus<T>()); }

        template<class F>
        static T nom_plus_minus(const _Me& a, const _Me& b, F f) { return f(a.n * b.d, a.d * b.n); }
    };

    template <typename T>
    fraction<T> reduce(const fraction<T>& f) {
        T g = gcd(f.n, f.d);
        return fraction<T>(f.n / g, f.d / g);
    }

    fraction<long> to_human_readable(fraction<long> f, fraction<long> epsilon);
}

