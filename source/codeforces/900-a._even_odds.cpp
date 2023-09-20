/**
 * Codeforces
 * 900
 * A. Even Odds
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 19/09/2023
**/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define lli int64_t
#define fi8 int_fast8_t
#define fit int_fast16_t
#define str string
#define dbl double
#define endl "\n"
#define spc " "
#define tab "\t"
#define vec vector
#define dq deque
#define sp shared_ptr
#define umap unordered_map
#define uset unordered_set
#define ms make_shared
#define INIT_CODE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    INIT_CODE;

    lli numof_num; cin >> numof_num;
    lli index; cin >> index;

    cout << numof_num / 2 << spc << (numof_num / 2) - index << endl;

    if (index > (numof_num / 2)) {
        lli odd_mod = numof_num % 2;
        cout << ((index - (numof_num / 2)) - odd_mod) * 2;
    } else {
        cout << (index * 2) - 1;
    } cout << endl;

    return 0;
}