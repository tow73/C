#include <stdio.h>
int main(void)
{
	char c = 'A';
	int n = 100;
	double d = 3.14;
	char* pC;
	int* pN;
	double* pD;
	pC = &c;
	pN = &n;
	pD = &d;
	// c: _____________ pC:__________________ *pC________________
	// n: _____________ pN:__________________ *pN________________
	// d: _____________ pD:__________________ *pD________________
	*pC = 'Z';
	*pN = 199;
	*pD = 3.1415;
	pC++;
	pN++;
	pD++;
	// pC: ______________ pN:___________________ pD:_________________
	pC = pC + 2;
	pN = pN + 2;
	pD = pD + 2;
	// pC: ______________ pN:___________________ pD:_________________
}