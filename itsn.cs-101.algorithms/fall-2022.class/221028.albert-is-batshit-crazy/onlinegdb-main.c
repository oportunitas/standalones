/*
*	OnlineGDB Archive
*
*	Created			: 10/28/2022, 6:53:50 PM
*	Last Modified	: 10/28/2022, 6:53:51 PM
*/


#include <stdio.h>

long long albert(long long n)
{
    long long
        result;
    
    if (n > 0)
    {
        if (n <= 2)
        {
            result = 0;
        }
        else if (n == 3 || n == 4)
        {
            result = 1;
        }
        else if (n <= 10)
        {
            result = albert(n-1) + albert(n-2) + albert(n-3);
        }
        else
        {
            result = albert(n-1) + albert(n-2);
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
        printf("%lli\n", albert(input[i]));
    }

    return 0;
}
