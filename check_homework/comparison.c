//
// Created by 张震宇 on 19/03/2018.
//
#include "comparison.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/***
 * test function, print file for checking inside of the file
 * //todo this function will be deleted.
 * @param file
 */
void printfile(FILE * file) {
	char tmp = fgetc(file);
	while (tmp != EOF) {
		printf("%c", tmp);
		tmp = fgetc(file);
	}
}

FILE *open_standard();
void open_outputs(FILE ** outputs);
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
	FILE **outputs = malloc(500*sizeof(FILE *));//use outputs pointer store output files
	open_outputs(outputs);//store handle in ram,outputs is an array which stores a series of file handles

	//todo compare files
	//for each student's output, compare it with standard output

	//close files
	fclose(standard);
	FILE **tag = outputs;
	while (fclose(*tag)!=EOF) {
		tag++;
	}
	free(outputs);
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
void open_outputs(FILE ** outputs) {
	FILE *list;
	if ((list = fopen(url_output_list, "r")) == NULL) //open school number file.
	{
		printf("error: School number list file cannot be opened.\n");
	}

	FILE **tag = outputs;//use tag to locate data pointer
	char school_number[20];//ues char array as str to store school number and deliver

	while (fgets(school_number, 20, list)) {//get number from list, end with "\n"

		//get url for each student's file
		char string_output[100] = url_outputs;
		strcat(string_output,"/");
		strcat(string_output,strtok(school_number,"\n"));
		strcat(string_output,".txt");

		//open students' output file
		if ((*tag = fopen(string_output, "r")) == NULL) {
			printf("error: open student's outputfile %s failed.\n", string_output);
		}
		tag++;
	}
}