/**
 * IF ITS Concepts of Artificial Intelligence
 * Local Search
 * 8 Queens Heuristic Search
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 25/09/2023
**/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define lli int64_t
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

class Board {
public:
    Board() {
        tile = vec<vec<char>>(8, vec<char>(8, '0'));
    }
public:
    vec<vec<char>> tile;
};

int main() {
    INIT_CODE;

    uset<vec<vec<char>>> checked_boards;

    return 0;
}