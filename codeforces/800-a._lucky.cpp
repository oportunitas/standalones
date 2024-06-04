/**
 * Codeforces
 * 800
 * A. Lucky?
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 24/09/2023
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

    lli numof_query; cin >> numof_query;

    for (lli i = 0; i < numof_query; ++i) {
        str input; cin >> input;
        lli head = 0;
        lli tail = 0;

        for (lli i = 0; i < 3; ++i) {
            head += input[i];
            tail += input[5 - i];
        }

        printf((head == tail) ? "YES" : "NO");
        printf("\n");
    }

    return 0;
}