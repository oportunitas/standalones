// 10/27/2022, 1:08:07 PM

#include <stdio.h>
#include <string.h>

long long fibonacci(long long n)
{
    long long
        result = 0;
    
    if (n == 1 || n == 2)
    {
        result = 1;
    }
    else if (n > 0)
    {
        result = fibonacci(n-1) + fibonacci(n-2);
    }
    
    return result;
}

int main()
{
    long long
        queries;
    
    scanf(" %lli", &queries);
    
    long long
        modifier[queries],
        key[queries];
    
    char
        string[queries][1000];
    
    for (long long i = 0; i < queries; i++)
    {
        scanf(" %lli %lli %[^\n]", &modifier[i], &key[i], string[i]);
        
        if (modifier[i] != 0 && modifier[i] != 1)
        {
            printf("Mode is not valid!");
            
            return 0;
        }
        
        key[i] = fibonacci(key[i]);
    }
    
    for (long long i = 0; i < queries; i++)
    {
        long long
            caesarMod = key[i] % 26,
            lenString = strlen(string[i]);
        
        for (long long j = 0; j < lenString; j++)
        {
            long long
                    charInt = (long long)string[i][j];
            
            if (modifier[i] == 1)
            {
                
                if (charInt >= 65 && charInt <= 90)
                {
                    charInt -= caesarMod;
                    
                    if (charInt < 65)
                    {
                        charInt += 26;
                    }
                    else if (charInt > 90)
                    {
                        charInt -= 26;
                    }
                    
                }
                
                else if (charInt >= 97 && charInt <= 122)
                {
                    charInt -= caesarMod;
                    
                    if (charInt < 97)
                    {
                        charInt += 26;
                    }
                    else if (charInt > 122)
                    {
                        charInt -= 26;
                    }
                }
                string[i][j] = (char)charInt;
            }
            
            if (modifier[i] == 0)
            {
                
                if (charInt >= 65 && charInt <= 90)
                {
                    charInt += caesarMod;
                    
                    if (charInt < 65)
                    {
                        charInt += 26;
                    }
                    else if (charInt > 90)
                    {
                        charInt -= 26;
                    }
                    
                }
                
                else if (charInt >= 97 && charInt <= 122)
                {
                    charInt += caesarMod;
                    
                    if (charInt < 97)
                    {
                        charInt += 26;
                    }
                    else if (charInt > 122)
                    {
                        charInt -= 26;
                    }
                }
                string[i][j] = (char)charInt;
            }
        }
        printf("%s\n", string[i]);
    }

    return 0;
}