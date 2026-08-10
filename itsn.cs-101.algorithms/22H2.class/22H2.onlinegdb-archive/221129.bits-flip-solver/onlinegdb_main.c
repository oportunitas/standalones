/*
*	OnlineGDB Archive
*
*	Created			: 11/29/2022, 12:37:38 AM
*	Last Modified	: 11/30/2023, 4:22:37 PM
*/

#include <stdio.h>
#include <math.h>

#define lli signed long long int

lli findStartIndex (lli *binaryArray)
{
    for (lli i = 0; i < 32; i++)
    {
        if (binaryArray[i] == 1)
        {
            return i;
        }
    }
    
    return 31;
}

void flip (lli *number)
{
    if (*number == 0)
    {
        *number = 1;
    }
    else if (*number == 1)
    {
        *number = 0;
    }
}

void assignBinaryValue (lli decimalNumber, lli* binaryArray)
{
    for (lli i = 31; i >= 0; i--)
    {
        if (decimalNumber >= ((lli)pow(2, i)))
        {
            binaryArray[31-i] = 1;
            
            decimalNumber -= ((lli)pow(2, i));
        }
    }
}

lli findFlipCount (lli *initialArray, lli *finalArray, lli startIndex, lli *flipCount)
{
    if (startIndex <= 32)
    {
        printf ("Start Index : %lli\n", startIndex);
        
        lli newStartIndex;
        
        for (lli i = startIndex; i <= 32; i++)
        {
            if ((initialArray[i] == finalArray[i]) && (i <= 32) && (i != startIndex))
            {
                printf ("Initial Array Before: ");
                for (lli i = 0; i < 32; i++)
                {
                    printf ("%lli ", initialArray[i]);
                }
                printf ("\n");
                
                for (lli k = startIndex; k < i; k++)
                {
                    flip (&initialArray[k]);
                }
                
                printf ("Initial Array After : ");
                for (lli i = 0; i < 32; i++)
                {
                    printf ("%lli ", initialArray[i]);
                }
                printf ("\n");
                *flipCount += 1;
                
                newStartIndex = i;
                
                break;
            }
            else if (i == startIndex)
            {
                if (initialArray[i] != finalArray[i])
                {
                    flip (&initialArray[i]);
                    for (lli i = 0; i < 32; i++)
                    {
                        printf ("%lli ", finalArray[i]);
                    }
                    printf ("\n");
                    *flipCount += 1;
                    
                    newStartIndex = 33;
                    
                    break;
                }
            }
        }
        
        findFlipCount (initialArray, finalArray, newStartIndex, flipCount);
    }
}

int main()
{
    
    lli queries;
    scanf (" %lli", &queries);
    
    
    lli initialNumber;
    scanf (" %lli", &initialNumber);
    
    lli initialNumberBinary[32] = {0};
    assignBinaryValue(initialNumber, initialNumberBinary);
    
    for (lli i = 0; i < 32; ++i) {
        printf("%lli", initialNumberBinary[i]);
    } printf("\n"); return 0;
    
    for (lli i = 0; i < 32; i++)
    {
        printf ("%lli ", initialNumberBinary[i]);
    }
    printf ("\n");
    
    for (lli i = 0; i < queries; i++)
    {
        lli swapInverseIndex;
        lli changeTo;
        scanf (" %lli %lli", &swapInverseIndex, &changeTo);
        
        
        if (swapInverseIndex > 0)
        {
            flip (&initialNumberBinary[32 - swapInverseIndex]);
        }
        
        lli changeToBinary[32] = {0};
        assignBinaryValue (changeTo, changeToBinary);
        
        for (lli i = 0; i < 32; i++)
        {
            printf ("%lli ", initialNumberBinary[i]);
        }
        printf ("\n");
        for (lli i = 0; i < 32; i++)
        {
            printf ("%lli ", changeToBinary[i]);
        }
        printf ("\n");
        
        lli initialNumberStartIndex = findStartIndex (initialNumberBinary);
        lli changeToStartIndex = findStartIndex (changeToBinary);
        
        lli startIndex;
        if (initialNumberStartIndex < changeToStartIndex)
        {
            startIndex = initialNumberStartIndex;
        }
        else
        {
            startIndex = changeToStartIndex;
        }
        
        lli flipCount = 0;
        findFlipCount (initialNumberBinary, changeToBinary, startIndex, &flipCount);
        
        printf ("Flip Count : %lli\n", flipCount);
    }

    return 0;
}


