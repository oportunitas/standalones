/*
*	OnlineGDB Archive
*
*	Created			: 10/27/2022, 4:42:13 PM
*	Last Modified	: 10/28/2022, 4:40:58 PM
*/


#include <stdio.h>

long long
    difference = 1;

long long albert(long long n, long long m)
{
    long long
        result = 0;
    
    if (n > 0)
    {
        if (n == 1 || n == 2)
        {
            result = 0;
        }
        else if (n == 3 || n == 4)
        {
            result = 1;
        }
        else
        {
            result = albert(n-1, m) + difference + (m-n);
        }
        
        return result;
    }
}


int main()
{
    long long
        queries;
    
    scanf(" %lli", &queries);
    
    long long
        input[queries];
    
    for (long long i = 0; i < queries; i++)
    {
        scanf(" %lli", &input[i]);
    }
    for (long long i = 0; i < queries; i++)
    {
        printf("%lli\n", albert(input[i], input[i]));
    }

    return 0;
}

