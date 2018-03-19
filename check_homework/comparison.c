//
// Created by 张震宇 on 19/03/2018.
//
#include "comparison.h"
#include <stdio.h>
#include <stdlib.h>

FILE *open_standard();
FILE **open_outputs(FILE **);
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
	FILE **outputs[500];//todo design a data structure to handle outputs file
//	outputs= open_outputs(outputs);
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

FILE ** open_outputs(FILE ** outputs) {
	FILE *list;
	if ((list = fopen(url_output_list, "r")) == NULL) //open school number file.
	{
		printf("error: School number list file cannot be opened.\n");
	}
	char school_number[15];//ues char array as str to store school number and deliver
	while (fgets(school_number, 15, list)) {//get number from list, end with "\n"
		printf("%s", school_number);
		//todo for each student, store it's file pointer into outputs array
		//todo design error dealer
	}
	return outputs;
}