//
// Created by 张震宇 on 19/03/2018.
//
/***
 * compare one student's exe output with standard output
 * line by line
 * in standard output, each line includes a standard output of a line of input
 * output: the number of worry lines
 */

#ifndef CHECK_HOMEWORK_COMPARISON_H_
#define CHECK_HOMEWORK_COMPARISON_H_

#define url_test "../test"
#define url_input "../test/input.txt"
#define url_output_standard "../test/output.txt"
#define url_output_list "../outputs/school_number.txt"
#define url_outputs "../outputs"

/***
 * automatically input .txt files under folder "/outputs"
 * and do comparison then output results saved in folder "rank"
 */
void comparison();

#endif //CHECK_HOMEWORK_COMPARISON_H_
