/**
* ╭╴kenjeran_crossroads_solution.c
* | GNU C11
* ╰--> solution for ITS IF184101 labwork 1 problem: 'Kenjeran Crossroads'
* ╭╴created    : circa Q3 2022
* | remastered : 17 Sep 2023
* | last edit  : 5 Jun 2024
* ╰--> @oportunitas
**/


#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

#define lli int64_t
#define str string
#define dbl double

int main() {
    lli nof_front, nof_back, nof_second;
    scanf(" %lli %lli %lli", &nof_front, &nof_back, &nof_second);

    lli nof_all = nof_front + nof_back + 1;
    lli nof_pass = (nof_second / 85) * 12;
    nof_second %= 85; nof_second -= 25;
    if (nof_second > 0) {
        nof_pass += nof_second / 5;
    }

    if (nof_pass >= nof_all) {
        printf("0");
    } else {
        if (nof_pass > nof_front) {
            printf("YES");
        } else {
            printf("NO");
        } printf("! %lli", nof_all - nof_pass);
    } printf("\n");

    return 0;
}