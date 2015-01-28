// bmatrix.h
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.4
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
#include <vector>
using namespace std;

class CBVector;

class BINARYMATH_API CBMatrix {
	int n, m;
	vector <CBVector> colv;
public:
	// CBMatrix(void);
	// TODO: add your methods here.
	CBMatrix(int, int);
	void operator=(CBMatrix &);
	void clear(void);
	void setValue(int, int, int);
	int getValue(int, int);
	int abs(void);
	CBMatrix inv(void);
	bool equals(CBMatrix);
	CBVector row(int);
	CBVector tran1(void);
	CBMatrix tran(void);
	CBMatrix or(CBMatrix);
	CBMatrix diff(CBMatrix);
	CBMatrix and(CBMatrix);
	CBMatrix xor(CBMatrix);
	CBMatrix mul(CBMatrix);
	CBVector mul(CBVector);
	string to_string(void);
};
