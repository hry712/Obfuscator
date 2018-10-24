#ifndef _FUNCS_H_
#define _FUNCS_H_

void GenHyperIncrementalSeq(int* Result, int Len);
int SumOfSeq(int* Arr, int Len);
int GenK(int* SeqB, int Len);
int IsPrime(int Num);
int CalcLegendreFormula(int D, int P);
int GenPrimeP(int Key, int (*Solutions[])(int k), int SoluNum, int* PrimeRecord);
int Gen

// The following function declarations are the Congruence equation solutions, 
// which canbe modified flexiblely.

// The solution of Con Equ x^2=-1(mod p)
// p = 4*k + 1
int CongruenceEquationSolu1(int k){
	return 4*k + 1;
}

// The solution of Con Equ x^2=2(mod p)
// There are two general solutions for this equation: p = 8*k + 1, p = 8*k + 7
// Here is the first one
int CongruenceEquationSolu2(int k){
	return 8*k + 1;
}
// The following is the second one
int CongruenceEquationSolu3(int k){
	return 8*k + 7;
}

// The solution of Con Equ x^2=-2(mod p)
// There are two general solutions for this equation: p = 8*k + 1, p = 8*k + 3
// Here is the first one
int CongruenceEquationSolu4(int k){
	return 8*k + 1;
}
// The following is the second one
int CongruenceEquationSolu5(int k){
	return 8*k + 7;
}

// The solution of Con Equ x^2=3(mod p)
// There are two general solutions for this equation: p = 12*k + 1, p = 12*k + 11
// Here is the first one
int CongruenceEquationSolu6(int k){
	return 12*k + 1;
}
// The following is the second one
int CongruenceEquationSolu7(int k){
	return 12*k + 11;
}

// The solution of Con Equ x^2=-3(mod p)
// p = 6*k + 1
int CongruenceEquationSolu8(int k){
	return 6*k + 1;
}
#endif
