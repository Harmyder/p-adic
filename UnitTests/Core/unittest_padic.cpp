#include "stdafx.h"
#include "MyCppUnitTestFramework.h"

#include "CppUnitTest.h"

#include "Core\padic.h"
#include "Utilities\Printing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace padic_arithmetic;
using namespace std;
using namespace Utilities;

namespace UnitTests
{
    TEST_CLASS(UnitTest_padic)
    {
    public:

        TEST_METHOD(TestMethod_construct_from_integer)
        {
            padic p2 = padic::construct(2, 256);
            Assert::AreEqual(8, p2.base());
            Assert::AreEqual(padic::Type(1), p2.period());
            Assert::AreEqual({1}, p2.coefs());
        }
    };
}