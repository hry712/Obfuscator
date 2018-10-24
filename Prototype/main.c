#include "funcs.c"

#define SoluNum 8

int main(void){
	int (*CongEquaSolus[SoluNum])(int k) = {CongruenceEquationSolu1,
				CongruenceEquationSolu2,
				CongruenceEquationSolu3,
				CongruenceEquationSolu4,
				CongruenceEquationSolu5,
				CongruenceEquationSolu6,
				CongruenceEquationSolu7,
				CongruenceEquationSolu8};
}
