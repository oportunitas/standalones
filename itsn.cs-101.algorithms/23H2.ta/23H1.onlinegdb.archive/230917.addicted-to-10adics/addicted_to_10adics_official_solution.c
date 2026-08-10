/**
* ╭╴addicted_to_10adics_official_solution.c
* | GNU C11
* ╰--> official solution for ITS IF234101 labwork 1 problem: 
*      'Addicted to 10-Adics'
* ╭╴created    : 17 Sep 2023
* | last edit  : 5 Jun 2024
* ╰--> @oportunitas
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