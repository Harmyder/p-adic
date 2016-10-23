#include "stdafx.h"

#include "Core\padic.h"
#include "Utilities\Printing.h"

#include <iostream>

using namespace std;
using namespace padic_arithmetic;
using namespace Utilities;

int main()
{
    padic p2 = padic::construct(2, 256);
    cout << p2 << endl;
    padic p = padic::construct(5, 199);
    cout << p << endl;
    padic p1 = padic::construct(5, -199);
    cout << p1 << endl;
    return 0;
}

