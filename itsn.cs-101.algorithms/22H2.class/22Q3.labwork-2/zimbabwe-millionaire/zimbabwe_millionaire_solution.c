/**
* ╭╴zimbabwe_millionaire_solution.c
* | GNU C11
* ╰--> solution for ITS IF184101 labwork 2 problem: 'Zimbabwe Millionaire'
* ╭╴created    : circa Q3 2022
* | remastered : 25 Sep 2023
* | last edit  : 5 Jun 2024
* ╰--> @oportunitas
**/


#include <stdio.h>
#define lli signed long long int

int main() {
    lli numof_nums; scanf(" %lli", &numof_nums);
    char num[2048]; scanf(" %s", num);
    char cond; scanf(" %c", &cond);

    char result[2048] = { 0 };
    //lli ratio = (cond == 'J' ? 5 : (cond == 'W' ? 2 : 0));
    lli ratio = 4;

    lli carry = 0;

    if (ratio > 0) {
        for (lli j = numof_nums - 1; j >= 0; --j) {
            lli digit = num[j] - 48;
            lli new_digit = (ratio * digit) + carry;

            result[j] = (new_digit % 10) + 48;
            carry = new_digit / 10;
            printf("added %c with carry of %lli\n", result[j], carry);
        }
    }


    if (cond == 'L') {
        printf("Lose! you're no longer a quadrillionaire now :\"(\n");
    } else {
        if (cond == 'J') {
            printf("Jackpot!\n");
        } else {
            printf("Win!\n");
        } 
        if (carry) printf("%lli", carry);
        printf("%s\n", result);
    }
}