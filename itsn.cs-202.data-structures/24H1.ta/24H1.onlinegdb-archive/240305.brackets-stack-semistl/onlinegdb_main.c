/*
*	OnlineGDB Archive
*
*	Created			: 2/27/2024, 8:23:35 AM
*	Last Modified	: 3/5/2024, 7:59:20 AM
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define lli signed long long int

typedef struct Stack_Node {
    char data;
    struct Stack_Node* next;
} Stack_Node;

typedef struct Stack {
    Stack_Node* top;
    lli size;
} Stack;

bool isStackEmpty(Stack* This_Stack) {
    return (This_Stack->top == NULL);
}

void pushIntoStack(Stack* This_Stack, char value) {
    Stack_Node* New_Node = (Stack_Node*) malloc(sizeof(Stack_Node));
    if (New_Node) {
        This_Stack->size += 1;
        New_Node->data = value;
        
        if (isStackEmpty(This_Stack)) {
            New_Node->next = NULL;
        } else {
            New_Node->next = This_Stack->top;
        }
        
        This_Stack->top = New_Node;
    }
}

void popFromStack(Stack* This_Stack) {
    if (!isStackEmpty(This_Stack)) {
        Stack_Node* temp = This_Stack->top;
        This_Stack->top = This_Stack->top->next;
        
        free(temp);
        This_Stack->size -= 1;
    }
}

char getStackTop(Stack* This_Stack) {
    if (!isStackEmpty(This_Stack)) {
        return This_Stack->top->data;
    }
    return 0;
}

int main() {
    Stack* Char_Stack = (Stack*) malloc(sizeof(Stack));
    
    char input[2048] = { 0 };
    scanf(" %s", input);
    
    for (lli i = 0; i < strlen(input); ++i) {
        char cur = input[i];
        if ((cur == '[') || (cur == '(') || (cur == '{')) {
            pushIntoStack(Char_Stack, cur);
        } else {
            char char_stack_back = getStackTop(Char_Stack);
            if (
                ((cur == ']') && (char_stack_back == '[')) ||
                ((cur == ')') && (char_stack_back == '(')) ||
                ((cur == '}') && (char_stack_back == '{'))
            ) {
                popFromStack(Char_Stack);
            } else {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    
    if (getStackTop(Char_Stack) == 0) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}
