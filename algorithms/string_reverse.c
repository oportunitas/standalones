#include <stdio.h>
#include <string.h>

#define lli signed long long int

void reverseString(char* str) {
    lli str_len = strlen(str);
    for (lli i = 0; i < str_len; ++i) {
        char temp = str[i];
        str[i] = str[str_len - i];
        str[len - i]
    }
}

int main() {
    char str[2048];
    scanf(" %s", str);

    reverseString(str);
}