// BMatrix.cpp : Defines the exported functions for the DLL application.
// Binary Matrix Class - CBMatrix
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.1
//
/**
 * @author Nonki Takahashi
 * @version 0.1
 */

#include "stdafx.h"
#include "BMatrix.h"

// BVector.cpp : Defines the exported functions for the DLL application.

#include "stdafx.h"


// This is an example of an exported variable
BMATRIX_API int nBMatrix = 0;

// This is an example of an exported function.
BMATRIX_API int fnBMatrix(void)
{
	return 43;
}

// This is the constructor of a class that has been exported.
// see BVector.h for the class definition

/**
 * Constructor for CBMatrix class.
 * @param n number of rows of the matrix
 * @param m number of columns of the matrix
 * @since 0.1
 */
CBMatrix::CBMatrix(int n, int m)
{
	this->n = n;
	this->m = m;
	size = (n - 1) / 32 + 1;
	colv = new (int**)[m];
	for (int j = 0; j < m; j++)
		colv[j] = new (int*)[size];
	clear();
	return;
}
void CBMatrix::operator=(CBMatrix &)
{
}
void CBMatrix::clear(void)
{
}
void CBMatrix::setValue(int, int, int)
{
}
int CBMatrix::getValue(int, int)
{
}
int CBMatrix::abs(void)
{
}
CBMatrix CBMatrix::inv(void)
{
}
bool CBMatrix::equals(CBMatrix)
{
}
CBMatrix CBMatrix::tran(void)
{
}
CBMatrix CBMatrix::or(CBMatrix)
{
}
CBMatrix CBMatrix::diff(CBMatrix)
{
}
CBMatrix CBMatrix::and(CBMatrix)
{
}
CBMatrix CBMatrix::xor(CBMatrix)
{
}
CBMatrix CBMatrix::mul(CBMatrix)
{
}
string CBMatrix::toString(void)
{
}

