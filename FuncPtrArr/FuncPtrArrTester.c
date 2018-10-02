#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PrimeJudging.h"

int GeneralSolution1(int k){
	int p = 4*k + 1;
	return p;
}


int GeneralSolution2(int k){
	int p = 8*k + 1;
	return p;
}


int GeneralSolution3(int k){
	int p = 8*k + 7;
	return p;
}


int GeneralSolution4(int k){
	int p = 8*k + 1;
	return p;
}


int GeneralSolution5(int k){
	int p = 8*k + 3;
	return p;
}


int GeneralSolution6(int k){
	int p = 12*k + 1;
	return p;
}


int GeneralSolution7(int k){
	int p = 12*k + 11;
	return p;
}


int GeneralSolution8(int k){
	int p = 6*k + 1;
	return p;
}

int (*solu_ptr[8])(int k) = {GeneralSolution1,
				GeneralSolution2,
				GeneralSolution3,
				GeneralSolution4,
				GeneralSolution5,
				GeneralSolution6,
				GeneralSolution7,
				GeneralSolution8};

int main(void){
	srand(time(NULL));
	int K = rand()/100000;
	int i = 0;
	int res[8] = {0};
	for (; i<8; i++) {
		if (isPrime(solu_ptr[i](K)))
			res[i] = 1;
		else
			res[i] = 0;
		printf("%d ", res[i]);
	}
	printf("\nK=%d\n", K);
	return 0;
}
