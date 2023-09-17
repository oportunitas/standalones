/**
 * Codeforces   
 * 800
 * A. Watermelon
 * 
 * Oportunitas (Taib Izzat Samawi)
 *
 * GNU C++ 20 11.2.0 (64bit, winlibs)
 * 17/09/2023
**/

#include <bits/stdc++.h>
#define lli int64_t
#define str string
#define dbl double
#define endl "\n"
#define spc " "
#define tam "\t"
#define INIT_CODE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main() {
    INIT_CODE;
    lli input; cin >> input;
    if (input % 2 == 0 && input > 2) {
        cout << "YES";
    } else cout << "NO";
    cout << endl;

    return 0;
}