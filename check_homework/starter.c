#include <stdio.h>
#include "runEXE.h"
#include "comparison.h"

void starter() {
	printf("starter run.\n");
	runEXE();
	comparison();
	printf("starter run completely.\n");
}

int main() {
	starter();
	return 0;
}
