// BVector.cpp : Defines the exported functions for the DLL application.
// Binary Vector Class - CBVector
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.2
/**
 * @author Nonki Takahashi
 * @version 0.2
 */

#include "stdafx.h"
#include "BVector.h"
const int MAXMEM = 100;

// This is an example of an exported variable
BVECTOR_API int nBVector=0;

// This is an example of an exported function.
BVECTOR_API int fnBVector(void)
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
int *memory[MAXMEM];	// memories to be deleted later

/**
* Constructor for CBVector class.
* @since 0.2
*/
CBVector::CBVector(void)
{
	return;
}

/**
 * Constructor for CBVector class.
 * @param order order of the vector
 * @since 0.1
 */
CBVector::CBVector(int order, string name)
{
	this->name = name;
	this->order = order;
	size = (order - 1) / 32 + 1;
	bits = new int[size];
	clear();
	return;
}

/**
 * Constructor for CBVector class.
 * @param order order of the vector
 * @param value[] array of values
 * @since 0.1
 */
CBVector::CBVector(int order, int value[], string name)
{
	this->name = name;
	this->order = order;
	size = (order - 1) / 32 + 1;
	bits = new int[size];
	clear();
	for (int i = 0; i < order; i++)
			setValue(i + 1, value[i]);
	return;
}

/**
* Constructor for CBVector class.
* @param order order of the vector
* @param value[] array of values
* @since 0.1
*/
CBVector::~CBVector(void)
{
	if (bits != 0)
		for (int i = 0; i < MAXMEM; i++) {
			if (memory[i] == bits)
				break;
			if (memory[i] == 0) {
				memory[i] = bits;
				break;
			}
		}
	return;
}

/**
 * Copy operator for binary vectors
 * @param bv source bianary vector
 * @since 0.1
 */
void CBVector::operator=(CBVector &bv)
{
	if (this == &bv)
		return;
	order = bv.order;
	if (*bv.bits != 0) {
		size = (order - 1) / 32 + 1;
		if (bits != 0)
			delete[] bits;
		bits = new int[size];
		for (int i = 0; i < size; i++)
			bits[i] = bv.bits[i];
	}
	return;
}

/**
 * Clear binary vector
 * @since 0.1
 */
void CBVector::clear(void)
{
    for (int i = 0; i < size; i++)
		bits[i] = 0;
	return;
}

/**
 * Set value 0 or 1 to element i of binary vector object
 * @param i element number (1 origin)
 * @param value value to set
 * @since 0.2
 */
void CBVector::setValue(int i, int value)
{
	// reminder of 32
	int i1 = (i - 1) & 0x1F;
	// quotient of 32
	int i2 = (i - 1) >> 5;
	if (value == 0)
		this->bits[i2] &= ~mask[i1];
	else
		this->bits[i2] |= mask[i1];
	return;
}

/**
 * Get element i of binary vector
 * @param i element number (1 origin)
 * @return value
 * @since 0.2
 */
int CBVector::getValue(int i)
{
	// (i - 1) & 0x1F means remainder of 32
	// (i - 1) >> 5@means quotent of 32
	return (bits[(i - 1) >> 5] & mask[(i - 1) & 0x1F]) ? 1 : 0;
}

/**
 * Count elements that values are 1 in binary vector
 * @return number of 1 elements
 * @since 0.1
 */
int CBVector::abs(void)
{
	int n = 0;
	for (int i = 0; i < order; i++)
		if (getValue(i) == 1)
			n++;
	return n;
}

/**
 * Returns inverted binary vector
 * @return inverted binary vector
 * @since 0.1
 */
CBVector CBVector::inv(void)
{
	CBVector bv(order, "inv");
	// remainder
	int m1 = (order - 1) % 32;
	int mask1 = mask[m1];
	for (int mask2 = 0; mask1 != 0; mask1 <<= 1) {
		mask2 |= mask1;
		int i = 0;
		for (; i < size - 1; i++)
			bv.bits[i] = ~bits[i];
		bv.bits[i] = ~bits[i] & mask2;
	}
	return bv;
}

/**
 * Returns true if two vectors are equal.  Returns false if error or different.
 * @param bv2 comparison target binary vector
 * @return returns true if two vectors are equal
 * @since 0.1
 */
bool CBVector::equals(CBVector bv2)
{
	if (order != bv2.order) {
		// different order
		return false;
	}
	for (int i = 0; i < order; i++)
		if (bits[i] != bv2.bits[i]) {
			// different value
			return false;
		}
	return true;
}

/**
 * Logical or with binary vector object bv2
 * @param bv2 second operand for logical or
 * @return logical or with bv2 (or 0 if error)
 * @since 0.1
 */
CBVector CBVector::or(CBVector bv2)
{
	if (order != bv2.order)
		return 0;
	CBVector bv(order, "or");
	bv = *this;
	for (int i = 0; i < size; i++)
		bv.bits[i] |= bv2.bits[i];
	return bv;
}
								
/**
 * Logical and with binary vector object bv2
 * @param bv2 second operand for logical and
 * @return logical and with bv2 (or 0 if error)
 * @since 0.1
 */
CBVector CBVector::and(CBVector bv2)
{
	if (order != bv2.order)
		return 0;
	CBVector bv(order, "and");
	bv = *this;
	for (int i = 0; i < size; i++)
		bv.bits[i] &= bv2.bits[i];
	return bv;
}
									
/**
 * Logical difference with binary vector object bv2
 * @param bv2 second operand for logical difference
 * @return logical difference with bv2 (or 0 if error)
 * @since 0.1
 */
CBVector CBVector::diff(CBVector bv2)
{
	if (order != bv2.order)
		return 0;
	CBVector bv(order, "diff");
	bv = *this;
	for (int i = 0; i < size; i++)
		bv.bits[i] &= ~bv2.bits[i];
    return bv;
}
										
/**
 * Exclusive or with binary vector object bv2
 * @param bv2 second operand for exclusive or
 * @return exclusive or with bv2 (or 0 if error)
 * @since 0.1
 */
CBVector CBVector::xor(CBVector bv2)
{
	if (order != bv2.order)
		return 0;
	CBVector bv(order, "xor");
	bv = *this;
	for (int i = 0; i < size; i++)
		bv.bits[i] ^= bv2.bits[i];
    return bv;
}

/**
 * Product with scalar (0 or 1)
 * @param b2 second operand for product
 * @return product with b2 (or 0 if error)
 * @since 0.1
 */
CBVector CBVector::mul(int b2)
{
	if (b2 != 0 && b2 != 1)
		return 0;
	CBVector bv(order, "mul");
	if (b2 == 0) {
		// 0 vector
		return bv;
	}
	else {
		bv = *this;
		return bv;
	}
}

/**
 * Dot product with binary vector object bv2
 * @param bv2 second operand for dot product
 * @return dot product with bv2 (or -1 if error)
 * @since 0.1
 */
int CBVector::dot(CBVector bv2)
{
	if (order != bv2.order)
		return -1;
	int b = 0;
	for (int i = 0; i < order; i++)
		b |= (getValue(i + 1) & bv2.getValue(i + 1));
	return b;
}

/**
 * Convert binary vector object to string
 * @return string e.g. "(0,1,...,1)"
 * @since 0.1
 */
string CBVector::toString(void)
{
	string str("(");
	for (int i = 0; i < order; i++) {
		str += to_string(getValue(i + 1));
		if (i < order - 1)
			str += ",";
	}
	str += ")";
	return str;
}

/**
 * Release memories for bits
 * @since 0.2
 */
void CBVector::releaseMem(void)
{
	for (int i = 0; i < MAXMEM; i++)
		if (memory[i] != 0)
			delete[] memory[i];
	return;
}
