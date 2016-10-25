#include "stdafx.h"

#include "Utilities\Debug.h"

#include <Windows.h>

using namespace std;

namespace Utilities
{
    Debug& Debug::instance()
    {
        static Debug debug;
        return debug;
    }

    void Debug::flush() {
        OutputDebugStringA(output.str().c_str());
    }
}
