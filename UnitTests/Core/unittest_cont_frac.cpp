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

        TEST_METHOD(TestMethod_cons)
        {
            {
                cont_frac cf2(1.1, 2);
                cont_frac cf4(1.1, 4);
                Assert::AreEqual(cf2.coefs(), cf4.coefs());
            }
        }

        TEST_METHOD(TestMethod_to_double)
        {
            const double delta = 1.e-8;
            {
                cont_frac cf(1.1, 2);
                double d = cf.to_double();
                Assert::AreEqual(1.1, d, delta);
            }

            {
                cont_frac cf(1./3., 100);
                double d = cf.to_double();
                Assert::AreEqual(1. / 3., d, delta);
            }

            {
                double gr = 1.61803398874989484;
                cont_frac golden(gr, 100);
                double d = golden.to_double();
                Assert::AreEqual(gr, d, delta);
            }


            {
                wchar_t message[200];
                double d = numeric_limits<long>::max() + 1.;
                try {
                    cont_frac cf(d, 2);
                    _swprintf(message, L"No exception for double %g", d);
                    Assert::Fail(message, LINE_INFO());
                }
                catch (std::overflow_error ex) {}
                catch (...) {
                    _swprintf(message, L"Incorrect exception for %g", d);
                    Assert::Fail(message, LINE_INFO());
                }
            }
        }

        TEST_METHOD(TestMethod_to_fraction)
        {
            const double delta = 1.e-8;
            {
                cont_frac cf(1.1, 2);
                pair<long, long> d = cf.to_fraction(10);
                Assert::AreEqual(d.first, 11l);
                Assert::AreEqual(d.second, 10l);
            }

            {
                cont_frac cf(1. / 3., 100);
                pair<long, long> d = cf.to_fraction(3);
                Assert::AreEqual(d.first, 1l);
                Assert::AreEqual(d.second, 3l);
            }

            {
                double gr = 1.61803398874989484;
                cont_frac golden(gr, 100);
                pair<long, long> d = golden.to_fraction(numeric_limits<long>::max());
                Assert::AreEqual(d.first, 559986409l);
                Assert::AreEqual(d.second, 346090634l, delta);
            }

            {
                wchar_t message[200];
                const long max_den = 0;
                try {
                    cont_frac cf(1., 2);
                    cf.to_fraction(max_den);
                    _swprintf(message, L"No exception for max_den %l", max_den);
                    Assert::Fail(message, LINE_INFO());
                }
                catch (std::domain_error ex) {}
                catch (...) {
                    _swprintf(message, L"Incorrect exception for %l", max_den);
                    Assert::Fail(message, LINE_INFO());
                }
            }
        }
    };
}