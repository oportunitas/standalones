/*
Program Name:
    barisan_intip_c_version
    
Created by:
    Taib Izzat Samawi

Using:
    C

On:
    12/02/2023
*/

// 2/12/2023, 11:34:28 PM

#include <stdio.h>
#include <string.h>

#define lli signed long long int
#define llu unsigned long long int
#define llf long double
#define str string

lli duckHeight[10000000];
lli peekedDucks[10000000];

lli sum;

int main()
{
    lli queries;
    scanf(" %lli", &queries);
    
    for (lli i = 1; i <= queries; i++)
    {
        scanf (" %lli", &duckHeight[i]);
        peekedDucks[i] = 1;
        
        for (lli j = i-1; j >= 1; j--)
        {
            if (duckHeight[j] <= duckHeight[i])
            {
                peekedDucks[i] += peekedDucks[j];
            }
            
            j -= (peekedDucks[j]-1);
        }
        
        sum += peekedDucks[i];
    }
    
    printf("%lli\n", sum);
    
    return 0;
}


