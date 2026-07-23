/*
Program Name:
    barisan_intip
    
Created by:
    Taib Izzat Samawi

Using:
    C++ 20

On:
    08/02/2023
*/

// 2/12/2023, 5:55:59 PM

#include <bits/stdc++.h>

#define lli signed long long int
#define llu unsigned long long int
#define llf long double
#define str string

using namespace std;

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
        
        lli heightFinder = 0;
        for (lli j = i-1; j >= 1; j--)
        {
            if (duckHeight[j] <= duckHeight[i])
            {
                peekedDucks[i] += peekedDucks[j];
            }
            
            j -= (peekedDucks[j]-1);
        }
        
        sum += peekedDucks[i];
        
        /*
        for (lli j = 0; j <= i+1; j++)
        {
            printf ("%lli ", duckHeight[j]);
        }
        printf("\n");
        for (lli j = 0; j <= i+1; j++)
        {
            printf ("%lli ", peekedDucks[j]);
        }
        printf("\n");
        
        printf("this duck can see %lli ducks\n", peekedDucks[i]);\
        
        printf("%lli\n\n", sum);
        */
    }
    
    printf("%lli\n", sum);
    
    return 0;
}
