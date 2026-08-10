/*
*	OnlineGDB Archive
*
*	Created			: 11/10/2022, 5:04:23 PM
*	Last Modified	: 11/29/2022, 2:44:22 AM
*/

#include <stdio.h>
#include <string.h>

typedef struct foodInfo
{
    unsigned long long available;
    char name[2048];
    unsigned long long price;
    unsigned long long stock;
} foodInfo;

int main()
{
    foodInfo
        foodInfo[1000];
    
    char
        charCache[2048];
    
    unsigned long long
        longlongCache;
    
    unsigned long long
        earnings = 0;
    
    for (unsigned long long i = 0; i < 1000; i++)
    {
        foodInfo[i].available = 0;
    }
    
    while (1)
    {
        char
            prompt[2048];
        
        scanf(" %s", prompt);
        
        if (strcmp(prompt, "ADD") == 0)
        {
            unsigned long long
                menuNum;
            
            scanf(" %llu", &menuNum);
            
            if (foodInfo[menuNum].available == 0)
            {
                foodInfo[menuNum].available = 1;
                
                scanf(" %[^\n]", foodInfo[menuNum].name);
                scanf(" %llu", &foodInfo[menuNum].price);
                scanf(" %llu", &foodInfo[menuNum].stock);
                
                printf("Menu added\n");
            }
            else
            {
                scanf(" %[^\n]", charCache);
                scanf(" %llu", &longlongCache);
                scanf(" %llu", &longlongCache);
                printf("Menu is already exist\n");
            }
        }
        else if (strcmp(prompt, "REMOVE") == 0)
        {
            unsigned long long
                menuNum;
            
            scanf(" %llu", &menuNum);
            
            if (foodInfo[menuNum].available == 0)
            {
                printf("Menu does not exist\n");
            }
            else
            {
                foodInfo[menuNum].available = 0;
                printf("Menu removed\n");
            }
        }
        else if (strcmp(prompt, "INFO") == 0)
        {
            unsigned long long
                menuNum;
            
            scanf(" %llu", &menuNum);
            
            if (foodInfo[menuNum].available == 1)
            {
                printf("#%llu %s\nPrice : Rp%llu\nStock : %llux\n\n", menuNum, foodInfo[menuNum].name, foodInfo[menuNum].price, foodInfo[menuNum].stock);
            }
            else
            {
                printf("Menu does not exist\n");
            }
        }
        else if (strcmp(prompt, "ORDER") == 0)
        {
            unsigned long long
                menuNum,
                quantity;
            
            scanf(" %llu %llu", &menuNum, &quantity);
            
            if (foodInfo[menuNum].available == 1)
            {
                if (quantity == 0)
                {
                    printf("So you want to order or what\n");
                }
                else if (foodInfo[menuNum].stock < quantity)
                {
                    printf("Apologize, the stock is not enough\n");
                }
                else
                {
                    printf("Ordered %llux %s for Rp%llu\n", quantity, foodInfo[menuNum].name, (foodInfo[menuNum].price*quantity));
                    earnings += (foodInfo[menuNum].price*quantity);
                    foodInfo[menuNum].stock -= quantity;
                }
            }
            else
            {
                printf("Menu does not exist\n");
            }
        }
        else if (strcmp(prompt, "DISC") == 0)
        {
            unsigned long long
                menuNum,
                discount;
            
            scanf(" %llu %llu", &menuNum, &discount);
            
            if (foodInfo[menuNum].available == 1)
            {
                double discountedPrice = (((double)discount)/100.0)*((double)foodInfo[menuNum].price);
                foodInfo[menuNum].price -= (unsigned long long)discountedPrice;
                
                printf ("Discount added\n");
            }
            else
            {
                printf("Menu does not exist\n");
            }
        }
        else if (strcmp(prompt, "CLOSE") == 0)
        {
            printf("Earnings: Rp%llu\n", earnings);
            printf("Informatics canteen is closing... thanks for the visit!\n");
            break;
        }
        else
        {
            printf("Unknown command\n");
        }
    }
}



