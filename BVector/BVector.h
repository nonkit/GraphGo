// BVector.h
// Copyright (c) 2015 Nonki Takahashi.  The MIT License.
// Version 0.2
//
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BVECTOR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BVECTOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BVECTOR_EXPORTS
#define BVECTOR_API __declspec(dllexport)
#else
#define BVECTOR_API __declspec(dllimport)
#endif

// This class is exported from the BVector.dll
#include <string>
using namespace std;

class BVECTOR_API CBVector {
	int order = 0;
	int size = 0;
	int* bits = 0;
	string name = "";
public:
	CBVector(void);
	// TODO: add your methods here.
	CBVector(int, string name = "");
	CBVector(int, int[], string name = "");
	~CBVector(void);
	void operator=(CBVector &);
	void clear(void);
	void setValue(int, int);
	int getValue(int);
	int abs(void);
	CBVector inv(void);
	bool equals(CBVector);
	CBVector or(CBVector);
	CBVector diff(CBVector);
	CBVector and(CBVector);
	CBVector xor(CBVector);
	CBVector mul(int);
	int dot(CBVector);
	string toString(void);
	static void releaseMem(void);
};

extern BVECTOR_API int nBVector;

BVECTOR_API int fnBVector(void);
