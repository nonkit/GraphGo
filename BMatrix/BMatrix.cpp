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
	return 42;
}

// This is the constructor of a class that has been exported.
// see BVector.h for the class definition
int mask[32] = {
	0x80000000, 0x40000000, 0x20000000, 0x10000000,
	0x08000000, 0x04000000, 0x02000000, 0x01000000,
	0x00800000, 0x00400000, 0x00200000, 0x00100000,
	0x00080000, 0x00040000, 0x00020000, 0x00010000,
	0x00008000, 0x00004000, 0x00002000, 0x00001000,
	0x00000800, 0x00000400, 0x00000200, 0x00000100,
	0x00000080, 0x00000040, 0x00000020, 0x00000010,
	0x00000008, 0x00000004, 0x00000002, 0x00000001
};

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
	colv = new CBVector[size];
	CBVector bv(n);
	for (int j = 0; j < m; j++)
		colv[j] = bv;
	return;
}

/**
* Copy operator for binary matrix
* @param bm source bianary matrix
* @since 0.1
*/
void CBMatrix::operator!=(CBMatrix &bm)
{
	if (this == &bm)
		return;
	n = bm.n;
	m = bm.m;
	if (bm.colv != 0) {
		size = (n - 1) / 32 + 1;
		delete[] colv;
		colv = new CBVector[size];
		for (int j = 0; j < m; j++)
			colv[j] = bm.colv[j];
	}
	return;
}

/**
* Clear binary matrix
* @since 0.1
*/
void CBMatrix::clear(void)
{
	for (int j = 0; j < m; j++)
		colv[j].clear();
	return;
}

/**
* Set value 0 or 1 to element i, j of binary matrix object
* @param i element row number (1 origin)
* @param j element column number (1 origin)
* @param value value to set
* @since 0.1
*/
void CBMatrix::setValue(int i, int j, int value)
{
	this->colv[j - 1].setValue(i, value);
	return;
}

/**
* Get value of element i, j in binary matrix object
* @param i element row number (1 origin)
* @param j element column number (1 origin)
* @return got value
* @since 0.1
*/
int CBMatrix::getValue(int i, int j)
{
	return colv[j - 1].getValue(i);
}

/**
* Count elements that values are 1 in binary matrix
* @return number of 1 elements
* @since 0.1
*/
int CBMatrix::abs(void)
{
	int n = 0;
	for (int j = 0; j < m; j++)
		n += colv[j].abs();
	return n;
}

/**
* Returns inverted binary matrix
* @return inverted binary matrix
* @since 0.1
*/
CBMatrix CBMatrix::inv(void)
{
	CBMatrix bm(n, m);
	for (int j = 0; j < m; j++)
		bm.colv[j] = colv[j].inv();
	return bm;
}

/**
* Returns true if two matrixes are equal.  Returns false if error or different.
* @param bm2 comparison target binary matrix
* @return returns true if two matrixes are equal
* @since 0.1
*/
bool CBMatrix::equals(CBMatrix bm2)
{
	if (n != bm2.n || m != bm2.m) {
		// different dimension
		return false;
	}
	for (int j = 0; j < m; j++)
		if (!colv[j].equals(bm2.colv[j])) {
			// different column value
			return false;
		}
	return true;
}
/**
 * Returns transposed binary matrix
 * @param binary matrix
 * @return transposed binary matrix
 * @since 0.1
 */
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

