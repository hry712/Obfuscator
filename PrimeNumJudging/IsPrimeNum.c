#include <stdio.h>
#include <math.h>

int isPrimeNum(int num){
	int range = floor(sqrt((float)num));
	if (num == 1)
		return 0;
	else if (num == 2|| num == 3)
		return 1;
	else if (num%6 != 1 && num%6 != 5)
		return 0;
	else {
		for (int i=5; i<=range; i+=6)
			if ((num%i) ==0 || (num%(i+2)) == 0)
				return 0;
		return 1;
	}
}

int main(void){
	if (isPrimeNum(37))
		printf("37 is prime.\n");
	else
		printf("37 is not prime.\n");
	return 0;
}
