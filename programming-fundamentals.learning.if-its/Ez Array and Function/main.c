// 10/27/2022, 2:45:49 PM

#include <stdio.h>

int main()
{
    long long
        queries;
    
    scanf(" %lli", &queries);
    
    long long
        input[queries],
        sum = 0;
    
    for (long long i = 0; i < queries; i++)
    {
        scanf(" %lli", &input[i]);
    }
    
    for (long long i = 0; i < queries; i++)
    {
        sum += input[i];
        
        if (input[i] % 26 != 0)
        {
            input[i] %= 26;
        }
        else
        {
            input[i] = 26;
        }
        
        input[i] += 64;
        
        if (input[i] >= 65 && input[i] <= 90)
        {
            if (input[i] < 65)
            {
                input[i] += 26;
            }
            else if (input[i] > 90)
            {
                input[i] -= 26;
            }
        }
        
        printf("%c ", (char)input[i]);
    }
    
    printf("\n%lli", sum);

    return 0;
}
