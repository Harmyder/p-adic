#include "stdafx.h"
#include "MyCppUnitTestFramework.h"

#include "CppUnitTest.h"

#include "Core\farey.h"
#include "Core\fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Core;
using namespace std;

namespace UnitTests
{
    TEST_CLASS(UnitTest_farey)
    {
    public:

        TEST_METHOD(TestMethod_in_between)
        {
            const auto b = farey<long>::in_between(fraction<long>(0, 1), fraction<long>(1, 2));
            Assert::AreEqual(fraction<long>(1, 3), b);
        }
    };
}