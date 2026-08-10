/*
*	OnlineGDB Archive
*
*	Created			: 10/28/2022, 3:42:18 PM
*	Last Modified	: 10/28/2022, 4:48:31 PM
*/

/*
    Problem Name
        Mix 'em Up (Acak)
    
    Compiled using
        C
    
    By
        Taib Izzat Samawi
    
    On
        October 28, 2022
*/

#include <stdio.h>

long long
    counter = 0,
    input[2000] = {0},
    output[2000] = {0};

void insertionDeShuffle(long long *itemCount, long long *step)
{
    long long
        middleIndex = (*itemCount - 1) / 2;
    
    if (*step >= 0)
    {
        output[middleIndex + *step] = input[middleIndex + *step - (middleIndex - *step)];
        output[middleIndex - *step] = input[middleIndex + *step - 1 - (middleIndex - *step)];
        
        *step -= 1;
        
        insertionDeShuffle(&*itemCount, &*step);
    }
}

int main()
{
    long long
        itemCount;
    
    scanf(" %lli", &itemCount);
    
    for (long long i = 0; i < itemCount; i++)
    {
        scanf(" %lli", &input[i]);
    }
    
    long long
        middleIndex = (itemCount - 1) / 2;
    
    insertionDeShuffle(&itemCount, &middleIndex);
    
    for (long long i = 0; i < itemCount; i++)
    {
        printf("%lli ", output[i]);
    }

    return 0;
}
