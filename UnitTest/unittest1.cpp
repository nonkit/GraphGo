// Unit Test for GraphGo
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
/**
 * @author Nonki Takahashi
 * @version 0.6
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../binarymath/bvector.h"
#include "../binarymath/bmatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(BVector_a)
		{
			// TODO: Your test code here
			string expected("(0,0,1,1)");
			string expectedTeX("\\begin{pmatrix}0\\\\0\\\\1\\\\1\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.to_string());
			Assert::AreEqual(expectedTeX, a.to_TeX());
		}

		TEST_METHOD(BVector_b)
		{
			string expected("(0,1,0,1)");
			string expectedTeX("\\begin{pmatrix}0\\\\1\\\\0\\\\1\\end{pmatrix}");
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, b.to_string());
			Assert::AreEqual(expectedTeX, b.to_TeX());
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
			string expectedTeX("\\begin{pmatrix}0\\\\1\\\\1\\\\1\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.or(b).to_string());
			Assert::AreEqual(expectedTeX, a.or(b).to_TeX());
		}

		TEST_METHOD(BVector_and)
		{
			string expected("(0,0,0,1)");
			string expectedTeX("\\begin{pmatrix}0\\\\0\\\\0\\\\1\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.and(b).to_string());
			Assert::AreEqual(expectedTeX, a.and(b).to_TeX());
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
			string expectedTeX("\\begin{pmatrix}1\\\\1\\\\0\\\\0\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.inv().to_string());
			Assert::AreEqual(expectedTeX, a.inv().to_TeX());
		}

		TEST_METHOD(BVector_diff)
		{
			string expected("(0,0,1,0)");
			string expectedTeX("\\begin{pmatrix}0\\\\0\\\\1\\\\0\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.diff(b).to_string());
			Assert::AreEqual(expectedTeX, a.diff(b).to_TeX());
		}

		TEST_METHOD(BVector_xor)
		{
			string expected("(0,1,1,0)");
			string expectedTeX("\\begin{pmatrix}0\\\\1\\\\1\\\\0\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.xor(b).to_string());
			Assert::AreEqual(expectedTeX, a.xor(b).to_TeX());
		}

		TEST_METHOD(BVector_mul)
		{
			string expected("(0,0,0,0)");
			string expectedTeX("\\begin{pmatrix}0\\\\0\\\\0\\\\0\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			Assert::AreEqual(expected, a.mul(0).to_string());
			Assert::AreEqual(expectedTeX, a.mul(0).to_TeX());
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

		TEST_METHOD(BVector_cross)
		{
			string expected("0 0 0 0\n0 0 0 0\n0 1 0 1\n0 1 0 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 0\\\\0 & 0 & 0 & 0\\\\0 & 1 & 0 & 1\\\\0 & 1 & 0 & 1\\end{pmatrix}");
			CBVector a(4);
			a.setValue(3, 1);
			a.setValue(4, 1);
			int v[] = { 0, 1, 0, 1 };
			CBVector b(4, v);
			Assert::AreEqual(expected, a.cross(b).to_string());
			Assert::AreEqual(expectedTeX, a.cross(b).to_TeX());
		}

		TEST_METHOD(BMatrix_A)
		{
			string expected("0 0 0 1\n0 0 0 1\n0 0 0 1\n0 0 0 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 1\\\\0 & 0 & 0 & 1\\\\0 & 0 & 0 & 1\\\\0 & 0 & 0 & 1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			Assert::AreEqual(expected, A.to_string());
			Assert::AreEqual(expectedTeX, A.to_TeX());
		}

		TEST_METHOD(BMatrix_B)
		{
			string expected("0 0 0 1\n0 0 1 0\n0 1 0 0\n1 0 0 0\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 1\\\\0 & 0 & 1 & 0\\\\0 & 1 & 0 & 0\\\\1 & 0 & 0 & 0\\end{pmatrix}");
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, B.to_string());
			Assert::AreEqual(expectedTeX, B.to_TeX());
		}

		TEST_METHOD(BMatrix_getValue)
		{
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			Assert::AreEqual(0, A.getValue(4, 3));
		}

		TEST_METHOD(BMatrix_or)
		{
			string expected("0 0 0 1\n0 0 1 1\n0 1 0 1\n1 0 0 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 1\\\\0 & 0 & 1 & 1\\\\0 & 1 & 0 & 1\\\\1 & 0 & 0 & 1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, A.or(B).to_string());
			Assert::AreEqual(expectedTeX, A.or(B).to_TeX());
		}

		TEST_METHOD(BMatrix_and)
		{
			string expected("0 0 0 1\n0 0 0 0\n0 0 0 0\n0 0 0 0\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 1\\\\0 & 0 & 0 & 0\\\\0 & 0 & 0 & 0\\\\0 & 0 & 0 & 0\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, A.and(B).to_string());
			Assert::AreEqual(expectedTeX, A.and(B).to_TeX());
		}

		TEST_METHOD(BMatrix_abs)
		{
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			Assert::AreEqual(4, A.abs());
		}

		TEST_METHOD(BMatrix_inv)
		{
			string expected("1 1 1 0\n1 1 1 0\n1 1 1 0\n1 1 1 0\n");
			string expectedTeX("\\begin{pmatrix}1 & 1 & 1 & 0\\\\1 & 1 & 1 & 0\\\\1 & 1 & 1 & 0\\\\1 & 1 & 1 & 0\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			Assert::AreEqual(expected, A.inv().to_string());
			Assert::AreEqual(expectedTeX, A.inv().to_TeX());
		}

		TEST_METHOD(BMatrix_tran)
		{
			string expected("0 0 0 0\n0 0 0 0\n0 0 0 0\n1 1 1 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 0\\\\0 & 0 & 0 & 0\\\\0 & 0 & 0 & 0\\\\1 & 1 & 1 & 1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			Assert::AreEqual(expected, A.tran().to_string());
			Assert::AreEqual(expectedTeX, A.tran().to_TeX());
		}

		TEST_METHOD(BMatrix_diff)
		{
			string expected("0 0 0 0\n0 0 0 1\n0 0 0 1\n0 0 0 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 0\\\\0 & 0 & 0 & 1\\\\0 & 0 & 0 & 1\\\\0 & 0 & 0 & 1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, A.diff(B).to_string());
			Assert::AreEqual(expectedTeX, A.diff(B).to_TeX());
		}

		TEST_METHOD(BMatrix_xor)
		{
			string expected("0 0 0 0\n0 0 1 1\n0 1 0 1\n1 0 0 1\n");
			string expectedTeX("\\begin{pmatrix}0 & 0 & 0 & 0\\\\0 & 0 & 1 & 1\\\\0 & 1 & 0 & 1\\\\1 & 0 & 0 & 1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, A.xor(B).to_string());
			Assert::AreEqual(expectedTeX, A.xor(B).to_TeX());
		}

		TEST_METHOD(BMatrix_mul)
		{
			string expected("1 0 0 0\n1 0 0 0\n1 0 0 0\n1 0 0 0\n");
			string expectedTeX("\\begin{pmatrix}1 & 0 & 0 & 0\\\\1 & 0 & 0 & 0\\\\1 & 0 & 0 & 0\\\\1 & 0 & 0 & 0\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			CBMatrix B(4, 4);
			B.setValue(1, 4, 1);
			B.setValue(2, 3, 1);
			B.setValue(3, 2, 1);
			B.setValue(4, 1, 1);
			Assert::AreEqual(expected, A.mul(B).to_string());
			Assert::AreEqual(expectedTeX, A.mul(B).to_TeX());
		}

		TEST_METHOD(BMatrix_Ac)
		{
			string expected("(1,1,1,1)");
			string expectedTeX("\\begin{pmatrix}1\\\\1\\\\1\\\\1\\end{pmatrix}");
			CBMatrix A(4, 4);
			A.setValue(1, 4, 1);
			A.setValue(2, 4, 1);
			A.setValue(3, 4, 1);
			A.setValue(4, 4, 1);
			int v[] = { 0, 0, 1, 1 };
			CBVector c(4, v);
			Assert::AreEqual(expected, A.mul(c).to_string());
			Assert::AreEqual(expectedTeX, A.mul(c).to_TeX());
		}

	};
}