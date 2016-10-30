#pragma once

#include "Core\fraction.h"

namespace Core
{
    template<typename T>
    class farey
    {
    public:
        static fraction<T> in_between(fraction<T> a, fraction<T> b) { return fraction<T>(a.n + b.n, a.d + b.d); }
    };
}

