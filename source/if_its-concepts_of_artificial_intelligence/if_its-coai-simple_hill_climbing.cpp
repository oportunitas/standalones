/**
 * IF ITS Concepts of Artificial Intelligence
 * Local Maxima
 * Simple Hill Climbing
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * 18/09/2023
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
#define dq deque
#define sp shared_ptr
#define umap unordered_map
#define ms make_shared
#define INIT_CODE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    umap<char, umap<char, dbl>> adj_map;

    adj_map['E']['C'] = 0.9;
    adj_map['C']['E'] = 0.9;

    adj_map['E']['S'] = 0.6;
    adj_map['S']['E'] = 0.6;

    adj_map['E']['M'] = 0.8;
    adj_map['M']['E'] = 0.8;

    adj_map['E']['K'] = 0.7;
    adj_map['K']['E'] = 0.7;
    

    adj_map['C']['S'] = 1.3;
    adj_map['S']['C'] = 1.3;

    adj_map['C']['M'] = 1.5;
    adj_map['M']['C'] = 1.5;

    adj_map['C']['K'] = 1.3;
    adj_map['K']['C'] = 1.3;


    adj_map['S']['M'] = 0.2;
    adj_map['M']['S'] = 0.2;

    adj_map['S']['K'] = 0.3;
    adj_map['K']['S'] = 0.3;

    adj_map['M']['K'] = 0.2;
    adj_map['K']['M'] = 0.2;

    str init_state = "EMSKC";

    vec<str> checked;
    checked.push_back(init_state);
    dbl total = 0;
    for (lli i = 0; i < init_state.size() - 1; ++i) {
        cout
            << init_state[i] << "->" << init_state[i + 1] << " = "
            << adj_map[init_state[i]][init_state[i + 1]] << endl;
        total += adj_map[init_state[i]][init_state[i + 1]];
    } 
    cout << "(";
    for (lli i = 0; i < init_state.size(); ++i) {
        cout << init_state[i];
        if (i < init_state.size() - 1) cout << "->";
    } cout << ") = " << total << endl << endl;

    for (lli i = 0; i < init_state.size() - 1; ++i) {
        for (lli j = 1; j < init_state.size(); ++j) {
            str temp = init_state;
            swap(temp[i], temp[j]);
            if (find(checked.begin(), checked.end(), temp) != checked.end()) {
                continue;
            }
            dbl current_total = 0;
            for (lli k = 0; k < temp.size() - 1; ++k) {
                cout
                    << temp[k] << "->" << temp[k + 1] << " = "
                    << adj_map[temp[k]][temp[k + 1]] << endl;
                current_total += adj_map[temp[k]][temp[k + 1]];
            } 
            cout << "(";
            for (lli k = 0; k < init_state.size(); ++k) {
                cout << temp[k];
                if (k < temp.size() - 1) cout << "->";
            } cout << ") = " << current_total << endl << endl;
            checked.push_back(temp);
        }
    }

    cout << "code complete" << endl;
    return 0;
}