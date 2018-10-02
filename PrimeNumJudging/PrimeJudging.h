#ifndef __ISPRIME_H__
#define __ISPRIME_H__

#include <math.h>

int isPrime(int num){
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

#endif
