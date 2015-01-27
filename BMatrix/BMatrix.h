// BMatrix.h
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.3
//
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BMATRIX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BVECTOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BMATRIX_EXPORTS
#define BMATRIX_API __declspec(dllexport)
#else
#define BMATRIX_API __declspec(dllimport)
#endif

// This class is exported from the BMatrix.dll
#include <string>
#include <vector>
using namespace std;

class CBVector;

class BMATRIX_API CBMatrix {
	int n, m;
	vector <CBVector> colv;
public:
	// CBVector(void);
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

extern BMATRIX_API int nBMatrix;

BMATRIX_API int fnMatrix(void);
