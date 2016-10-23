#include "stdafx.h"

#include "Core\padic.h"
#include "Utilities\Printing.h"

#include <iostream>
#include <sstream>

using namespace std;
using namespace padic_arithmetic;
using namespace Utilities;

int main()
{
    vector<padic> vv = { padic::construct(2, 256), padic::construct(5, 199), padic::construct(5, -199) };
    cout << vv << endl;
    ostringstream _s;
    _s << vv;
    return 0;
}

