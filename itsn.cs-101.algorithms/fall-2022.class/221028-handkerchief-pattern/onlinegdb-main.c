/*
*	OnlineGDB Archive
*
*	Created			: 10/27/2022, 10:08:18 AM
*	Last Modified	: 10/28/2022, 4:41:02 PM
*/

/*
    Program Name
        Handkerchief Pattern
    
    Compiled using
        C

    By
        Taib Izzat Samawi
    
    At
        Sepuluh Nopember Institute of Technology
    
    On
        October 27, 2022
    
    As
        handkerchiefPattern.c
*/

#include <stdio.h>

void longInput (long long *a)
{
    scanf("%lli", a);
}

void wingKerchief (long long n, long long programLimit)
{
    for (long long i = 0; i < (programLimit - n); i++)
    {
        printf("  ");
    }
}

void footKerchief (long long n, long long programLimit)
{
    if (n < programLimit)
    {
        printf("%lli ", n);
        footKerchief(n+1, programLimit);
        printf("%lli ", n);
    }
    else if (n == programLimit)
    {
        printf("%lli ", n);
    }
}

void handKerchief (long long n, long long m, long long programLimit)
{
    if (m < programLimit)
    {
        wingKerchief (m, programLimit);
        footKerchief(n, m);
        printf("\n");
        handKerchief(n, m+1, programLimit);
        printf("\n");
        wingKerchief (m, programLimit);
        footKerchief(n, m);
    }
    
    else if (m == programLimit)
    {
        footKerchief(n, m);
    }
    
}

int main()
{
    long long
        n;
    
    longInput(&n);
    
    handKerchief(0, 0, n);

    return 0;
}

