/**
 * IF ITS Basics of Programming
 * Lab Work 1
 * Choose The Cards
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C11
 * 17/09/2023
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
    lli deck; scanf(" %lli", &deck);
    lli idx1, idx2; scanf(" %lli %lli", &idx1, &idx2);

    lli card1 = (lli)(deck / (lli)pow(10, idx1 - 1) % 10);
    lli card2 = (lli)(deck / (lli)pow(10, idx2 - 1) % 10);

    bool odd1 = card1 % 2;
    bool odd2 = card2 % 2;

    if (card1 == card2) {
        printf("WIN 100$!");
    } else if (odd1 == odd2) {
        printf("Lose!");
    } else {
        printf("Win 50$!");
    } printf("\n");

    return 0;
}