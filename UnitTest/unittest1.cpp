// Unit Test for GraphGo
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
/**
 * @author Nonki Takahashi
 * @version 0.1
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../BVector/BVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			CBVector::releaseMem();
			Logger::WriteMessage("Momory released.");
		}

		TEST_METHOD(BVector_a)
		{
			// TODO: Your test code here
			string expected("(0,0,1,1)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.toString());
		}

		TEST_METHOD(BVector_b)
		{
			string expected("(0,1,0,1)");
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, b.toString());
		}

		TEST_METHOD(BVector_getValue)
		{
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(1, a.getValue(3));
		}

		TEST_METHOD(BVector_or)
		{
			string expected("(0,1,1,1)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.or(b).toString());
		}

		TEST_METHOD(BVector_and)
		{
			string expected("(0,0,0,1)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.and(b).toString());
		}

		TEST_METHOD(BVector_abs)
		{
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(2, a.abs());
		}

		TEST_METHOD(BVector_inv)
		{
			string expected("(1,1,0,0)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.inv().toString());
		}

		TEST_METHOD(BVector_diff)
		{
			string expected("(0,0,1,0)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.diff(b).toString());
		}

		TEST_METHOD(BVector_xor)
		{
			string expected("(0,1,1,0)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.xor(b).toString());
		}

		TEST_METHOD(BVector_mul)
		{
			string expected("(0,0,0,0)");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.mul(0).toString());
		}

		TEST_METHOD(BVector_dot)
		{
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(1, a.dot(b));
		}

	};
}