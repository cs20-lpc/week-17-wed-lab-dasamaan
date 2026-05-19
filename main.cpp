#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int V = 6;

// Dijkstra's Algorithm
void dijkstra(vector<pair<int, int>> graph[], int source) {

    vector<int> dist(V, INT_MAX);

    // priority queue: (distance, vertex)
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Explore neighbors
        for (auto edge : graph[currentNode]) {

            int neighbor = edge.first;
            int weight = edge.second;

            if (currentDist + weight < dist[neighbor]) {

                dist[neighbor] = currentDist + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print results
    cout << "Shortest distances from node " << source << ":" << endl;

    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    cout << endl;
}

int main() {

    vector<pair<int, int>> graph[V];

    // Add edges: graph[from].push_back({to, weight});

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 9});
    graph[0].push_back({4, 2});

    graph[1].push_back({3, 1});
    graph[1].push_back({2, 2});

    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});

    graph[3].push_back({5, 1});

    graph[4].push_back({2, 3});
    graph[4].push_back({5, 8});

    // Run from node 0
    dijkstra(graph, 0);

    // Run from node 1
    dijkstra(graph, 1);

    return 0;
}