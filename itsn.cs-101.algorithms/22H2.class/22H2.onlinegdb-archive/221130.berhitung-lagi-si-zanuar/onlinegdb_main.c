/*
*	OnlineGDB Archive
*
*	Created			: 11/29/2022, 6:54:02 PM
*	Last Modified	: 11/30/2022, 1:02:38 AM
*/

#include <stdio.h>
#include <math.h>

#define lli signed long long int

lli inverseModulo (lli number, lli modulo)
{
    for (lli i = 1; i < modulo; i++)
    {
        if (((number % modulo) * (i % modulo)) % modulo == 1)
        {
            return i;
        }
    }
}

int main()
{
    lli nodes;
    lli colors;
    scanf(" %lli %lli", &nodes, &colors);
    
    lli combinationCount = 0;
    
    for (lli i = 0; i < nodes; i++)
    {
        lli sum = 1;
        lli cache;
        lli highestPower = i;
        
        for (lli j = nodes; j != 0; j = cache)
        {
            cache = (highestPower % j) % 1000000007;
            highestPower = j;
        }
        
        for (lli j = 0; j < highestPower; j++)
        {
            sum = (sum * colors) % 1000000007;
        }
       
        combinationCount = (combinationCount + sum) % 1000000007;
    }
    
    combinationCount = (combinationCount * inverseModulo (nodes, 1000000007)) % 1000000007;

    printf("%lld",combinationCount);

    return 0;
}