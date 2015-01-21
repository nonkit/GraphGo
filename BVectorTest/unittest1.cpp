#include "stdafx.h"
#include "CppUnitTest.h"

#define DllImport __declspec( dllimport )

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BVectorTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			DllImport BVector bv(4, {0, 0, 1, 1});
			Assert::AreEqual(bv.abs(), 2);
		}

	};
}