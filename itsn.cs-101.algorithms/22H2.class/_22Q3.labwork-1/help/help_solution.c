/**
* ╭╴help_solution.c
* | GNU C11
* ╰--> solution for ITS IF184101 labwork 1 problem: 'HELP'
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
    lli date, month, year; scanf(" %lli %lli %lli", &date, &month, &year);

    bool is_leap = true;
    if ((!(year % 100) && (year % 400)) || (year % 4)) {
        is_leap = false;
    }

    if (is_leap) {
        printf("it is a leap year.\n");
        return 0;
    }

    lli nof_day[13] = { 0 };
    for (lli i = 1; i <= 12; ++i) {
        if (i == 2) {
            nof_day[i] = 28;
        } else {
            if (i <= 7) {
                nof_day[i] = (i % 2) ? (31) : (30);
            } else {
                nof_day[i] = (i % 2) ? (30) : (31);
            }
        }
    }

    if ((month <= 0 || month > 12) || (date <= 0 || date > nof_day[month])) {
        printf("invalid date or month!!!\n");
        return 0;
    }

    lli day_num = date;
    for (lli i = 0; i < month; ++i) {
        day_num += nof_day[i];
    }
    printf("Day number: %lli\n", day_num);
    
    return 0;
}