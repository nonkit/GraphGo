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
	int order;
	int *bits;
public:
	CBVector(void);
	// TODO: add your methods here.
	CBVector(int);
	CBVector(int, int[]);
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
	CBVector dot(CBVector);
	string toString(void);
};

extern BVECTOR_API int nBVector;

BVECTOR_API int fnBVector(void);
