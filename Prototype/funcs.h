#ifndef _FUNCS_H_
#define _FUNCS_H_

void GenHyperIncrementalSeq(int* Result, int Len);
int SumOfSeq(int* Arr, int Len);
void GenPackageSeq(int* Remainders, int Len, int Divisor, int* Result);
int GenK(int* SeqB, int Len);
int IsPrime(int Num);
int CalcLegendreFormula(int D, int P);
int GenPrimeP(int Key, int (*Solutions[])(int k), int SoluNum, int* PrimeRecord);
void GenZeroOneString(int* Remainders, int Len, int P, int* ResultStr);
int CalcLeftCmpEle(int* Seq, int Len);
int CalcRightCmpEle(int* Seq, int Len, int* ZeroOneStr);


int CongruenceEquationSolu1(int k);
int CongruenceEquationSolu2(int k);
int CongruenceEquationSolu3(int k);
int CongruenceEquationSolu4(int k);
int CongruenceEquationSolu5(int k);
int CongruenceEquationSolu6(int k);
int CongruenceEquationSolu7(int k);
int CongruenceEquationSolu8(int k);
#endif
