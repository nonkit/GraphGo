// RegressionTest.cpp : Defines the entry point for the console application.
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.5
//
/**
 * @author Nonki Takahashi
 * @version 0.5
 */

#include "stdafx.h"
#include <iostream>
#include "../binarymath/bvector.h"
#include "../binarymath/bmatrix.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CBVector a(4, "a");
	a.setValue(3, 1);
	a.setValue(4, 1);
	cout << "a=" << a.to_string() << endl;
	int v[] = { 0, 1, 0, 1 };
	CBVector b(4, v, "b");
	cout << "b=" << b.to_string() << endl;
	cout << "a.getValue(3)=" << to_string(a.getValue(3)) << endl;
	cout << "a.or(b)=" << a.or(b).to_string() << endl;
	cout << "a.and(b)=" << a.and(b).to_string() << endl;
	cout << "a.abs()=" << to_string(a.abs()) << endl;
	cout << "a.inv()=" << a.inv().to_string() << endl;
	cout << "a.diff(b)=" << a.diff(b).to_string() << endl;
	cout << "a.xor(b)=" << a.xor(b).to_string() << endl;
	cout << "a.mul(0)=" << a.mul(0).to_string() << endl;
	cout << "a.dot(b)=" << to_string(a.dot(b)) << endl;
	cout << "a.cross(b)=" << endl << a.cross(b).to_string() << endl;
	cout << endl;

	CBMatrix A(4, 4);
	A.setValue(1, 4, 1);
	A.setValue(2, 4, 1);
	A.setValue(3, 4, 1);
	A.setValue(4, 4, 1);
	cout << "A=" << endl << A.to_string() << endl;
	CBMatrix B(4, 4);
	B.setValue(1, 4, 1);
	B.setValue(2, 3, 1);
	B.setValue(3, 2, 1);
	B.setValue(4, 1, 1);
	cout << "B=" << endl << B.to_string() << endl;
	cout << "A.getValue(4, 3)=" << to_string(A.getValue(4, 3)) << endl;
	cout << "A.or(B)=" << endl << A.or(B).to_string() << endl;
	cout << "A.and(B)=" << endl << A.and(B).to_string() << endl;
	cout << "A.abs()=" << to_string(A.abs()) << endl;
	cout << "A.inv()=" << endl << A.inv().to_string() << endl;
	cout << "A.tran()=" << endl << A.tran().to_string() << endl;
	cout << "A.diff(B)=" << endl << A.diff(B).to_string() << endl;
	cout << "A.xor(B)=" << endl << A.xor(B).to_string() << endl;
	cout << "A.mul(B)=" << endl << A.mul(B).to_string() << endl;
	int v2[] = { 0, 0, 1, 1 };
	CBVector c(4, v2, "c");
	cout << "c=" << c.to_string() << endl;
	cout << "A.mul(c)=" << A.mul(c).to_string() << endl;
	cout << endl;
	system("pause");
	return 0;
}

