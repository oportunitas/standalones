/**
 * IF ITS Concepts of AI
 * Searching Algorithms
 * 8 Puzzles BFS Solver
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 17/09/2023
**/

#include <bits/stdc++.h>
#include <unordered_map>

#define lli int64_t
#define str string
#define dbl double
#define endl "\n"
#define spc " "
#define tab "\t"
#define vec vector
#define sp shared_ptr
#define ms make_shared
#define spLli shared_ptr<int64_t>
#define msLli make_shared<int64_t>
#define INIT_CODE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

class Node {
public:
    vec<vec<lli>> data;
    sp<Node> via = nullptr;
};

Node bfs(vec<vec<lli>>& start, vec<vec<lli>> finish) {
    map<str, function<vec<vec<lli>>(vec<vec<lli>>)>> move;
    move["up"] = [](vec<vec<lli>> input) {
        vec<vec<lli>> temp = input;
        for (lli i = 0; i < 2; ++i) {
            for (lli j = 0; j < 3; ++j) {
                if (temp[i][j] == 0) {
                    swap(temp[i][j], temp[i + 1][j]);
                    return temp;
                }
            }
        }
        return input;
    };
    move["down"] = [](vec<vec<lli>> input) {
        vec<vec<lli>> temp = input;
        for (lli i = 1; i < 3; ++i) {
            for (lli j = 0; j < 3; ++j) {
                if (temp[i][j] == 0) {
                    swap(temp[i][j], temp[i - 1][j]);
                    return temp;
                }
            }
        }
        return input;
    };
    move["left"] = [](vec<vec<lli>> input) {
        vec<vec<lli>> temp = input;
        for (lli i = 0; i < 3; ++i) {
            for (lli j = 0; j < 2; ++j) {
                if (temp[i][j] == 0) {
                    swap(temp[i][j], temp[i][j + 1]);
                    return temp;
                }
            }
        }
        return input;
    };
    move["right"] = [](vec<vec<lli>> input) {
        vec<vec<lli>> temp = input;
        for (lli i = 0; i < 3; ++i) {
            for (lli j = 1; j < 3; ++j) {
                if (temp[i][j] == 0) {
                    swap(temp[i][j], temp[i][j - 1]);
                    return temp;
                }
            }
        }
        return input;
    };

    deque<Node> leaf_list;
    leaf_list.push_back({ start, nullptr });
    vector<vec<vec<lli>>> visited;

    deque<Node> leaflet_list;
    try_again:
    for (auto it : leaf_list) {
        if (find(visited.begin(), visited.end(), it.data) != visited.end()) {
            continue;
        } visited.push_back(it.data);
        for (lli j = 0; j < 3; ++j) {
            for (lli k = 0; k < 3; ++k) {
                cout << it.data[j][k] << spc;
            } cout << endl;
        } cout << endl;
        if (it.data == finish) {
            return it;
        }
        leaflet_list.push_back({ move["up"](it.data), ms<Node>(it) });
        if (leaflet_list.back().data == it.data) leaflet_list.pop_back();
        //cout << "up" << spc;
        leaflet_list.push_back({ move["right"](it.data), ms<Node>(it) });
        if (leaflet_list.back().data == it.data) leaflet_list.pop_back();
        //cout << "right" << spc;
        leaflet_list.push_back({ move["down"](it.data), ms<Node>(it) });
        if (leaflet_list.back().data == it.data) leaflet_list.pop_back();
        //cout << "down" << spc;
        leaflet_list.push_back({ move["left"](it.data), ms<Node>(it) });
        if (leaflet_list.back().data == it.data) leaflet_list.pop_back();
        //cout << "left" << spc;
        //cout << endl;
    }
    leaf_list = leaflet_list;
    goto try_again;
}

int main() { INIT_CODE;
    vec<vec<lli>> start(3, vec<lli>(3, 0));
    for (lli i = 0; i < start.size(); ++i) {
        for (lli j = 0; j < start[i].size(); ++j) {
            cin >> start[i][j];
        }
    }

    vec<vec<lli>> finish = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    cout << "\r";
    cout.flush();

    Node result = bfs(start, finish);
    cout << "----------" << endl;
    while (result.via->data != result.data) {
        for (lli j = 0; j < 3; ++j) {
            for (lli k = 0; k < 3; ++k) {
                cout << result.data[j][k] << spc;
            } cout << endl;
        } cout << endl;
        result = *result.via;
    }

    return 0;
}