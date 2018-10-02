#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	int factor = 0;
	int sum = 0;
	int arr[10] = {0};
	arr[0] = time(NULL)%10;
	sum = arr[0];
	printf("%d ", arr[0]);
	int i = 1;
	while (i<10){	
		while((arr[i-1]+(2<<factor))<=sum)
			factor += 1;
		arr[i] = arr[i-1] + (2<<factor);
		sum += arr[i];
		printf("%d ", arr[i]);
		++i;
	}
	printf("\n");
}
