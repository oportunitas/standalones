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
    lli dist = LLONG_MAX;
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
    vec<bool> visited(1000006, false);

    while (frontiers.size() > 0) {
        cout
            << "<---------------------------------" 
            << "--------------------------------->"
            << endl
            << "Exhausting vertex {" << (char)(frontiers.front().vertex + 64) << "}"
            << endl << endl;
        if (frontiers.front().vertex == to) {
            cout
                << "But wait! vertex {" << (char)(frontiers.front().vertex + 64) << "}"
                << " is the destination!" << endl;

            dq<Frontier> shortest_path;
            Frontier temp = frontiers.front();
            shortest_path.push_front(temp);
            while (temp.via != nullptr) {
                temp = *temp.via;
                shortest_path.push_front(temp);
            }

            cout << "Shortest path found! the path is as follows:" << endl;
            for (lli k = 0; k < shortest_path.size() - 1; ++k) {
                cout
                    << tab << k + 1
                    << ". Go from vertex {" << (char)(shortest_path[k].vertex + 64)
                    << "} to vertex {" << (char)(shortest_path[k + 1].vertex + 64)
                    << "}," << endl << tab << "   this will take "
                    << shortest_path[k + 1].dist - shortest_path[k].dist
                    << " unit(s) of distance." << endl << endl;
            }
            cout
                << "And there you have it!" << endl
                << "that is the shortest path between "
                << "vertex {" << (char)(shortest_path.front().vertex + 64) << "} and vertex {"
                << (char)(shortest_path.back().vertex + 64) << "}," << endl
                << "which took only " << shortest_path.back().dist
                << " units of distance" << endl << endl << endl;
            break;
        }
        auto edges_pos = find_if(
            graph.begin(),
            graph.end(),
            [&frontiers](pair<pair<lli, lli>, lli>& element) {
                return element.first.first == frontiers.front().vertex;
            }
        );

        while (edges_pos->first.first == frontiers.front().vertex) {
            cout
                << "Checking connection between vertex {"
                << (char)(edges_pos->first.first + 64) << "} and vertex {"
                << (char)(edges_pos->first.second + 64) << "}" << endl;

            if (!visited[edges_pos->first.second]) {
                auto pos = find_if(
                    frontiers.begin(),
                    frontiers.end(),
                    [edges_pos](Frontier& element) {
                        return element.vertex == edges_pos->first.second;
                    }
                );
                if (pos == frontiers.end()) {
                    frontiers.push_back({
                        edges_pos->second + frontiers.front().dist,
                        edges_pos->first.second,
                        ms<Frontier>(frontiers.front())
                        }
                    );

                    cout
                        << tab << "established new connection between vertex {"
                        << (char)(edges_pos->first.first + 64) << "} and vertex {"
                        << (char)(edges_pos->first.second + 64)<< "}" << endl << endl;
                }
                else if (edges_pos->second + frontiers.front().dist < pos->dist) {
                    pos->dist = edges_pos->second + frontiers.front().dist;
                    pos->via = ms<Frontier>(frontiers.front());

                    cout
                        << tab << "changed vertex {" << (char)(edges_pos->first.second + 64)
                        << "} to now connect to vertex {"
                        << (char)(edges_pos->first.first + 64) << endl << endl;
                }
            } else {
                cout
                    << tab 
                    << "The destination vertex has already been exhausted."
                    << endl << tab 
                    << "continuing to next edge..." << endl << endl;
            }
            edges_pos++;
        } 
        visited[frontiers.front().vertex] = true;
        frontiers.pop_front();

        sort(frontiers.begin(), frontiers.end(), sortFrontierByDist);
        cout << "-----------------" << endl;
        cout << "| front | dist  |" << endl;
        for (auto it : frontiers) {
            cout 
                << "|  " << (char)(it.vertex + 64) << tab 
                << "|  " << it.dist << tab 
                << "|  " << endl;
        } cout << "-----------------" << endl << endl;
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
    dijkstraFind(*graph, 1, 8);

    cout
        << "<---------------------------------"
        << "--------------------------------->"
        << endl
        << "This program is built solely by Oportunitas (Taib Izzat Samawi)"
        << endl << "for the purpose of completing a graph theory assignment"
        << endl << "given in ITS Surabaya,"
        << endl << "namely, finding the shortest path between 2 vertices "
        << "in a graph." << endl
        << "<---------------------------------"
        << "--------------------------------->"
        << endl;

    return 0;
}

/*
* input:
    1 2 1
    1 3 3
    1 4 5
    2 7 7
    2 5 4
    3 5 1
    4 6 2
    5 8 6
    5 6 2
    6 7 1
    6 8 4
    6 12 1
    7 9 6
    8 10 1
    9 10 2
    9 13 4
    10 11 1
    10 13 7
    11 12 4
    12 13 3
    0 0 0
*/



