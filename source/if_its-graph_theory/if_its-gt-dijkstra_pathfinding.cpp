/**
 * IF ITS Graph Theory
 * Shortest Paths
 * Dijkstra Algorithm
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
#define dq deque
#define sp shared_ptr
#define ms make_shared
#define INIT_CODE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

class Frontier {
public:
    lli dist = 0;
    lli vertex = -1;
    sp<Frontier> via = nullptr;
};

bool sortFrontierByDist(
    Frontier frontier1,
    Frontier frontier2
) {
    return frontier1.dist < frontier2.dist;
}

bool sortVertexThenWeight(
    pair<pair<lli, lli>, lli> edge1,
    pair<pair<lli, lli>, lli> edge2
) {
    if (edge1.first.first == edge2.first.first) {
        return edge1.second < edge2.second;
    } else {
        return edge1.first.first < edge2.first.first;
    }
}

void dijkstraFind(vec<pair<pair<lli, lli>, lli>> graph, lli from, lli to) {
    dq<Frontier> frontiers;
    frontiers.push_back({ 0, from, nullptr });
    vec<bool> visited(10000007, false);
    while (true) {
        for (auto it : frontiers) {
            cout
                << it.dist << tab
                << it.vertex << endl;
        } cout << endl;

        if (frontiers.front().vertex == to) {
            break;
        }

        auto front_pos = find_if(
            graph.begin(), graph.end(),
            [&frontiers](pair<pair<lli, lli>, lli>& element) {
                return element.first.first == frontiers.front().vertex;
            }
        );

        while (front_pos->first.first == frontiers.front().vertex) {
            if (visited[front_pos->first.second]) {
                if (frontiers)
            }
            if (!visited[front_pos->first.second]) {
                frontiers.push_back({
                    frontiers.front().dist + front_pos->second,
                    front_pos->first.second,
                    ms<Frontier>(frontiers.front())
                });
                visited[front_pos->first.second] = true;
                goto replay;
            }
            front_pos++;
        }
        frontiers.pop_front();

    replay:
        sort(frontiers.begin(), frontiers.end(), sortFrontierByDist);
    }
}

int main() { 
    INIT_CODE;

    sp<vec<pair<pair<lli, lli>, lli>>> graph = 
        ms<vec<pair<pair<lli, lli>, lli>>>();
    //^{ { v1, v2 }, e }

    while (true) {
        lli v1, v2, w;
        cin >> v1 >> v2 >> w;

        if ((v1 == 0) && (v2 == 0) && (w == 0)) {
            break;
        }

        graph->push_back({ { v1, v2 }, w });
        graph->push_back({ { v2, v1 }, w });
    }

    sort(graph->begin(), graph->end(), sortVertexThenWeight);
    for (auto it : *graph) {
        cout
            << it.first.first << tab
            << it.first.second << tab << tab
            << it.second << endl;
    }
    dijkstraFind(*graph, 1, 13);

    return 0;
}