// 3/23/2024, 9:05:45 AM

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define lli signed long long int

/* Struktur ADT StackArray */

typedef struct stackarr_t {
    lli *_element, _topIndex;
    lli _size, _capacity;
} StackArray;

/* Function prototype */

void stackArray_init(StackArray *stack, lli stackSize);
bool stackArray_isEmpty(StackArray *stack);
void stackArray_push(StackArray *stack, lli value);
void stackArray_pop(StackArray *stack);
lli  stackArray_top(StackArray *stack);

/* Function definition below */

void stackArray_init(StackArray *stack, lli stackSize) 
{
    stack->_element  = (lli*) malloc(sizeof(lli) * stackSize);
    stack->_size     = 0;
    stack->_topIndex = -1;
    stack->_capacity = stackSize;
}

bool stackArray_isEmpty(StackArray *stack) {
    return (stack->_topIndex == -1);
}

void stackArray_push(StackArray *stack, lli value)
{
    if (stack->_size + 1 <= stack->_capacity) {
        stack->_element[++stack->_topIndex] = value;
        stack->_size++;
    }
}

void stackArray_pop(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        stack->_topIndex--;
        stack->_size--;
    }
}

lli stackArray_top(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        return stack->_element[stack->_topIndex];
    }
    return 0;
}

int main() {
    lli queries; scanf(" %lli", &queries);
	for (lli i = 0; i < queries; ++i) {
	    lli digits; scanf(" %lli", &digits);
	    getchar();
	    
		StackArray idx; stackArray_init(&idx, (digits * 2));
		
		for (lli j = 0; j < digits; ++j) {
			char temp; scanf("%c", &temp);
			lli num = (lli)temp - 48;
			stackArray_push(&idx, num);
		}
 
		if (digits >= 3) {
		    for (lli j = digits-1; j >= 4; --j) {
		        //printf("%lli", idx._element[j]);
		        if (idx._element[j] == 0) {
		            idx._element[j] = -1;
		            idx._element[j - 1] = (10 * idx._element[j - 2]) + idx._element[j - 1];
		            idx._element[j - 2] = -1;
		        }
		        //printf("%lli\n", idx._element[j]);
		    }
		}
	
	    for (lli j = 0; j < digits; ++j) {
	        char res = idx._element[j] + 96;
	        if (res > 96) {
	            printf("%c", res);
	        }
	    } printf("\n");
	}
	return 0;
}