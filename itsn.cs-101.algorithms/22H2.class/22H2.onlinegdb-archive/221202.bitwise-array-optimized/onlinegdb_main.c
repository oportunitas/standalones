/*
*	OnlineGDB Archive
*
*	Created			: 12/2/2022, 11:19:32 AM
*	Last Modified	: 12/2/2022, 7:06:36 PM
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define lli signed long long int

char number[1000000][17];
lli numberLen[1000000];

int main()
{
    lli inputDigits;
    scanf (" %lli", &inputDigits);
    
    for (lli i = 0; i < inputDigits; i++)
    {
        scanf (" %s", number[i]);
        numberLen[i] = strlen(number[i]);
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
            lli comparator;
            scanf (" %lli", &comparator);
            
            if (operation[0] == 'X')
            {
                for (lli l = 0; l < inputDigits; l++)
                {
                    numberlli ^= comparator;]);
                }
            }
            
            else if (operation[0] == 'A')
            {
                for (lli l = 0; l < inputDigits; l++)
                {
                    numberlli &= comparator;
                }
            }
            else if (operation[0] == 'O')
            {
                for (lli l = 0; l < inputDigits; l++)
                {
                    numberlli |= comparator;
                }
            }
            
        }
        else if (prompt == 2)
        {
            char space = ' ';
            char endl = '\n';
            for (lli i = 0; i < inputDigits; i++)
            {
                fwrite (number[i], 1, numberLen[i], stdout);
                putc (space, stdout);
            }
            putc (endl, stdout);
        }
    }
    return 0;
}






