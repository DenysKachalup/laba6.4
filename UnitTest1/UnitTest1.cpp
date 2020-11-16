#include "pch.h"
#include "CppUnitTest.h"
#include "../laba6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int q = 0;
			int a[6] = { -1,2,15,-20,25,0 };
			int t = DoMin(a, 6, 0, 0, q);//мінімальне значення
			Assert::AreEqual(t,-20);
		}
		TEST_METHOD(TestMethod2)
		{
			int q = 0;
			int a[6] = { -1,2,15,-20,25,0 };
			int min= DoMin(a, 6, 0, 0, q);
			int t = SumDoMin(a, 6, min, 0, 0, q);//сума до мінімального значення
			Assert::AreEqual(t, 16);
		}
		TEST_METHOD(TestMethod3)
		{
			

		}
	};
}
