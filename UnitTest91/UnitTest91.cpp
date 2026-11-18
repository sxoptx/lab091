#include "pch.h"
#include "CppUnitTest.h"

#include "../lab9.1/var.cpp"
#include "../lab9.1/dod.cpp"
#include "../lab9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:
		// dod(): другий доданок ряду для x = 0.5 (перший доданок -0.5, n = 1)
		TEST_METHOD(TestDod)
		{
			nsVar::x = 0.5;
			nsVar::n = 1;
			nsVar::a = -0.5;
			nsDod::dod();
			Assert::AreEqual(0.125 / 3, nsVar::a, 1e-9);
		}

		// sum(): сума ряду порівнюється з точним значенням pi/2 - atan(x)
		TEST_METHOD(TestSum)
		{
			nsVar::x = 0.5;
			nsVar::e = 1e-6;
			nsSum::sum();
			Assert::AreEqual(acos(-1.) / 2 - atan(0.5), nsVar::s, 1e-5);
		}

		// sum(): при x = 0 сума дорівнює pi/2, виконується один крок циклу
		TEST_METHOD(TestSumZero)
		{
			nsVar::x = 0;
			nsVar::e = 1e-6;
			nsSum::sum();
			Assert::AreEqual(acos(-1.) / 2, nsVar::s, 1e-9);
			Assert::AreEqual(1, nsVar::n);
		}
	};
}