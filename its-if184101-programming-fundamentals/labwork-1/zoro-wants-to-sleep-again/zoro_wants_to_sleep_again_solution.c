/**
* ╭╴zoro_wants_to_sleep_again_solution.c
* | GNU C11
* ╰--> solution for ITS IF184101 labwork 1 problem: 'Zoro Wants To Sleep Again'
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
    lli curr_hour, curr_min;
    scanf(" %lli %lli", &curr_hour, &curr_min);
    curr_min += curr_hour * 60;

    lli class_hour, class_min;
    scanf(" %lli %lli", &class_hour, &class_min);
    class_min += class_hour * 60;

    lli trip_time, min_sleep;
    scanf(" %lli %lli", &trip_time, &min_sleep);

    if (curr_min + trip_time > class_min) {
        printf("Sleepyhead you already late smh");
    } else if (class_min - (curr_min + trip_time) < min_sleep) {
        printf("Don't sleep again or you'll be late, Zoro");
    } else {
        printf(
            "Zoro can sleep for another %lli minutes :D",
            class_min - (curr_min + trip_time));
    } printf("\n");

    return 0;
}