// bvector.h
// Copyright (c) 2015-2016 Nonki Takahashi.  The MIT License.
// Version 0.6
//
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BINARYMATH_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BINARYMATH_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BINARYMATH_EXPORTS
#define BINARYMATH_API __declspec(dllexport)
#else
#define BINARYMATH_API __declspec(dllimport)
#endif

// This class is exported from the binarymath.dll
#include <string>
#include <bitset>
using namespace std;
const int MAXBITS = 32;

class CBMatrix;

class BINARYMATH_API CBVector {
	int order = 0;
	bitset<MAXBITS> bits;
	string name = "";
public:
	CBVector(void);
	// TODO: add your methods here.
	CBVector(int, string name = "");
	CBVector(int, int[], string name = "");
	void operator=(CBVector &);
	void clear(void);
	void setValue(int, int);
	int getValue(int);
	int getOrder(void);
	int abs(void);
	CBVector inv(void);
	CBMatrix tran(void);
	bool equals(CBVector);
	CBVector or(CBVector);
	CBVector diff(CBVector);
	CBVector and(CBVector);
	CBVector xor(CBVector);
	CBVector mul(int);
	int dot(CBVector);
	CBMatrix cross(CBVector);
	string to_string(void);
	string to_TeX(void);
};
