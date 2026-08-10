/*
*	OnlineGDB Archive
*
*	Created			: 12/1/2022, 4:57:45 PM
*	Last Modified	: 12/2/2022, 11:33:25 AM
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define lli signed long long int

lli number[1000000];

void xorSwap (lli comparator, lli index)
{
    //printf ("%lli XOR %lli\n", number[index], comparator);
    
    if (number[index] == comparator)
    {
        number[index] = 0;
    }
    else if (number[index] != comparator)
    {
        lli bigNum;
        lli smallNum;
        if (number[index] > comparator)
        {
            bigNum = number[index];
            smallNum = comparator;
        }
        else if (number[index] < comparator)
        {
            bigNum = comparator;
            smallNum = number[index];
        }
        
        number[index] = 0;
        //^preparation for value assignment
        
        for (lli biggestPower = 31; biggestPower >= 0; biggestPower--)
        {
            lli twoToTheBiggestPower = pow(2, biggestPower);
            if (bigNum >= twoToTheBiggestPower)
            {
                /*
                printf ("Initial Big Num  : %lli\n", bigNum);
                printf ("Initial Small Num: %lli\n", smallNum);
                printf ("Initial Number   : %lli\n", number[index]);
                
                printf ("Big Num Before: %lli\n", bigNum);
                */
                
                if ((smallNum < twoToTheBiggestPower) && (biggestPower > 0))
                {
                    number[index] += twoToTheBiggestPower;
                    bigNum -= twoToTheBiggestPower;
                }
                else if ((smallNum >= twoToTheBiggestPower) && (biggestPower > 0))
                {
                    bigNum -= twoToTheBiggestPower;
                    smallNum -= twoToTheBiggestPower;
                }
                else if ((biggestPower == 0) && (bigNum != smallNum))
                {
                    number[index] += twoToTheBiggestPower;
                    bigNum -= twoToTheBiggestPower;
                }
                else if ((biggestPower == 0) && (bigNum == smallNum))
                {
                    bigNum -= twoToTheBiggestPower;
                    smallNum -= twoToTheBiggestPower;
                }
                
                //printf ("Big Num After: %lli\n", bigNum);
                
                if (bigNum < smallNum)
                {
                    lli smallNumCache = bigNum;
                    
                    bigNum = smallNum;
                    smallNum = smallNumCache;
                }
                
                /*
                printf ("Final Big Num  : %lli\n", bigNum);
                printf ("Final Small Num: %lli\n", smallNum);
                printf ("Final Number   : %lli\n\n", number[index]);
                */
            }
            if ((bigNum == 0) && (smallNum == 0))
            {
                return;
            }
        }
    }
    //printf ("%lli\n", number[index]);
}

void orSwap (lli comparator, lli index)
{
    if (number[index] == comparator)
    {
        number[index] = comparator;
    }
    else if (number[index] != comparator)
    {
        lli bigNum;
        lli smallNum;
        if (number[index] >= comparator)
        {
            bigNum = number[index];
            smallNum = comparator;
        }
        else if (number[index] < comparator)
        {
            bigNum = comparator;
            smallNum = number[index];
        }
        
        number[index] = 0;
        //^preparation for value assignment
        
        for (lli biggestPower = 31; biggestPower >= 0; biggestPower--)
        {
            lli twoToTheBiggestPower = pow(2, biggestPower);
            if (bigNum >= twoToTheBiggestPower)
            {
                /*
                printf ("Initial Big Num  : %lli\n", bigNum);
                printf ("Initial Small Num: %lli\n", smallNum);
                printf ("Initial Number   : %lli\n", number[index]);
                
                printf ("Big Num Before: %lli\n", bigNum);
                */
                
                number[index] += twoToTheBiggestPower;
                bigNum -= twoToTheBiggestPower;
                
                if (smallNum >= twoToTheBiggestPower)
                {
                    smallNum -= twoToTheBiggestPower;
                }
                
                //printf ("Big Num After: %lli\n", bigNum);
                
                if (bigNum < smallNum)
                {
                    lli smallNumCache = bigNum;
                    
                    bigNum = smallNum;
                    smallNum = smallNumCache;
                }
                
                /*
                printf ("Final Big Num  : %lli\n", bigNum);
                printf ("Final Small Num: %lli\n", smallNum);
                printf ("Final Number   : %lli\n\n", number[index]);
                */
            }
            if ((bigNum == 0) && (smallNum == 0))
            {
                return;
            }
        }
    }
}

void andSwap (lli comparator, lli index)
{
    if (number[index] == comparator)
    {
        number[index] = comparator;
    }
    else if (number[index] != comparator)
    {
        lli bigNum;
        lli smallNum;
        if (number[index] >= comparator)
        {
            bigNum = number[index];
            smallNum = comparator;
        }
        else if (number[index] < comparator)
        {
            bigNum = comparator;
            smallNum = number[index];
        }
        
        number[index] = 0;
        //^preparation for value assignment
        
        for (lli biggestPower = 31; biggestPower >= 0; biggestPower--)
        {
            lli twoToTheBiggestPower = pow(2, biggestPower);
            if (bigNum >= twoToTheBiggestPower)
            {
                /*
                printf ("Initial Big Num  : %lli\n", bigNum);
                printf ("Initial Small Num: %lli\n", smallNum);
                printf ("Initial Number   : %lli\n", number[index]);
                
                printf ("Big Num Before: %lli\n", bigNum);
                */
                
                if (smallNum >= twoToTheBiggestPower)
                {
                    number[index] += twoToTheBiggestPower;
                    smallNum -= twoToTheBiggestPower;
                }
                
                bigNum -= twoToTheBiggestPower;
                
                //printf ("Big Num After: %lli\n", bigNum);
                
                if (bigNum < smallNum)
                {
                    lli smallNumCache = bigNum;
                    
                    bigNum = smallNum;
                    smallNum = smallNumCache;
                }
                
                /*
                printf ("Final Big Num  : %lli\n", bigNum);
                printf ("Final Small Num: %lli\n", smallNum);
                printf ("Final Number   : %lli\n\n", number[index]);
                */
            }
            if ((bigNum == 0) && (smallNum == 0))
            {
                return;
            }
        }
    }
}

int main()
{
    lli inputDigits;
    scanf (" %lli", &inputDigits);
    
    for (lli i = 0; i < inputDigits; i++)
    {
        scanf (" %lli", &number[i]);
    }
    
    lli queries;
    scanf (" %lli", &queries);
    
    for (lli i = 0; i < queries; i++)
    {
        lli prompt;
        scanf (" %lli", &prompt);
        
        if (prompt == 1)
        {
            char operation[4];
            scanf (" %s", operation);
            
            if (strcmp(operation, "XOR") == 0)
            {
                lli comparator;
                scanf (" %lli", &comparator);
                
                //printf ("Executed operation XOR with Number: %lli\n", comparator);
                
                for (lli l = 0; l < inputDigits; l++)
                {
                    xorSwap (comparator, l);
                }
            }
            else if (strcmp(operation, "OR") == 0)
            {
                lli comparator;
                scanf (" %lli", &comparator);
                
                for (lli l = 0; l < inputDigits; l++)
                {
                    orSwap (comparator, l);
                }
            }
            else if (strcmp(operation, "AND") == 0)
            {
                lli comparator;
                scanf (" %lli", &comparator);
                
                for (lli l = 0; l < inputDigits; l++)
                {
                    andSwap (comparator, l);
                }
            }
        }
        else if (prompt == 2)
        {
            for (lli k = 0; k < inputDigits; k++)
            {
                printf ("%lli ", number[k]);
            }
            printf ("\n");
        }
    }
    return 0;
}

