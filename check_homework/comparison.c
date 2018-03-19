//
// Created by 张震宇 on 19/03/2018.
//
#include "comparison.h"
#include <stdio.h>
#include <stdlib.h>

FILE *open_standard();
FILE **open_outputs();
/**
 * compare students' program's output with standard output,and compute difference by line
 * @param standard
 * @param output
 * @return number of different lines
 */
int compare(FILE * standard,FILE * output);

void comparison() {
	printf("comparison run.\n");
	//open files
	FILE *standard = open_standard();
	FILE **outputs = open_outputs();
	printf("comparison run completely.\n");
}

FILE *open_standard() {
	FILE *output;
	if ((output = fopen(url_output_standard, "r")) == NULL) //open output failed
	{
		printf("error: Standard output file cannot be opened.\n");
		exit(1);//end program
	}
	return output;
}

FILE ** open_outputs() {
	FILE *outputs;
	FILE *list = fopen(url_output_list, "r");
	char a[15];
	int tag = 0;
	while (fgets(a, 15, list)) {//get number from list, end with "\n"
		printf("%s", a);
	}

	return outputs;
}