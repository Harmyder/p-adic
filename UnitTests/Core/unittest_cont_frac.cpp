#include "stdafx.h"
#include "MyCppUnitTestFramework.h"

#include "CppUnitTest.h"

#include "Core\cont_frac.h"
#include "Utilities\Printing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Core;
using namespace std;
using namespace Utilities;

namespace UnitTests
{
    TEST_CLASS(UnitTest_cont_frac)
    {
    public:

        TEST_METHOD(TestMethod_from_double)
        {
            const double delta = 1.e-8;
            {
                cont_frac cf(1.1, 2);
                double d = cf;
                Assert::AreEqual(1.1, d, delta);
            }

            {
                cont_frac cf2(1.1, 2);
                cont_frac cf4(1.1, 4);
                Assert::AreEqual(cf2.coefs(), cf4.coefs());
            }

            {
                cont_frac cf(1./3., 100);
                double d = cf;
                Assert::AreEqual(1. / 3., d, delta);
            }

            {
                double gr = 1.61803398874989484;
                cont_frac golden(gr, 100);
                double d = golden;
                Assert::AreEqual(gr, d, delta);
            }
        }
    };
}