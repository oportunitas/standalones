/**
 * IF ITS Basics of Programming 2023
 * Lab Work 1
 * Addicted to 10-Adics (Official Problemsetter Solution)
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C11
 * 17/09/2023
**/

#include <stdio.h>
#define lli signed long long int

int main() {
    lli tenad_num, reg_num; scanf(" %lli %lli", &tenad_num, &reg_num);

    if (reg_num > 0) {
        lli result = (tenad_num * reg_num) % 100000000000000000;
        if (result == 1) {
            printf(
                "yes, ...%lli in 10-adics is equal to 1/%lli, very nice indeed\n", 
                tenad_num, reg_num
            );
        } else {
            printf(
                "well, turns out that ...%lli in 10-adics is unfortunately not equal to 1/%lli\n", 
                tenad_num, reg_num
            );
        }
    } else if (reg_num < 0) {
        lli result = (tenad_num - reg_num) % 100000000000000000;
        if (result == 0) {
            printf(
                "Look!, ...%lli in 10-adics is equal to %lli!\n", 
                tenad_num, reg_num
            );
        } else {
            printf(
                "Hmm, it seems that ...%lli in 10-adics is sadly not equal to %lli\n", 
                tenad_num, reg_num
            );
        }
    }

    return 0;
}