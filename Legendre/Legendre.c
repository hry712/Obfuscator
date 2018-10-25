#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrimeJudging.h"

static int factors[10];

int factoring(int num){
	memset(factors, -1, sizeof(int)*10);
	int len = 0;
	int num2 = num;
	int i = 2;
	if (num < 2)
		return -1;
	else {
		for (; i*i <= num2; i++){
			while (num2%i == 0){
				num2 /= i;
				factors[len++] = i;
			}
		}
		if (num2 != 1)
			factors[len++] = num2;
	}	
	return len;
}

int legendre(int d, int p){
	if (1 == d)
		return 1;
	else if (0==d%p)
		return 0;
	else if (-1 == d){
		if (((p-1)/2)%2)
			return -1;
		else
			return 1;
	} else if (0 == d%2)
		return (((p*p -1)/8)%2)?-1*legendre(d/2, p):legendre(d/2, p);
	else
		return (((d-1)*(p-1)/4)%2)?-1*legendre((p%d+d)%d, d):legendre((p%d+d)%d, d);
}

int legendre2(int d, int p){
	if (d>=p || d<0)
		return legendre2((d%p+p)%p, p);
	else if (d==0 || d==1)
		return d;
	else if (d == 2)
		if ((-1 == p%8) || (1 == p%8))
			return 1;
		else
			return -1;
	else if (d == p-1)
		if (1 == p%4)
			return 1;
		else
			return -1;
	else if (!isPrime(d)){
		int pn = factoring(d);
		int i = 0;
		int res = 1;
		for (; i<pn; i++)
			res *= legendre2(factors[i], p);
		return res;
	} else {
		if ((0 == (p-1)/2%2) || (0 == (d-1)/2%2))
			return legendre2(p, d);
		else
			return -1*legendre2(p, d);
	}
}

int main(void){
	int bittable[3][2] = {{0, 0},		// no solution
				{0, 1},		// one solution
				{1, 0}};	// multiple solutions
	int tmp = 0;
	tmp = legendre(-1, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	tmp = legendre(2, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	tmp = legendre(-2, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	tmp = legendre(3, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	tmp = legendre(-3, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	printf("\n%d\n",(((-3-1)*(17-1)/4)%2));
	tmp = legendre(-3, 17);
	printf("%d %d ", bittable[tmp+1][0], bittable[tmp+1][1]);
	printf("\n");

	return 0;
}
