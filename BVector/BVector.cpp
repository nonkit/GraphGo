// BVector.cpp : Defines the exported functions for the DLL application.
// Binary Vector Class - CBVector
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.3
/**
 * @author Nonki Takahashi
 * @version 0.3
 */

#include "stdafx.h"
#include "BVector.h"
#include <iostream>

// This is an example of an exported variable
BVECTOR_API int nBVector=0;

// This is an example of an exported function.
BVECTOR_API int fnBVector(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see BVector.h for the class definition
int mask[MAXBITS] = {
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
	if (MAXBITS < order) {
		cerr << "CBVector: order too large." << endl;
		return;
	}
	this->order = order;
	this->name = name;
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
	if (MAXBITS < order) {
		cerr << "CBVector: order too large." << endl;
		return;
	}
	this->order = order;
	this->name = name;
	for (int i = 0; i < order; i++)
			setValue(i + 1, value[i]);
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
	bits = bv.bits;
	return;
}

/**
 * Clear binary vector
 * @since 0.1
 */
void CBVector::clear(void)
{
	bits.reset();
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
	if (i < 1 || MAXBITS < i) {
		cerr << "CBVector::setValue: i is smaller than 1 or larger than" << std::to_string(MAXBITS) << "." << endl;
		return;
	}
	if (value == 0)
		bits.reset(i - 1);
	else
		bits.set(i - 1);
	return;
}

/**
 * Get element i of binary vector
 * @param i element number (1 origin)
 * @return value (-1 if error)
 * @since 0.2
 */
int CBVector::getValue(int i)
{
	if (i < 1 || MAXBITS < i) {
		cerr << "CBVector::getValue: i is smaller than 1 or larger than" << std::to_string(MAXBITS) << "." << endl;
		return -1;
	}
	return bits.test(i - 1) ? 1 : 0;
}

/**
* Get order of binary vector
* @return order
* @since 0.2
*/
int CBVector::getOrder(void)
{
	return order;
}

/**
 * Count elements that values are 1 in binary vector
 * @return number of 1 elements
 * @since 0.1
 */
int CBVector::abs(void)
{
	return bits.count();
}

/**
 * Returns inverted binary vector
 * @return inverted binary vector
 * @since 0.1
 */
CBVector CBVector::inv(void)
{
	CBVector bv(order);
	bv.bits = bits.flip();
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
	if (bits != bv2.bits) {
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
	bv.bits |= bv2.bits;
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
	bv.bits &= bv2.bits;
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
	bv.bits &= ~bv2.bits;
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
	bv.bits ^= bv2.bits;
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
 * @since 0.3
 */
string CBVector::to_string(void)
{
	string str("(");
	for (int i = 0; i < order; i++) {
		str += std::to_string(getValue(i + 1));
		if (i < order - 1)
			str += ",";
	}
	str += ")";
	return str;
}
