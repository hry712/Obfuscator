#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funcs.h"

// Generate a hyper incremental sequence.
// Param-Result: store the final sequance content
// Param-Len: the length of the Result buffer
// Return-Void
void GenHyperIncrementalSeq(int* Result, int Len){
	int factor = 0;
	int i = 1;
	int sum = Result[0];
	while (i<Len){
		while ((Result[i-1] + (2<<factor)) <= sum)
			factor += 1;
		Result[i] = Result[i-1] + (2<<factor);
		sum += Result[i++];
	}
}

// Caculate the summary of an integer sequance.
// Param-Arr: the integer number array
// Param-Len: the length of the array
// Return-Int: the sum of the integer sequence
int SumOfSeq(int* Arr, int Len){
	int sum = 0;
	int i = 0;
	while (i<Len){
		sum += Arr[i];
		++i;
	}
	return sum;
}

// Generate a K value which participates a later comparison
// The method is each two elements form a group then choose
// one element in each groups as an addend to calculate a
// summary as the final result i.e. K value.
// Param-SeqB: an integer source array which provides raw 
// 		materials for K
// Param-Len: the length of sequence B
// Return-Int: return the expected K value
int GenK(int* SeqB, int Len){
	int i = 0;
	int sum = 0;
	int ran;
	for (; i<Len; i+=2){
		srand(time(NULL));
		ran = rand();
		if (ran%2)
			sum += SeqB[i];
		else
			sum += SeqB[i+1];
	}
	return sum;
}

// Judge whether a number is prime
// Param-Num: the num which is going to be judged
// Return-Int: if the Num is prime then return 1 or else 0
int IsPrime(int Num){
	int range = floor(sqrt((float)Num));
	int i;
	if (1 == Num)
		return 0;
	else if (2 == Num || 3 == Num)
		return 1;
	else if (1 != Num%6 && 5 != Num%6)
		return 0;
	else {
		for (i = 5; i<=range; i += 6)
			if (0 == (Num%i) || 0 == (Num%(i+2)))
				return 0;
		return 1;
	}
}

// Caculate Legendre formula L(D, P)
// Param-D: the numerator in Legendre formula
// Param-P: the denominator in Legendre formula
// Return-Int: the value of L(D, P)
int CalcLegendreFormula(int D, int P){
	if (1 == D)
		return 1;
	else if (0 == D%P)
		return 0;
	else if (-1 == D) {
		if (((P-1)/2)%2)
			return -1;
		else
			return 1;
	} else if (0 == D%2)
		return (((P*P-1)/8)%2)?(-1)*CalcLegendreFormula(D/2, P):CalcLegendreFormula(D/2, P);
	else
		return (((D-1)*(P-1)/4)%2)?(-1)*CalcLegendreFormula((P%D+D)%D, D):CalcLegendreFormula((P%D+D)%D, D);
}

// Substitute a Key value into different congruence equation solutions 
// then each solutions can calculate a P value. Finally if a P value is
// prime, it will be recorded in an array and one of them will be used
// in the following calculation.
// Param-Key: Key is generated randomly by the outside code and it must be
// 		a positive integer
// Param-Solutions: this array contains some congruence equation solution
// 		formula
// Param-PrimeRecord: this array will store the prime P value in it
// Return-Int: the number of the prime P
int GenPrimeP(int Key, int (*Solutions[])(int k), int SoluNum, int* PrimeRecord){
	int count = 0;
	int i = 0;
	int p = 0;
	for (; i<SoluNum; i++){
		p = Solutions[i](Key);
		if (IsPrime(p))
			PrimeRecord[count++] = p;
	}
	return count+1;
}
