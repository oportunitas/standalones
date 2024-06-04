/**
 * IF ITS Concepts of Artificial Intelligence
 * Informed Search
 * A Star on 8 Puzzles Algorithm
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 18/09/2023
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

class Frontier {
public:
    fit heur = 0;
    sp<vec<vec<fit>>> front;
    sp<Frontier> via;
};

sp<Frontier> move(
    sp<Frontier> curr_frontier, 
    sp<pair<fit, fit>> zero_loc, 
    char way
) {
    Frontier return_frontier = *(curr_frontier.get());
    return_frontier.via = curr_frontier;

    fit i = zero_loc->first;
    fit j = zero_loc->second;
    if (way == 'R') {
        cout << "swapping " << (*return_frontier.front)[i][j] << " with "
            << (*return_frontier.front)[i][j - 1] << endl;
        swap(
            (*return_frontier.front)[i][j],
            (*return_frontier.front)[i][j - 1]
        );
    }
    if (way == 'L') {
        swap(
            (*return_frontier.front)[i][j],
            (*return_frontier.front)[i][j + 1]
        );
    }
    if (way == 'D') {
        swap(
            (*return_frontier.front)[i][j],
            (*return_frontier.front)[i - 1][j]
        );
    }
    if (way == 'D') {
        swap(
            (*return_frontier.front)[i][j],
            (*return_frontier.front)[i + 1][j]
        );
    }

    for (fit it = 0; it < 3; ++it) {
        for (fit jt = 0; jt < 3; ++jt) {
            cout << (*return_frontier.front)[it][jt] << spc;
        } cout << endl;
    } cout << "---" << endl;
    sp<Frontier> result = ms<Frontier>(return_frontier);
    return result;
}

bool sortFrontierByHeur(sp<Frontier> frontier1, sp<Frontier> frontier2) {
    return frontier1->heur < frontier2->heur;
}

fit getHeur(sp<vec<vec<fit>>> curr, sp<vec<vec<fit>>> finish) {
    fit result = 0;
    vec<pair<fit, fit>> curr_loc(10, {0, 0});
    vec<pair<fit, fit>> finish_loc(10, {9, 0});

    for (fit i = 0; i < 3; ++i) {
        for (fit j = 0; j < 3; ++j) {
            curr_loc[(*curr)[i][j]] = { i, j };
            finish_loc[(*finish)[i][j]] = { i, j };
        }
    }

    for (fit i = 0; i < 10; ++i) {
        result +=
            abs(curr_loc[i].first - finish_loc[i].first) +
            abs(curr_loc[i].second - finish_loc[i].second);
    }

    return result;
}

void aStarFind(sp<vec<vec<fit>>> start, sp<vec<vec<fit>>> finish) {
    dq<sp<Frontier>> frontiers;
    sp<Frontier> start_frontier = ms<Frontier>();
    *start_frontier = { getHeur(start, finish), start, nullptr };
    frontiers.push_back(start_frontier);

    sp<uset<sp<vec<vec<fit>>>>> visited = 
        ms<uset<sp<vec<vec<fit>>>>>();
    visited->reserve(10000007);
    
    while (frontiers.size() > 0) {
        sp<Frontier> pierce = frontiers.front();

        cout << endl << endl;
        for (fit j = 0; j < frontiers.size(); ++j) {
            for (fit k = 0; k < 3; ++k) {
                for (fit l = 0; l < 3; ++l) {
                    cout << (*frontiers[j]->front)[k][l] << spc;
                } cout << endl;
            } cout << endl;
        }

        if (pierce->front == finish) break;

        sp<pair<fit, fit>> zero_loc = ms<pair<fit, fit>>();
        *zero_loc = { -1, -1 };
        for (fit j = 0; j < 3; ++j) {
            for (fit k = 0; k < 3; ++k) {
                if ((*pierce->front)[j][k] == 0) {
                    *zero_loc = { j, k };
                    break;
                }
            }
        }

        if (zero_loc->second > 0) {
            //cout << "test right" << endl;
            sp<Frontier> temp = ms<Frontier>();
            temp = move(pierce, zero_loc, 'R');
            if (!visited->count(temp->front)) {
                frontiers.push_back(temp);
                //cout << "push right" << endl;
            }
        }
        if (zero_loc->second < 2) {
            //cout << "test left" << endl;
            sp<Frontier> temp = ms<Frontier>();
            temp = move(pierce, zero_loc, 'L');
            if (!visited->count(temp->front)) {
                frontiers.push_back(temp);
                //cout << "push left" << endl;
            }
        }
        if (zero_loc->first > 0) {
            //cout << "test down" << endl;
            sp<Frontier> temp = ms<Frontier>();
            temp = move(pierce, zero_loc, 'D');
            if (!visited->count(temp->front)) {
                frontiers.push_back(temp);
                //cout << "push down" << endl;
            }
        }
        if (zero_loc->first < 2) {
            //cout << "test up" << endl;
            sp<Frontier> temp = ms<Frontier>();
            temp = move(pierce, zero_loc, 'U');
            if (!visited->count(temp->front)) {
                frontiers.push_back(temp);
                //cout << "push up" << endl;
            }
        }

        visited->insert(pierce->front);
        frontiers.pop_front();
        sort(frontiers.begin(), frontiers.end(), sortFrontierByHeur);
    }
}

int main() {
    sp<vec<vec<fit>>> start = ms<vec<vec<fit>>>();
    *start = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
    };

    sp<vec<vec<fit>>> finish = ms<vec<vec<fit>>>();
    *finish = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    for (lli i = 0; i < 3; ++i) {
        for (lli j = 0; j < 3; ++j) {
            cin >> (*start)[i][j];
        }
    }

    cout << getHeur(start, finish);

    return 0;
}