#pragma once

#include <sstream>
#include <memory>

namespace Utilities
{
    class Debug
    {
    public:
        static Debug& instance();
        
        std::ostringstream output;

        void flush();

    private:
        Debug() {};
        Debug(Debug const&) = delete;
        void operator=(Debug const&) = delete;
    };
}
