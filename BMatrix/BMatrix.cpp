// BMatrix.cpp : Defines the exported functions for the DLL application.
// Binary Matrix Class - CBMatrix
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.2
//
/**
 * @author Nonki Takahashi
 * @version 0.2
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
	CBVector bv(n, "0");
	for (int j = 0; j < m; j++)
		colv.push_back(bv);
	return;
}

/**
* Copy operator for binary matrix
* @param bm source bianary matrix
* @since 0.2
*/
void CBMatrix::operator=(CBMatrix &bm)
{
	if (this == &bm)
		return;
	n = bm.n;
	m = bm.m;
	if (!bm.colv.empty()) {
		colv.clear();
		for (int j = 0; j < m; j++)
			colv.push_back(bm.colv[j]);
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
 * Returns transposed binary vector
 * @return transposed binary vector
 * @since 0.1
 */
CBVector CBMatrix::row(int i)
{
	if (i < 1 || n < i)
		return 0;
	CBVector bv(m);
	for (int j = 0; j < m; j++)
		bv.setValue(j + 1, getValue(i, j + 1));
	return bv;
}

/**
 * Returns transposed binary vector
 * @return transposed binary vector
 * @since 0.1
 */
CBVector CBMatrix::tran1(void)
{
	return row(1);
}

/**
 * Returns transposed binary matrix
 * @param binary matrix
 * @return transposed binary matrix
 * @since 0.1
 */
CBMatrix CBMatrix::tran(void)
{
	CBMatrix bm(m, n);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			bm.setValue(j + 1, i + 1, getValue(i + 1, j + 1));
	return bm;
}

/**
 * Logical or with binary matrix object bm2
 * @param bm2 second operand for logical or
 * @return logical or with bm2 (or 0 if error)
 * @since 0.1
 */
CBMatrix CBMatrix::or(CBMatrix bm2)
{
	if (n != bm2.n || m != bm2.m)
		return *this;	// TODO return 0
	CBMatrix bm(n, m);
	for (int j = 0; j < m; j++)
		bm.colv[j] = colv[j].or(bm2.colv[j]);
	return bm;
}

/**
* Logical difference with binary matrix object bm2
* @param bm2 second operand for logical difference
* @return logical difference with bm2 (or 0 if error)
* @since 0.1
*/
CBMatrix CBMatrix::diff(CBMatrix bm2)
{
	if (n != bm2.n || m != bm2.m)
		return *this;	// TODO return 0;
	CBMatrix bm(n, m);
	for (int j = 0; j < m; j++)
		bm.colv[j] = colv[j].diff(bm2.colv[j]);
	return bm;
}

/**
* Logical and with binary matrix object bm2
* @param bm2 second operand for logical and
* @return logical and with bm2 (or 0 if error)
* @since 0.1
*/
CBMatrix CBMatrix::and(CBMatrix bm2)
{
	if (n != bm2.n || m != bm2.m)
		return *this;	// TODO return 0;
	CBMatrix bm(n, m);
	for (int j = 0; j < m; j++)
		bm.colv[j] = colv[j].and(bm2.colv[j]);
	return bm;
}

/**
* Logical xor with binary matrix object bm2
* @param bm2 second operand for logical xor
* @return logical xor with bm2 (or 0 if error)
* @since 0.1
*/
CBMatrix CBMatrix::xor(CBMatrix bm2)
{
	if (n != bm2.n || m != bm2.m)
		return *this;	// TODO return 0;
	CBMatrix bm(n, m);
	for (int j = 0; j < m; j++)
		bm.colv[j] = colv[j].xor(bm2.colv[j]);
	return bm;
}

/**
 * Product with binary matrix object bm2
 * @param bm2 second operand for product
 * @return product with bm2 (or 0 if error)
 * @since 0.1
 */
CBMatrix CBMatrix::mul(CBMatrix bm2)
{
	if (m != bm2.n)
		return *this;	// TODO return 0;
	CBMatrix bm(n, bm2.m);
	for (int j = 0; j < bm2.m; j++)
		for (int i = 0; i < n; i++)
			bm.setValue(i + 1, j + 1, row(i + 1).dot(bm2.colv[j]));
	return bm;
}

/**
* Product with binary vector object bv2
* @param bv2 second operand for product
* @return product with bv2 (or 0 if error)
* @since 0.1
*/
CBVector CBMatrix::mul(CBVector bv2)
{
	if (m != bv2.getOrder())
		return 0;
	CBVector bv(m);
	for (int j = 0; j < m; j++)
		bv.setValue(j + 1, row(j + 1).dot(bv2));
	return bv;
}

/**
* Logical difference with binary matrix object bm2
* @param bm2 second operand for logical difference
* @return logical difference with bm2 (or 0 if error)
* @since 0.1
*/
string CBMatrix::to_string(void)
{
	string str("");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			str += std::to_string(getValue(i, j));
			if (j < m)
				str += " ";
		}
		str = str + "\n";
	}
	return str;
}

