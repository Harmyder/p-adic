#include "stdafx.h"
#include "MyCppUnitTestFramework.h"

#include "CppUnitTest.h"

#include "Core\fraction.h"
#include "Utilities\Printing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Core;
using namespace std;
using namespace Utilities;

namespace UnitTests
{
    TEST_CLASS(UnitTest_fraction)
    {
    public:

        TEST_METHOD(TestMethod_cons)
        {
            fraction<long> f(1, 2);
            Assert::AreEqual(1l, f.n);
            Assert::AreEqual(2l, f.d);
        }

        TEST_METHOD(TestMethod_comparison)
        {
            fraction<long> a(1, 2);
            fraction<long> b(1, 3);

            Assert::AreEqual(true, b < a);
            Assert::AreEqual(false, a < b);
            Assert::AreEqual(false, b < b);

            Assert::AreEqual(false, b > a);
            Assert::AreEqual(true, a > b);
            Assert::AreEqual(false, b > b);

            Assert::AreEqual(true, b == b);
            Assert::AreEqual(false, b == a);
        }

        TEST_METHOD(TestMethod_part)
        {
            fraction<long> a(5, 2);
            Assert::AreEqual(fraction<long>(1, 2), a.frac_part());
            Assert::AreEqual(2l, a.int_part());
        }

        TEST_METHOD(TestMethod_to_human_readable)
        {
            {
                fraction<long> f(111111112l, 333333333l);
                const auto readable = to_human_readable(f, fraction<long>(1, 10e6));
                Assert::AreEqual(fraction<long>(1l, 3l), readable);
            }

            {
                fraction<long> f(444444445l, 333333333l);
                const auto readable = to_human_readable(f, fraction<long>(1, 10e6));
                Assert::AreEqual(fraction<long>(4l, 3l), readable);
            }

            {
                const auto f = to_human_readable(fraction<long>(8472869, 65536), fraction<long>(1l, 10e4l));
                Assert::AreEqual(fraction<long>(905l, 7l), f);
            }
        }
    };
}