/*
*	OnlineGDB Archive
*
*	Created			: 9/22/2023, 2:06:39 PM
*	Last Modified	: 9/22/2023, 2:06:40 PM
*/

#include <stdio.h>
#define lli signed long long int

int main()
{
    lli score; scanf(" %lli", &score);
    printf("%c", (score > 75 && score <= 100) * 'A');
    printf("%c", (score > 60 && score <= 85) * 'B');
    printf("%c", (score > 55 && score <= 65) * 'C');
    printf("%c", (score > 40 && score <= 55) * 'D');
    printf("%c", (score >= 0 && score <= 40) * 'E');
    printf("\n");

    return 0;
}
