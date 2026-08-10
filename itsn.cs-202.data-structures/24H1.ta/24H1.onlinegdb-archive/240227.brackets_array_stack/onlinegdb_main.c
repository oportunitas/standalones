/*
*	OnlineGDB Archive
*
*	Created			: 2/27/2024, 7:46:20 AM
*	Last Modified	: 2/27/2024, 8:00:26 AM
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define lli signed long long int

int main() {
    char char_stack[2048] = { 0 };
    char input[2048] = { 0 };
    scanf(" %s", input);
    
    for (lli i = 0; i < strlen(input); ++i) {
        char cur = input[i];
        if ((cur == '[') || (cur == '(') || (cur == '{')) {
            char_stack[strlen(char_stack)] = cur;
        } else {
            char char_stack_back = char_stack[strlen(char_stack) - 1];
            if (
                ((cur == ']') && (char_stack_back == '[')) ||
                ((cur == ')') && (char_stack_back == '(')) ||
                ((cur == '}') && (char_stack_back == '{'))
            ) {
                char_stack[strlen(char_stack) - 1] = 0;
            } else {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    
    if (strlen(char_stack) > 0) {
        printf("INVALID\n");
    } else {
        printf("VALID\n");
    }
    
    return 0;
}