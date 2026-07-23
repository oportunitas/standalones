// 3/30/2024, 12:47:50 AM

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define lli signed long long int

vector<lli> prime;

vector<vector<lli>> g(0, vector<lli>(0));
vector<bool> g_found;

vector<lli> f;
vector<bool> f_found;

int main() {
    // Precompute prime sequence using The Sieve of Eratosthenes
    prime.push_back(2);
    g.push_back({0});
    g.push_back({0});
    g.push_back({1});
    f.push_back(0);
    f.push_back(0);
    f.push_back(1);
    
    for (lli i = 3; i < 20; ++i) {
        g.push_back({1});
        
        //cout << i << endl;
        bool exit_loop = 0;
        for (lli j = 0; j < prime.size(); ++j) {
            //cout << "\t" << prime[j] << endl;
            if (i % prime[j] == 0) {
                exit_loop = 1;
                g[i].push_back(prime[j]);
            }
        }
        f.push_back(0);
        for (lli j = 0; j < prime.size(); ++j) {
            
        }
        
        
        if (exit_loop) {
            goto next_up;
        }
        prime.push_back(i);
        //cout << i << "!!!" << endl << endl;
    next_up:
        void(0);
    }
    
    f.push_back(0);
    f.push_back(0);
    f.push_back(1);
    for (lli i = 3; i < 20; ++i) {
        cout << i << ": ";
        for (lli j = 0; j < g[i].size(); ++j) {
            cout << g[i][j] << ", ";
            f[i] += g[i][j];
        } cout << endl;
    }
    
    for (lli i = 0; i < 20; ++i) {
        cout << i << ": " << f[i] << endl;
    }
    
    vector<lli> res;
    for (lli i = 0; i < 20; ++i) {
        res.push_back(0);
        for (lli j = 0; j <= i; ++j) {
            res[i] += f[j];
        }
        cout << i << ": " << res[i] << endl;
    }
    
    lli n_queries; cin >> n_queries;
    for (lli i = 0; i < n_queries; ++i) {
        lli input; cin >> input;
        cout << res[input] << endl;
    }
    
    // for (lli i = 0; i < prime.size(); ++i) {
    //     cout << prime[i] << ", ";
    // } cout << endl;
    
    // lli n_queries; cin >> n_queries;
    // for (lli i = 0; i < n_queries; ++i) {
    //     lli input; cin >> input;
    //     if (!f_found[input]) {
    //         if (!g_found[input]) {
    //             if (!prime_found[input]) {
    //                 for (lli i = 0; i < )
    //             }
    //         }
    //     }
    //     cout << f[input] << endl;
    // }
}